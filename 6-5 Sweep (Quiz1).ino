#include <Servo.h>

Servo myservo; 
//int pos = 0; 
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  while(Serial.available() > 0)
  {
    int pos=Serial.parseInt();
    pos=constrain(pos,0,180);
    if(Serial.read()=='\n')
    {
      myservo.write(pos);
      Serial.println(pos);
    }
  }
  /*
  for (pos = 0; pos <= 180; pos++)
  { 
    myservo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos--)
  {
    myservo.write(pos);
    delay(15);
  }
  */
}

