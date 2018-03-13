int ledpin=9;
int brightness=0;
int fadeAmount=5;

void ooo()
{
  analogWrite(ledpin,brightness);
  delay(3000); //3 second
  analogWrite(ledpin,0);
  delay(1000);
}
void sss()
{
  analogWrite(ledpin,brightness);
  delay(1000);  //1 second
  analogWrite(ledpin,0);
  delay(1000);
}
void one()
{
  //S
  Serial.println("==S==");
  sss();
  sss();
  sss();
  delay(1000);
  //O
  Serial.println("==O==");
  ooo();
  ooo();
  ooo();  
  delay(1000);
  //S
  Serial.println("==S==");
  sss();
  sss();
  sss();  
  delay(1000); 
}
void setup() {
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}
void loop() {
 int value=analogRead(A0);
 float voltage=value*(5.0/1023.0); //value max = 1023, voltage max = 5
 Serial.println(voltage);
 brightness=voltage*(255.0/5.0);
 Serial.println(brightness);
 one();
 brightness=0;
 delay(1);

}
