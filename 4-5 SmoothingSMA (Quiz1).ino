const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;

void setup() {
  Serial.begin(9600);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) // initialize
  {
    readings[thisReading] = 0;
  }
}

void loop() {
  total = total - readings[readIndex];  // remove the last reading
  readings[readIndex] = analogRead(inputPin);
  total = total + readings[readIndex];  // add the reading to the total
  readIndex = readIndex + 1;  //next position
  if (readIndex >= numReadings) //10
  {
    readIndex = 0;  // wrap around to the beginning
  }
  average = total / numReadings;  // calculate the average:
  Serial.println(average);
  delay(1000);        // delay in between reads for stability
}
