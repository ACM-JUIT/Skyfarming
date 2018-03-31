import serial
import time
ser=serial.Serial("dev/ttyACM0",9600)
i=0
while i<200:
	print=ser.readline()
	s=ser.readline()
	temp,soilmoist,humidity,waterlevel=s.split(",")
	i=i+1
	