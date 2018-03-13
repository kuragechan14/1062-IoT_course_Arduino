int melody[10] = {0};
int noteDurations[] = {
  4, 4, 4, 4, 4,
  4, 4, 4, 4, 4
};

const int  buttonPin = 2; 
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 5000;
unsigned long btn_on=0;
unsigned long btn_off=0;
unsigned long interval=0;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(A0); // read the sensor
  //Serial.println(sensorReading);
  int thisPitch = map(sensorReading, 0, 1023, 120, 1500);
  //potentiometer:0~1023, tone: 0~255(can change)
  tone(9, thisPitch, 10);  // play the pitch
  delay(1);        // delay in between reads for stability

  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState)   //state change
  {
    if (buttonState == HIGH)
    {
      // LOW to HIGH(now) => on
      melody[buttonPushCounter]=thisPitch;
      buttonPushCounter++;
      btn_on=millis();
      Serial.print("number of button pushes: ");
      Serial.print(buttonPushCounter);
      Serial.print("\t");
      Serial.println(thisPitch);
    }
    else  //HIGH to LOW(now) => off
    {
      btn_off=millis();
      interval=btn_off-btn_on;
      Serial.print("interval: ");
      Serial.println(interval);
    }
    delay(50);  // Delay a little bit to avoid bouncing
  }
  lastButtonState = buttonState;  // save the current state

  


  //Play the melody
  if (interval>debounceDelay || (buttonPushCounter > 0 && buttonPushCounter % 10 == 0))
  {
    for (int thisNote = 0; thisNote < buttonPushCounter; thisNote++)
    {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(9, melody[thisNote], noteDuration);
      Serial.print(thisNote);
      Serial.print("\t");
      Serial.println(melody[thisNote]);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
    buttonPushCounter=0;
  }
}
