#include <Servo.h>
#include <AFMotor.h> 
// Define our servos
Servo servo1;
AF_Stepper motor1(30,1);
AF_Stepper motor2(30,2);

int steps_per_loop =100 ;
int stepper_speed = 2500 ;
 
void setup() {


  Serial.begin(9600);
   motor1.setSpeed(stepper_speed);
   motor2.setSpeed(stepper_speed);

}
void loop() 
{   
   while(true)
   {
    motor1.step(steps_per_loop,BACKWARD,SINGLE);  //HERE
    motor2.step(steps_per_loop,BACKWARD,SINGLE);  //HERE
   }
  while(false)
   {
    motor1.step(steps_per_loop,FORWARD,SINGLE);  //HERE
    motor2.step(steps_per_loop,FORWARD,SINGLE);  //HERE
   }
        
}
