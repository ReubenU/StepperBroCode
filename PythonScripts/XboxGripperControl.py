import serial
from XInput import *
import time

timeout = 5/1000

usr_port = input("Enter port address: ")

arduino = serial.Serial(port=usr_port, baudrate=115200, timeout=timeout)
print(arduino.baudrate)
time.sleep(1)

# Make an input value that ranges from "fromMin" to "fromMax"
# map directly to a new range that goes from "toMin" to "toMax".
def mapInputToRange(inputVal, fromMin, fromMax, toMin, toMax):
    return (inputVal-fromMin)/(fromMax-fromMin)*(toMax-toMin)+toMin

# Write and read data with a time delay to the connected Arduino
# Serial port.
def write_read(data):
    arduino.write(bytes('%i'%(data), 'utf-8'))

    time.sleep(timeout)
    result = arduino.readline()
    return result

# The main loop.
while True:
    triggers = get_trigger_values(get_state(0))

    mappedTriggerVals = int(round(mapInputToRange(triggers[1]-triggers[0], -1.0, 1.0, -100, 100)))

    print(write_read(mappedTriggerVals))
