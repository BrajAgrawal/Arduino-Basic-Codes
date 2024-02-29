#include <Servo.h>

// Define our servos
Servo servo1;
Servo servo2;
Servo servo3;

// Servo position in degrees

void setup() {
  // Define servo signal inputs(Digital) PWM 1,2,3
  Serial.begin(9600);

  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);


}
void loop()
{
//  int sign1 = analogRead(A0);
//  int sign2 = analogRead(A1);
//  int sign3 = analogRead(A2);
//  //  Serial.print(sign);
//
//  int  angle1 = sign1 / 5.5;
//  servo1.write(angle1);
//  delay(100);
//  
//  int  angle2 = sign2 / 5.5;
//  servo2.write(angle2);
//  delay(100);
//  
//  int  angle3 = sign3 / 5.5;
//  servo3.write(angle3);
//  delay(100);
for(int angle =0;angle<180;angle++)
  {
    servo1.write(angle);
    servo2.write(angle);
    servo3.write(angle);
    delay(50);
  }
  delay(2000);
}
