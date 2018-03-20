const int numReadings = 10;

int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int pre_CMA=0;
int CMA=0;

int inputPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
 int s_value = analogRead(inputPin);
 if(readIndex <= numReadings)
  {
    total+=s_value;
    pre_CMA = total / numReadings;
    CMA = pre_CMA;
    readIndex++;
  }
  else
  {
    CMA = (s_value + numReadings * pre_CMA) / (numReadings + 1);
    pre_CMA = CMA; //overwrite
  }
  Serial.println(CMA);
  delay(100);        // delay in between reads for stability
}
