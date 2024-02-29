#include <Servo.h>


Servo servo1;

// Stepper Motor X
const int stepPinX = 2; //X.STEP
const int dirPinX = 5; // X.DIR


// Stepper Motor Y
const int stepPinY = 3; //Y.STEP
const int dirPinY = 6; // Y.DIR


// Stepper Motor Z
const int stepPinZ = 4; //Z.STEP
const int dirPinZ = 7; // Z.DIR



int button = 22;
int angle = 0;
int servo_pin = 52;
int X_Y_Speed = 1000;
int Z_Speed = 1000;
int max_trimmer_angle = 100;
int steps_Z = 20;
int num_steps = 0;
int trimmer = 40 ;

void setup() {

  Serial.begin(9600);

  servo1.attach(servo_pin);

  pinMode(button, INPUT);

  pinMode(trimmer, OUTPUT);


  pinMode(stepPinX, OUTPUT);   //X
  pinMode(dirPinX, OUTPUT);    //X

  pinMode(stepPinY, OUTPUT);   //Y
  pinMode(dirPinY, OUTPUT);    //Y

  pinMode(stepPinZ, OUTPUT);   //Z
  pinMode(dirPinZ, OUTPUT);    //Z

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void loop()
{



  for (angle = 0; angle < max_trimmer_angle || digitalRead(button) == LOW; angle++)
  {
    servo1.write(angle);
    delay(50);
  

  }

  Serial.println("servo done");

  digitalWrite(dirPinX, HIGH); // Enables the motorX to move in a particular direction
  digitalWrite(dirPinY, HIGH); // Enables the motorY to move in a particular direction


  while(true)
  {
    digitalWrite(trimmer, HIGH);


    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPinX, LOW);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(1000);
    //trimmer on
  }

  digitalWrite(trimmer, LOW);

  Serial.println("stepper 1 done");




  angle = 0;
  servo1.write(angle);

  digitalWrite(dirPinX, LOW);
  digitalWrite(dirPinY, LOW);

  for (; num_steps > 0; num_steps--)
  {
    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPinX, LOW);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(1000);
  }




  Serial.println("stepper 2 done");


  digitalWrite(dirPinZ, HIGH);

  for (int i = 0; i < steps_Z; i--)
  {
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(Z_Speed);
    digitalWrite(stepPinZ, LOW);
    delayMicroseconds(Z_Speed);
  }


}
