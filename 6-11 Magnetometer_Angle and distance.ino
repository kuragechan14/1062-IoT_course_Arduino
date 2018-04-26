#include "Wire.h"
#include "I2Cdev.h"
#include "HMC5883L.h"
#define echoPin 7
#define trigPin 8
#define BTN_PIN 2
long a,b,c;
float da,db;
HMC5883L mag;
int16_t mx, my, mz;

int state=0;
int last=0;
int counter=0;

long getdistance()
{
  long duration,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration/58.2;
  return distance;
}
void setup()
{
  Wire.begin();
  Serial.begin(38400);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(BTN_PIN,INPUT);
  Serial.println("Initializing I2C devices...");
  mag.initialize();
  Serial.println("Testing device connections...");
  Serial.println(mag.testConnection() ? "HMC5883L connection successful" :
  "HMC5883L connection failed"); // Conditional Operator
}
void loop() {
  mag.getHeading(&mx, &my, &mz);
  /*
  Serial.print("mag:\t");
  Serial.print(mx); Serial.print("\t");
  Serial.print(my); Serial.print("\t");
  Serial.print(mz); Serial.print("\t");
  */
  float heading = atan2(my, mx);
  if(heading < 0)
  heading += 2 * M_PI;
  float d=heading * 180/M_PI;

  state=digitalRead(BTN_PIN);
  if(state!=last)
  {
    if(state==HIGH)
    {
      counter++;
      if(counter==1)
      {
        Serial.print("====AC====:");
        b=getdistance();
        da=d;
        Serial.print(b);
        Serial.print("\t");
        Serial.println(da);
      }
      else if(counter==2)
      {
        Serial.print("====BC====:");
        a=getdistance();
        db=d;
        Serial.print(a);
        Serial.print("\t");
        Serial.println(db);
        Serial.print("===AB===:");
        float theta=abs(db-da);
        c=sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(theta));
        Serial.print(c);
        Serial.print("\t");
        Serial.println(theta);
      }
      else if(counter==3)
      {
        Serial.println("====Clean====");
        counter=0;
      }
    }
    delay(50);
  }
  last=state;

  delay(100);

}
