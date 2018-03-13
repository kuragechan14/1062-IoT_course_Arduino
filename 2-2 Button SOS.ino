int ledpin=13;
int btnpin=2;
int flag=0;
void ooo()
{
  digitalWrite(ledpin,HIGH);
  delay(3000); //3 second
  digitalWrite(ledpin,LOW);
  delay(1000);
}
void sss()
{
  digitalWrite(ledpin,HIGH);
  delay(1000);  //1 second
  digitalWrite(ledpin,LOW);
  delay(1000);
}
void one()
{
  //S
  sss();
  sss();
  sss();
  Serial.println("==S==");
  delay(2000);
  //O
  ooo();
  ooo();
  ooo();
  Serial.println("==O==");
  delay(2000);
  //S
  sss();
  sss();
  sss();
  Serial.println("==S==");
  delay(2000); 
}
void setup() {
  Serial.begin(9600);
  pinMode(btnpin,INPUT); //intput mode
  pinMode(ledpin,OUTPUT); //output mode
}
void loop() {
 int state=digitalRead(btnpin);
 if(state==HIGH)
 {
    delay(1000);
    one();
    Serial.println(state);
 }
  Serial.println(state);
  delay(1);
}
