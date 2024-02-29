#include <Servo.h>
#include <AFMotor.h>


Servo servo1;

AF_Stepper motor1(30, 1);
AF_Stepper motor2(30, 2);

#define STEPPER_PIN_1 22  //
#define STEPPER_PIN_2 24 // stepper 3 pins
#define STEPPER_PIN_3 26 //
#define STEPPER_PIN_4 28 //     

int stepper3_step_number = 0;           //for stepper 3 **do not change**
int button = 32;
int angle = 0;
int servo_pin = 10;
int Stepper1_2_speed = 1500;
int max_trimmer_angle = 100;
int num_of_steps_stepper_3 = 2048;      // Total steps for revolution is 2048 each steps moves motor by 0.17578125 degree


void setup() {
  
  Serial.begin(9600);

  servo1.attach(servo_pin);
  pinMode(button, INPUT);

  
  motor1.setSpeed(Stepper1_2_speed);
  motor2.setSpeed(Stepper1_2_speed);

  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);


}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//coding for stepper 3

void OneStep(bool dir){
    if(dir){
switch(stepper3_step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(stepper3_step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
 
  
} 
  }
stepper3_step_number++;
  if(stepper3_step_number > 3){
    stepper3_step_number = 0;
  }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void loop()
{
  
  for (angle = 0; angle < max_trimmer_angle; angle++)
  {
    servo1.write(angle);
    delay(50);
    if (digitalRead(button) == HIGH)  break;
  
   }

  
  int num_steps = 0;

  
  for (; digitalRead(button) == HIGH; num_steps++)
  {
    motor1.step(1, BACKWARD, SINGLE);
    motor2.step(1, BACKWARD, SINGLE);
    //trimmer on
  }

  
  if (digitalRead(button) == HIGH)
  { 
    angle = 0; //ear problem discuss
    servo1.write(angle);
    
    for (; num_steps > 0; num_steps--)
    {
      motor1.step(1, FORWARD, SINGLE);
      motor2.step(1,FORWARD, SINGLE);
    }
    
  }


  
// for(int i=0;i<343;i++)
//  {
//    OneStep(false);
//    delay(2);
//  }

}
