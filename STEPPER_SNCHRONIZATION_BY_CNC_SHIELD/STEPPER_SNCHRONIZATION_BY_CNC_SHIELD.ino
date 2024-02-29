// Stepper Motor X
const int stepPinX = 2; //X.STEP
const int dirPinX = 5; // X.DIR

const int stepPinY = 3; //X.STEP
const int dirPinY = 6; // X.DIR

int button = 22;
int a;

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPinX, OUTPUT);
  pinMode(dirPinX, OUTPUT);

  pinMode(stepPinY, OUTPUT);
  pinMode(dirPinY, OUTPUT);
}
void loop() {
  digitalWrite(dirPinX, HIGH) ;
  digitalWrite(dirPinY, HIGH) ; // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  // if()
  //{
  while ()
  {



    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(1000);



  }
  //trimmer on
  // }
  //}
  // delay(1000); // One second delay
  //
  // digitalWrite(dirPin,LOW); //Changes the rotations direction
  // // Makes 400 pulses for making two full cycle rotation
  // for(int x = 0; x < 400; x++) {
  //
  // delay(1000);
}
