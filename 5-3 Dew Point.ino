#include<dht.h>
#define dht_dpin A0
float T,H,DP;
dht DHT;

void setup() {
  Serial.begin(9600);
  delay(300);
  Serial.println("H and T");
  delay(700);
}

void loop() {
  DHT.read11(dht_dpin);
  T=DHT.temperature;
  H=DHT.humidity;
  Serial.print("T=");
  Serial.print(T);
  Serial.print(" H=");
  Serial.print(H);
  DP=T-(100-H)/5;
  Serial.print(" DP=");
  Serial.println(DP);
  
  delay(1000);
}
