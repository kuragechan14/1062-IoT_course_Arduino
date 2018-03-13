// constants won't change
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState); // set initial LED state: HIGH
}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) //button change
  {
    lastDebounceTime = millis();   //reset the debouncing timer
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay)  //after press > 50ms
  {
    if (reading != buttonState) //state change
    {
      buttonState = reading;
      if (buttonState == HIGH)  //if button state is HIGH
      {
        ledState = !ledState; //change LED state
      }
    }
  }
  digitalWrite(ledPin, ledState);  // set the LED
  lastButtonState = reading;  // save the reading
}

