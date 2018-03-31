# Skyfarming
Repository to manage project on automated urban farming

### Requirements:
- dht11 Temprature and Humidity Sensor
- Soil Moisture Sensor
- Water Level sensor
- Relay module (Minimum with 3 port)
- Fan, Water Sprinkler and Water Pump
- Python 3.x
- Flask

### Usage
- Find `sensordata.ino` file and burn into Arduino Uno
- SSH or RDP into your Client to access Raspberry Pi GUI.
- Open the terminal and set your directory to Skyfarming
- run `python3 tryserial.py` to check the output string from `sensordata.ino`
- run `python3 app.py` to get the web interface running

### Arduino connection details and libraries:
dht libraries are included with code stack and connection details are commented in file `sensordata.ino`
