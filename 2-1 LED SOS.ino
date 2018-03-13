int ledpin=13;
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
void setup() {
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT); //output mode
}
void loop() {
  //S
  sss();
  sss();
  sss();
  delay(2000);
  //O
  ooo();
  ooo();
  ooo();
  delay(2000);
  //S
  sss();
  sss();
  sss();
  delay(6000); 
  Serial.println("Test");
}
