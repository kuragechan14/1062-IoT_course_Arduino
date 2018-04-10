#include <Servo.h>
Servo myservo;
int potpin =A0;
int val;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val);
  Serial.println(val);
  delay(15);
}

