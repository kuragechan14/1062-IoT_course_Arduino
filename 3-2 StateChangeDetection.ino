// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  pinMode(buttonPin, INPUT);   // initialize the button pin as a input:
  pinMode(ledPin, OUTPUT);   // initialize the LED as an output:
  Serial.begin(9600);  // initialize serial communication:
}
void loop() {
  buttonState = digitalRead(buttonPin); // read the pushbutton input pin
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState)   //state change
  { 
    if (buttonState == HIGH)
    {
      // LOW to HIGH(now) => on
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    }
    else  //HIGH to LOW(now) => off
    {
      Serial.println("off");
    }
    delay(50);  // Delay a little bit to avoid bouncing
  }
  lastButtonState = buttonState;  // save the current state
  
  if (buttonPushCounter % 4 == 0) //turn on the LED every 4 pushes,只有4的倍數才亮，其餘都LOW
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

}
