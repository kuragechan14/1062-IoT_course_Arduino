#include "Wire.h"
#include "I2Cdev.h"
#include "BMP085.h"
#define BTN_PIN 2
#define LED_PIN1 9
#define LED_PIN2 10
#define LED_PIN3 13
BMP085 barometer;

float temp;
float pres;
float seaLevelP=101325;
float altitude;
int32_t lastMicros;
bool blinkState=false;
int F=0;
float seaf1,seaf2,seaf3,floordiff;
int state=0;
int last=0;
int counter=0;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Initializing I2C devices...");
  barometer.initialize();
  Serial.println(barometer.testConnection()?"BMP085 connection succesful":"BMP085 connection failed");
  pinMode(LED_PIN1,OUTPUT);
  pinMode(LED_PIN2,OUTPUT);
  pinMode(LED_PIN3,OUTPUT);
  pinMode(BTN_PIN,INPUT);
}

void loop()
{
  
  barometer.setControl(BMP085_MODE_TEMPERATURE);
  lastMicros=micros();
  while(micros()-lastMicros<barometer.getMeasureDelayMicroseconds());
  temp=barometer.getTemperatureC();

  barometer.setControl(BMP085_MODE_PRESSURE_3);
  while(micros()-lastMicros<barometer.getMeasureDelayMicroseconds());
  pres=barometer.getPressure();

  altitude=barometer.getAltitude(pres,seaLevelP);

  state=digitalRead(BTN_PIN);
  if(state!=last)
  {
    if(state==HIGH)
    {
      counter++;
      if(counter==1)
      {
        seaf1=altitude;
        Serial.print("====1F====:");
        Serial.println(seaf1);
      }
      else if(counter==2)
      {
        seaf2=altitude;
        floordiff=seaf2-seaf1;
        Serial.print("====2F====:");
        Serial.println(seaf2);
        Serial.print("====Diff====:");
        Serial.println(floordiff);
      }
    }
    delay(50);
  }
  last=state;
  if(counter==0)
  {
    Serial.print("T/P/A\t");
    Serial.print(temp);
    Serial.print("\t");
    Serial.print(pres);
    Serial.print("\t");
    Serial.println(altitude);
  }
  else if (counter==3)
  {
    F=int((altitude-seaf1)/floordiff)+1;
    Serial.print("====NOW====:");
    Serial.print(F);
    Serial.print("\t");
    Serial.println(altitude);
    if(F==1)
    {
      digitalWrite(LED_PIN1,HIGH);
      digitalWrite(LED_PIN2,LOW);
      digitalWrite(LED_PIN3,LOW);
    }
    else if(F==2)
    {
      digitalWrite(LED_PIN2,HIGH);
      digitalWrite(LED_PIN1,LOW);
      digitalWrite(LED_PIN3,LOW);
    }
    else if(F==3)
    {
      digitalWrite(LED_PIN3,HIGH);
      digitalWrite(LED_PIN1,LOW);
      digitalWrite(LED_PIN2,LOW);
    }
  }
  
  delay(100);
}
