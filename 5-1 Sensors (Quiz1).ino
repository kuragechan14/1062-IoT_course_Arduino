#define echoPin 7
#define trigPin 8
#define LEDPin 13
#define beep 65
int maximumRange=200;
int minimumRange=0;
int safe=100;
int careful=30;
long duration,distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(LEDPin,OUTPUT);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH);
  distance=duration/58.2;
  Serial.print("D=");
  Serial.print(distance);
  if (distance > safe)
  {
    Serial.println("\tSafe!");
  }
  else if (distance >= careful && distance <= safe)
  {
    Serial.println("\tBe careful!");
    tone(9,beep);
    delay(400);
    noTone(9);
    //delay(100);
  }
  else
  {
    Serial.println("\tDangerous!");
    tone(9,beep);
    delay(200);
    noTone(9);
    //delay(50);
  }
  delay(50);

}
