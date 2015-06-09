# Copyright Oliver D. Rodriguez and others from IBM.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import serial
import ibmiotf.device
import json


class iotClient(object):
  
  def __init__(self, options):
    self.client = ibmiotf.device.Client(options)

  def connect(self):
    try:
      self.client.connect()
    except ibmiotf.ConnectionException as e:
      self.client.disconnect()
      print(e)  

  def send(self, jsonData):
    print("Sending JSON Payload")
    self.client.publishEvent("status", jsonData)
    print(json.dumps(jsonData))



config = {
    "org": "eplnqo",
    "type": "arduino",
    "id": "abc123",
    "auth-method": "token",
    "auth-token": "C4fEFTTFJBzDP-w8Qi"
}

client = iotClient(config)
client.connect()

ser = serial.Serial(
    port='COM4',\
    baudrate=9600,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
        timeout=1)

def sendTemp(temp):
    client.send({"temp":temp})
    print("temp: "+str(temp))

#def sendVoltage(volt):
    #print("volt: "+str(volt))

while 1:

    line = ser.readline()
    if len(line) > 0:
        parts = line.decode("utf-8").split(':', 1)

        if parts[0] == 'temp':
            data = float(parts[1])
            sendTemp(data)
        #elif parts[0] == 'volt':
            #sendVoltage(data)
    

ser.close()
