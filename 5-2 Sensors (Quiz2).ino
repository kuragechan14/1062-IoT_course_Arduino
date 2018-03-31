#include<dht.h>
#define dht_dpin A0

#define echoPin 7
#define trigPin 8
#define LEDPin 13
float T,V;
long duration,distance;

dht DHT;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(LEDPin,OUTPUT);
  delay(300);
  Serial.println("H and T");
  delay(700);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW); 
  DHT.read11(dht_dpin);
  T=DHT.temperature;
  Serial.print("T=");
  Serial.print(T);

  duration=pulseIn(echoPin,HIGH);
  V=1000000/((331.3+0.606*T)*100); //m/s to 1cm per microsecond
  
  Serial.print(" V=");
  Serial.print(V);
  distance=duration/(V*2);
  Serial.print("  D=");

  delay(1000);

}
