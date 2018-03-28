/*Akhilesh
----
We need three relay switch for sprinkler, pump and fan
sprinkler depends on soil moisture level
pump on water level
and fan on temprature
*/



#define dht_apin A0
dht DHT;
int soilmoisture=A1, water=A2, soilout;
int pump=3, fan=4, sprinkle=5;
void setup(){
  Serial.begin(9600);
  pinMode(pump,LOW);
  pinMode(fan,LOW);
  delay(2000);
}
void loop(){
  DHT.read11(dht_apin);
  soilout=analogRead(soilmoisture);
  soilout=map(soilout,550,10,0,100);
  Serial.print("Moisture : ");
  Serial.print(soilout);
  Serial.println("%");
  Serial.print("Current Humidity=");
  Serial.print(DHT.humidity);
  Serial.print("%\t");
  Serial.print("Current Temperature");
  Serial.print(DHT.temperature);
  Serial.println("C");
  waterlevel=analogRead(water);
  Serial.println(waterlevel);
  delay(5000);
  if (soilout<100){
  pinMode(sprinkle,HIGH);
  else{
  pinMode(sprinkle,LOW);
  }
  if (waterlevel<100){
  pinMode(pump,HIGH);
  else{
  pinMode(pump,LOW);
}
