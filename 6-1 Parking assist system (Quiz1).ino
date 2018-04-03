#define echoPin 7
#define trigPin 8
#define beep 65
int maximumRange=200;
int minimumRange=0;
int safe=100;
int careful=30;
long duration,distance;
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
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
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
  }
  else if (distance >= careful && distance <= safe)
  {
    Serial.println("\tBe careful!");
    //tone(9,beep);
    //delay(400);
    //noTone(9);
    //delay(100);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
  }
  else
  {
    Serial.println("\tDangerous!");
    //tone(9,beep);
    //delay(200);
    //noTone(9);
    //delay(50);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  }
  delay(100);
}