#ifndef ACTIONPAGE_H
#define ACTIONPAGE_H

const char actionpage[] PROGMEM = R"=====(
<div class="row">
  <div class="side">
    <h2>Communication</h2>
        <h4 for="interval" >Interval: </h4>
        <input id="interval" style="height: 40px; width: 70%; left: 0px;" name="name" type="text" left="0" placeholder="Input Command">
        <button style="width: 29%; height: 40px" onclick="sendInputCmd()">Send</button>
        <h4 for="duration">Duration: </h4>
        <input id="interval" style="height: 40px; width: 70%; left: 0px;" name="name" type="text" left="0" placeholder="Input Command">
        <button style="width: 29%; height: 40px" onclick="sendInputCmd()">Send</button>
      <br>
    <h2>Movement Types</h2>
    <div class="container">
      <form>
          <label style="color: black")>
          	  <input type="radio" id ="walk" name="movementType" value="wk" checked/>
              <span>WALK</span>
          </label>
          <label style="color: black")>
              <input type="radio" id="run" name="movementType" value="rn"/>
              <span>RUN</span>
          </label>
          <label style="color: black")>
              <input type="radio" id="trot" name="movementType" value="tr"/>
              <span>TROT</span>
          </label>
          <label style="color: black")>
              <input type="radio" id="crawl" name="movementType" value="cr"/>
              <span>CRAWL</span>
          </label>
      </form>
    </div>
    <h2>Custom Command</h2>
    <input id="input" style="height: 40px; width: 70%; left: 0px;" name="name" type="text" left="0" placeholder="Input Command">
    <button  style="width: 29%; height: 40px" onclick="sendInputCmd()">Send</button>
  </div>
  <div class="main">
    <h2>MOVEMENTS</h2>
    <div class="card">
        <button onclick="movement('F')"  style="width: 100%;">Forward</button>
        <button onclick="movement('L')" style="width: 50%;">Forward Left</button>
        <button onclick="movement('R')" style="width: 50%;">Forward Right</button>
        <button onclick="sendCmd('kbkL')" style="width: 50%;">Back Left</button>
        <button onclick="sendCmd('kbkR')" style="width: 50%;">Back Right</button>
        <button onclick="sendCmd('kbk')" style="width: 100%;">Back</button>
    </div>
    <h2>MODES</h2>
	<div class="cardwide">
        <button onclick="sendCmd('g')"  style="width: 32%">Gyro On/Off</button>
        <button onclick="sendCmd('c')"  style="width: 32%;">Calibration</button>
        <button onclick="sendCmd('kbalance')"  style="width: 32%;">Balanced</button>
    </div>
    <h2>ACTIONS</h2>
    <div class="cardwide">
        <button onclick="sendCmd('ksit')">Sit</button>
        <button onclick="sendCmd('kck')">Check</button>
        <button onclick="sendCmd('kbuttUp')">Buttup</button>
        <button onclick="sendCmd('khi')">Hello</button>
        <button onclick="sendCmd('kstr')">Stretch</button>
        <button onclick="sendCmd('kpee')">Pee</button>
        <button onclick="sendCmd('kpu')">Push ups</button>
        <button onclick="sendCmd('kvt')">Stepping</button>
        <button onclick="sendCmd('lu')">Look up</button>
        <button onclick="sendCmd('kbf')">Backflip</button>
        <button onclick="sendCmd('kbdF')">Jumps</button>
        <button onclick="sendCmd('krc')">Recover</button>
        <button class="redBG" style="width: 97%" onclick="sendCmd('d')">STOP</button>
    </div>
  </div>
  <script type="text/javascript">
        document.addEventListener('DOMContentLoaded', function() {
            setInterval(function() {
                fetch('/getOutput', {
                    method: "POST"
                }).then(response => {
                    return response.text();
                }).then(text => {
                    if (!text) {
                      return;
                    }
                    document.getElementById('serialOutput').innerHTML = `${text}<br/>${document.getElementById('serialOutput').innerHTML}`;
                });
            }, 500);
        });
        function movement(direction) {
            const movementType = document.querySelector('input[name="movementType"]:checked').value;
            sendCmd(`k${movementType}${direction}`);
        }
        function sendInputCmd() {
            const cmd = document.getElementById('input').value;
            sendCmd(cmd);
        }

        function sendCommunication() {
          const cmd = document.getElementById('input').value;
          sendCmd()
        }
    </script>
</div>
)=====";

#endif