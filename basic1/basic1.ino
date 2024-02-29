#include <Servo.h>
#include <AFMotor.h> 
// Define our servos
Servo servo1;
int button = 9,angle=0;
 // Servo position in degrees
 int serPos = 0;
void setup() {
  // Define servo signal inputs(Digital) PWM 1,2,3
  Serial.begin(9600);
 
  servo1.attach(10);
   pinMode(button,INPUT);

}
void loop() 
{   
   for(angle=0;angle<100;angle++)
{
 servo1.write(angle);
 delay(50);
 if(digitalRead(button)==HIGH){break;}  
}
//int num_steps=0;
// for(;digitalRead(button)==HIGH;num_steps++)
// {
//    motor1.step(1,FORWARD,SINGLE);  
//    motor2.step(1,FORWARD,SINGLE); 
//    //trimmer on 
//   }
// if(digitalRead(button)==HIGH)
// { angle=0;
//  servo1.write(angle);
//  for(;num_steps>0;num_steps--)
//    { 
//      motor1.step(1,BACKWARD,SINGLE);  
//      motor2.step(1,BACKWARD,SINGLE); 
//    }
// }
        
        
}
