#include<dht.h>
#define dht_dpin A0
float T,H,AT,e;
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
  e=H/100*6.105*exp((17.27*T)/(237.7+T));
  AT=1.04*T+0.2*e-0.65*2.7-2.7;
  Serial.print(" AT=");
  Serial.println(AT);
  
  delay(1000);
}
