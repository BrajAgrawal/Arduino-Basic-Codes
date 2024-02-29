char ch;
//double dura,dist;
void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    ch = Serial.read();
    Serial.println(ch);
    //    if(ch=='a')
    //    {
    //      Serial.println(ch);
    //      /*delay(2);
    //      digitalWrite(8,HIGH);
    //      delay(10);
    //      digitalWrite(8,LOW);
    //
    //      dura=pulseIn(7,HIGH);
    //      dist=dura*0.017;
    //      Serial.print("Distance is ");
    //      Serial.println(dist);*/
    //    }
  }
}
