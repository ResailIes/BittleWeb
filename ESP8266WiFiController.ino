#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>       
#include <ArduinoJson.h>
#include <Dictionary.h>

#include "commons.h"
#include "actionpage.h"
#include "calibrationpage.h"
#include "mainpage.h"

#include "actions.h"

#define BUILTIN_LED 2

ESP8266WebServer server(80);

Dictionary *actions = new Dictionary(30);

String PROGMEM renderHtml(String body, String title) {
  String page;
  page += FPSTR(head);
  page.replace(FPSTR("%TITLE%"), title);
  page += body;
  page += FPSTR(foot);
  return page;
}

void handleMainPage() {
  server.send(200, "text/html", renderHtml(FPSTR(mainpage), "Home"));
}

void handleActionPage() {
  if (server.hasArg("cmd")) {
    Serial.print(server.arg("cmd"));
  }
  server.send(200, "text/html", renderHtml(FPSTR(actionpage), "Actions"));
}

String sendCmd() {
  String argname = server.arg("name");

  if (actions->search(argname).isEmpty())
  {
      Serial.print(argname);
  }
  else
  {
      Serial.print((*actions)[argname]);
  }

  // read result
  String ret = Serial.readString();
  return ret;
}

void handleCommand() {
  StaticJsonDocument<30> data;
  DeserializationError error = deserializeJson(data, server.arg("plain"));
  
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  const String cmd = data["cmd"];

  if (cmd == "cycle") {
    Serial.print("s");
    delay(500);
    Serial.print("ksit");
    delay(2000);
    Serial.print("kbalance");
    delay(2000);
    Serial.print("c");
  }
  
  Serial.print(cmd);
  server.send(200);
}

void handleCalibrationPage() {
  server.send(200, "text/html", renderHtml(FPSTR(calibrationpage), "Calibration"));
  Serial.print("c");
}

void handleSerialOutput() {
  if (Serial.available() > 0) {
    String output;
    output += Serial.read();
    server.send(200, "text/plain", output);
  } else {
    server.send(204);
  }
}

void setup(void) {

  // Serial and GPIO LED
  Serial.begin(115200);
  pinMode(BUILTIN_LED, OUTPUT);

  // load json file
  actions->jload(dict_json);

  // WiFiManager
  WiFiManager wifiManager;

  // Start WiFi manager, default gateway IP is 192.168.4.1
  wifiManager.autoConnect("Bittle-AP");
  digitalWrite(BUILTIN_LED, HIGH);      // While connected, LED lights

  // Print the IP get from DHCP Server of your Router
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // HTTP server started with handlers
  server.on("/", handleMainPage);
  server.on("/commander", handleCommand);
  server.on("/actions", handleActionPage);
  server.on("/calibrationpage", handleCalibrationPage);
  server.on("/getOutput", handleSerialOutput);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  // handle clients
  server.handleClient();
}