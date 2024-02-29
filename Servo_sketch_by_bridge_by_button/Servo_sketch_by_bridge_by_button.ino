#include <Servo.h>

// Define our servos
Servo servo1;
int button = 22,angle=0;

void setup() {
  // Define servo signal inputs(Digital) PWM 1,2,3
  Serial.begin(9600);
 
  servo1.attach(52);
   pinMode(button,INPUT);

}
void loop() 
{   servo1.write(0);
   for(angle=0;digitalRead(button)== HIGH;angle+=1)
{
 servo1.write(angle);
 delay(10);
 while(digitalRead(button)==HIGH){}  
}
//   for(angle =180;angle>0;angle-=1)
//{
// servo1.write(angle);
// delay(10);
// while(digitalRead(button)==HIGH){}  
//}
     
}
