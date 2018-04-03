const int buttonPin=2;
const int analogInPin=A0;
const int ledPin=13;
int state=0;
int last_state=0;
int pwd=0;
int mode=0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
}

void loop() {
  if (mode==0)
  {
    Serial.println("Please enter the Password...");
    state=digitalRead(buttonPin);
    if(state!=last_state)
    {
      pwd=analogRead(analogInPin);  //read the value
      Serial.print("Password has been set: ");
      Serial.println(pwd);
      mode=1;
      delay(50);  //avoid bouncing
    }
    last_state=state;
  }
  else  //if (mode==1), guess
  {
    while (Serial.available() > 0)
    {
        Serial.print("GUESS\t");
        int guess = Serial.parseInt();
        //Serial.println(guess);
        if (Serial.read() == '\n')
        {
            Serial.print(guess);
            Serial.print("\t");
            if(guess>pwd)
            {Serial.println("Too Large!");}
            else if(guess<pwd)
            {Serial.println("Too Small!");}
            else
            {
              Serial.println("Bingo!");
              digitalWrite(ledPin,HIGH);
              break;
            }
        }
    }
  }
  delay(50);
  
  
}
