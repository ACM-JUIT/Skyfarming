import serial
import time
ser=serial.Serial("dev/ttyACM0",9600)                         #in quotes edit the port according to the serial/usb port used for communication with arduino
i=0
while i<200:
	print=ser.readline()
	s=ser.readline()                                      #this commmand reads the data sent by arduino through serial port
	temp,soilmoist,humidity,waterlevel=s.split(",")       #used this command to convert the incoming data into a csv value file
	i=i+1
	
