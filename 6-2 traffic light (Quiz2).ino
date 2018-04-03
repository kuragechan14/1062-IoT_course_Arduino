#define beep1 131
#define beep2 165
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
long previous=0;
long interval=1000;
int state=0;
void red_light()
{
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
}
void yellow_light()
{
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
}
void green_light()
{
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
}
void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  unsigned long current=millis();
  if(current-previous>=interval)
  {
    previous=current;
    state++;
    Serial.print(state);
    Serial.print("\t");
    if(state<=10)
    {
      Serial.println("Green");
      green_light();
      tone(9,beep1);
      delay(400);
      noTone(9);
    }
    else if(state>10 && state <=13)
    {
      Serial.println("Yellow");
      yellow_light();
    }
    else
    {
      Serial.println("Red");
      red_light();
      tone(9,beep2);
      delay(400);
      noTone(9);
      if(state==23){state=0;}
    }
  }
}
