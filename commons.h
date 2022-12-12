#ifndef COMMONS_H
#define COMMONS_H

const char head[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
  <title>OpenCat Web Controller</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, minimum-scale=0.5, maximum-scale=0.8, user-scalable=yes"/>
  <style>

body {
  font-family: Arial, Helvetica, sans-serif;
  margin: 0;
}

.header {
  padding: 80px;
  text-align: center;
  background: #121212;
  color: white;
}

h2 {
  text-align: center;
  justify-content: center;
  align-items: center;
}

h1 {
  font-size: 40px;
  text-align: center;
  justify-content: center;
  align-items: center
}

.wide {
  width: 80%;
}

button, input[type="submit"], input[type="text"] {
  border-radius: 0;
  background: #333;
  border: 1px solid #ddd;
  color: white;
  text-align: center;
  text-decoration: none;
  font-size: 1em;
  height: 75px;
  cursor: pointer;
  width: 32%;
  outline: none;
  padding: 0;
  margin: 0;
}
 
form {
  display: flex;
  flex-wrap: wrap;
  flex-direction: column;
}

container {
  position: relative;
    top: 5;
    left: 5;
    right: 5;
    bottom: 5;
    width: 50%;
   
    justify-content: center;
    align-items: center;
    padding: 0px;
    background: #333;
}

input {
  position: relative;
  left: -9999px;
}

input:checked + span {
  background-color: #bbb;
}

input:checked + span:before {
  box-shadow: inset 0 0 0 0.3em #000
}
    
span {
  display: flex;
  align-items: center;
  padding: 0.375em 0.75em 0.375em 0.375em;
  border-radius: 99em;
  transition: 0.25s ease;
  position: relative;
}

span:hover {
  background-color: #ddd;
}

span:before {
  display: flex;
  flex-shrink: 0;
  content: "";
  background: #ddd;
  width: 1em;
  height: 1em;
  border-radius: 50%;
  margin-right: 0.4em;
  transition: 0.25s ease;
  box-shadow: inset 0 0 0 0.125em #333;
  box-sizing: border-box;
}

.radio {
  display: flex;
  height: 50px;
  align-content: center;
  justify-content: center;
  align-items: center;
  justify-items: center;
  flex: 1;
}

.redBG {
  background: red;
}

label {
  font-size: 1.2em;
  color: white;
  text-transform: uppercase;
  margin: 5px, auto, 5px;
  cursor: pointer;
}

.btn-group button {
  border-radius: 25px;
  background: #333; /* Green background */
  border: 1px solid green; /* Green border */
  color: white; /* White text */
  padding: 10px 24px; /* Some padding */
  cursor: pointer; /* Pointer/hand icon */
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 20px;
  height: 50px;
  margin: 5px 5px 10px;
}

.btn-group button:hover {
  background: #3e8e41;
}

.btn button {
  border-radius: 25px;
  background: #2196F3;
  border: 1px #2196F3;
  color: white;
  text-align: center;
  font-size: 25px;
  display: inline-block;
  width: 45%;
  height: 60px;
}

.btn-stop button {
  border-radius: 25px;
  background: red;
  border: 1px red;
  color: white;
  text-align: center;
  font-size: 25px;
  display: inline-block;
  width: 45%;
  height: 60px;
}

.center {
  text-align: center;
}

.navbar {
  overflow: hidden;
  background-color: #333;
}

.navbar a {
  float: left;
  display: block;
  color: white;
  text-align: center;
  padding: 14px 20px;
  text-decoration: none;
}

.navbar a.right {
  float: right;
}

.navbar a:hover {
  background-color: #ddd;
  color: black;
}

.card {
  display: flex;
  flex-wrap: wrap;
  width: 50%;
  margin: 0px auto 2px;
  background: #ddd;
  justify-content: center;
  align-items: center;
  min-height: 50px;
}

.row {  
  display: -ms-flexbox; /* IE10 */
  display: flex;
  -ms-flex-wrap: wrap; /* IE10 */
  flex-wrap: wrap;
}

.side {
  -ms-flex: 30%; /* IE10 */
  flex: 30%;
  background: #f1f1f1;
  padding: 20px;
}

.main {   
  -ms-flex: 70%; /* IE10 */
  flex: 70%;
  background: #ddd;
  padding: 20px;

}

.linkAdvert {
  font-size: 1.2em;
  font-weight: bold;
}

.link {
  display: block;
  margin: 25px;
  width: 100%;
}

.footer {
  width: 100%;
  background: #bbb;
  border-top: 2px solid #333;
  text-align: center;
  position: relative;
  bottom: 0;
  height: 45px;
  font-size: 15px;
  padding: 10px;
}

/* Responsive layout - when the screen is less than 700px wide, make the two columns stack on top of each other instead of next to each other */
@media screen and (max-width: 700px) {
  .row {   
    flex-direction: row;
  }
}

/* Responsive layout - when the screen is less than 400px wide, make the navigation links stack on top of each other instead of next to each other */
@media screen and (max-width: 400px) {
  .navbar a {
    float: none;
    width: 100%;
  }
}

</style>

<script type="text/javascript">
        document.addEventListener('DOMContentLoaded', function () {
            let title = "%TITLE%";
            document.getElementById(title).classList.add('active')
        });
        function sendCmd(cmd) {
            fetch('/commander', {
                method: "POST",
                body: JSON.stringify({
                    cmd: cmd
                })
            }).then(result => {
               console.log(`Sent "${cmd}" to Bittle`);
            }).catch(() => {
                console.warn(`Failed sending "${cmd}" to Bittle`);
            });
        }
    </script>
</head>

<body>
<div class="header">
  <h1>Bittle Web API</h1>
  <p>Web API Wrapper Using Raspberry Pi Host.</p>
</div>

<div class="navbar">
  <a id="Home" href="/">Home</a>
  <a id="Calibrate" href="/calibrationpage">Calibrate</a>
  <a id= "Actions" href="/actions">Commands</a>
  <a class="right">IP: 192.168.4.1 </a>
</div>

)=====";

const char foot[] PROGMEM = R"=====(
<div class="footer">
    <p><a href="www.petoi.com" target="_blank">www.petoi.com</a> - Web interface by Dylan </p>
</div>
</body>
</html>
)=====";
#endif