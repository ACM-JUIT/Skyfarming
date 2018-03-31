/*Akhilesh
----
We need three relay switch for sprinkler, pump and fan
sprinkler depends on soil moisture level
pump on water level
and fan on temprature
conditions: 
1. if: Water level is less than any x value, HIGH the corresponding relay pin for water pump.
else: LOW
2. if: Temprture is more than any y value, HIGH the corresponding relay pin for fan.
else: LOW
3. if: Soil Moisture level is less than any value z, HIGH the relay pin for sprinkler.
else: LOW
connections:
dht11 to A0
soil moisture to A1
Water level to A2
fan to 4
*/

#include<dht.h>

#define dht_apin A0
dht DHT;
int soilMoisture=A1, water=A2, soilout;
int pump=3, fan=4, sprinkle=5, waterLevel;
void setup(){
  Serial.begin(9600);
  pinMode(pump,LOW);
  pinMode(fan,LOW);
  delay(2000);
}
void loop(){
  DHT.read11(dht_apin);
  delay(10);
  soilout=analogRead(soilMoisture);
  soilout=map(soilout,550,10,0,100);
  Serial.print("Moisture : ");
  Serial.print(soilout);
  Serial.println("%");
  Serial.print("Current Humidity : ");   
  Serial.print(DHT.humidity);
  Serial.print("%");
  Serial.print(", ");           
  Serial.print("Current Temperature : "); 
  Serial.print(DHT.temperature);
  Serial.println("C");
  waterLevel=analogRead(water) * (100/1023);
  Serial.print("waterlevel : ");
  Serial.print (waterLevel);
  Serial.println ("%"); 
  delay(5000);
  /*
  do all the logic stuff and check other left things
  - relay
  - values in string
  */
  
  
  if (soilout<70)
    pinMode(sprinkle,HIGH);
  else
    pinMode(sprinkle,LOW);
  
  if (waterLevel<90)
    pinMode(pump,HIGH);
  else
    pinMode(pump,LOW);

  if (DHT.temperature > 20)
    pinMode(fan,HIGH);
  else
    pinMode(fan,LOW);
    

  
}









