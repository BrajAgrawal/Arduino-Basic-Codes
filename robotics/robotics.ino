#include <Servo.h>

// Define our servos
Servo servo1;
Servo servo2;
Servo servo3;


void setup() {
  
  Serial.begin(9600);

  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);


}
void loop()
{
  int sign1 = analogRead(0);
  int sign2 = analogRead(1);
  int sign3 = analogRead(2);
  //  Serial.print(sign);

  int  angle1 = map(sign1,0,1023,0,180);
  servo1.write(angle1);
  
  
  int  angle2 = map(sign2,0,1023,0,180);
  servo2.write(angle2);
  
  
  int  angle3 = map(sign3,0,1023,0,180);
  servo3.write(angle3);
  delay(500);
//for(int angle =0;angle<180;angle++)
//  {
//    servo1.write(angle);
//    servo2.write(angle);
//    servo3.write(angle);
//    delay(50);
//  }
//  delay(2000);
}
