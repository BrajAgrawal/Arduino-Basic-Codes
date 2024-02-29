int speedpin1=5,dir11=4,dir12=3,mspeed=200;

void setup()
{
  pinMode(speedpin1, OUTPUT);
  pinMode(dir11, OUTPUT);
  pinMode(dir12, OUTPUT);
 
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(dir11, HIGH);
  digitalWrite(dir12, LOW);
  analogWrite(speedpin1,255);
  delay(2000);
  analogWrite(speedpin1,mspeed);  
  delay(10000);
}
