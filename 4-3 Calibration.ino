const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 9;        // pin that the LED is attached to
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > sensorMax) { sensorMax = sensorValue; } //maximum
    if (sensorValue < sensorMin) { sensorMin = sensorValue; } //minimum
  }
  digitalWrite(13, LOW);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  sensorValue = constrain(sensorValue, 0, 255);
  analogWrite(ledPin, sensorValue);
}
