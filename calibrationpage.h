#ifndef CALIBRATIONPAGE_H
#define CALIBRATIONPAGE_H

const char calibrationpage[] PROGMEM = R"=====(
  <div class="main">
    <h2>CALIBRATION MENU</h2>
    <div class="center">
        <img src="https://gblobscdn.gitbook.com/assets%2F-MPQ2vWEZUH7ol6XE55o%2F-MShb_2_2fVamKuokK2A%2F-MShe8Oogbo5SCF0YULN%2FIndex.png?alt=media&token=ca8cc841-460a-4f10-af02-aa9d73093a0e" alt="Bittle joint overview" width="400">
    </div>
    <h2>Offset amount</h2>
    <div class="radio">
        <label for="offsetAmountSetter" id="offsetAmount" style="color: black;">1</label>
        <input type="range" style="width: 30%; left: 0px;" min="1" max="10" step="1" value="1" name="offsetAmount" onchange="setOffset(this.value)"></radiorange>
    </div>
    <h2>Head (0)</h2>
    <div class="card" style="width: 70%">
        <button style="width: 50%" onclick="increase(0)">Left</button>
        <button style="width: 50%" onclick="decrease(0)">Right</button>
    </div>
    <h2>Front left leg</h2>
    <div class="card" style="width: 70%">
        <button style="width: 50%" onclick="increase(8)">(8) Upper joint +</button>
        <button style="width: 50%" onclick="decrease(8)">(8) Upper joint -</button>
        <button style="width: 50%" onclick="increase(12)">(12) Lower joint +</button>
        <button style="width: 50%" onclick="decrease(12)">(12) Lower joint -</button>
    </div>
    <h2>Front right leg</h2>
    <div class="card" style="width: 70%">
        <button style="width: 50%" onclick="increase(9)">(9) Upper joint +</button>
        <button style="width: 50%" onclick="decrease(9)">(9) Upper joint -</button>
        <button style="width: 50%" onclick="increase(13)">(13) Lower joint +</button>
        <button style="width: 50%" onclick="decrease(13)">(13) Lower joint -</button>
    </div>
    <h2>Back left leg</h2>
    <div class="card" style="width: 70%">
        <button style="width: 50%" onclick="increase(11)">(11) Upper joint +</button>
        <button style="width: 50%" onclick="decrease(11)">(11) Upper joint -</button>
        <button style="width: 50%" onclick="increase(15)">(15) Lower joint +</button>
        <button style="width: 50%" onclick="decrease(15)">(15) Lower joint -</button>
    </div>
    <h2>Front right leg</h2>
    <div class="card" style="width: 70%">
        <button style="width: 50%" onclick="increase(10)">(10) Upper joint +</button>
        <button style="width: 50%" onclick="decrease(10)">(10) Upper joint -</button>
        <button style="width: 50%" onclick="increase(14)">(14) Lower joint +</button>
        <button style="width: 50%" onclick="decrease(14)">(14) Lower joint -</button>
    </div>
    <br>
    <div class="card" style="width: 70%">
        <button class="redBG" style="width: 100%" onclick="sendCmd('s')">Save offsets</button>
    </div>
    <div class="card" style="width: 70%">
        <button class="redBG" style="width: 100%" onclick="sendCmd('cycle')">Check with a cycle</button>
    </div>
    <div class="card" style="width: 70%">
        <div class="console" id="serialOutput">Serial output</div>
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

        function setOffset(value) {
            document.getElementById('offsetAmount').innerHTML = value;
        }

        function increase(joint) {
            sendCmd(`c${joint} ${1000 + parseInt(document.getElementById('offsetAmountSetter').value)}`);
        }

        function decrease(joint) {
            sendCmd(`c${joint} ${-1000 - parseInt(document.getElementById('offsetAmountSetter').value)}`);
        }
    </script>
</div>
)=====";

#endif