const int ledPin =  13;         // LED pin
int ledState = LOW;             // save the state of LED
unsigned long previousMillis = 0;        // store last time LED was updated
const long interval = 500;           // interval to blink (ms)

void setup()
{
  pinMode(ledPin, OUTPUT);
}
void loop() 
{
  unsigned long currentMillis = millis(); //get time
  //check the intervel 
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis; //update the time
    if (ledState == LOW)
    {
      ledState = HIGH;  //change state
    }
    else
    {
      ledState = LOW; //change state
    }
    digitalWrite(ledPin, ledState);
  }
  //can do other task...
}
