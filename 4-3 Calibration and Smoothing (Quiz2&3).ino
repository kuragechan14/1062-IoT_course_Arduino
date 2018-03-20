const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 9;        // pin that the LED is attached to
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int Smoothing(int s_value)
{
  total = total - readings[readIndex];  // remove the last reading
  readings[readIndex] = s_value;
  total = total + readings[readIndex];  // add the reading to the total
  readIndex = readIndex + 1;  //next position
  if (readIndex >= numReadings) //10
  {
    readIndex = 0;  // wrap around to the beginning
  }
  average = total / numReadings;
  return average;
}
int Calibration(int s_value)
{
  s_value = map(s_value, sensorMin, sensorMax, 0, 255);
  //map function is linear, so it may greater than 255
  s_value = constrain(s_value, 0, 255);
  //max=255,min=0,return sensorValue
  return s_value;
}
void setup() {
  Serial.begin(9600);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) // initialize
  { readings[thisReading] = 0;}
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  while (millis() < 5000) // calibrate during the first five seconds
  {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > sensorMax)  // record the maximum
    { sensorMax = sensorValue; }
    if (sensorValue < sensorMin)  // record the minimum
    { sensorMin = sensorValue; }
  } 
  digitalWrite(13, LOW);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  sensorValue = Calibration(sensorValue);
  sensorValue = Smoothing(sensorValue);
  delay(10);
  Serial.println(sensorValue);  
  analogWrite(ledPin, sensorValue);
}
