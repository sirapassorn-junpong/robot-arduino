#include <Servo.h>
Servo servo1; //make object right
Servo servo2; //make object left

void setup() {
  servo1.attach(11); //make object to attach arm
  servo2.attach(10); //make object to attach  arm
  pinMode(2, INPUT_PULLUP); //left pin hit
  pinMode(3, INPUT_PULLUP); //right pin hit

}

void brake (){ //do not have formular because we want it to stop,so read only
  servo1.write(92);
  servo2.write(94.5);
}

void forward (double x) { //open forward variable
  double n1 = 92-x; //formula of left forward
  double n2 = 94.5+x; //formula of right forward
  servo1.write(n1); //read left
  servo2.write(n2); //read right

}

void loop() {
  
  int left = digitalRead(2); //left pin hit then read
  int right=digitalRead(3); //right pin hit then read

  //write code for working
  
  if(left==HIGH && right==HIGH) {
    forward(50); // output move
  } else if (left==LOW && right==LOW){
    // just in case
  } else if (left==LOW) { //left hit
    brake();
    delay(1000);

    forward(-40);
    delay(1000);

    brake();
    delay(1000);

    servo1.write(92+40);
    servo2.write(94.5+60);
    delay(1000);

    brake();
    delay(1000);
    
  }else if (right==LOW) { //right hit
    brake();
    delay(1000);

    forward(-40);
    delay(1000);

    brake();
    delay(1000);

    servo1.write(92-60);
    servo2.write(94.5-40);
    delay(1000);

    brake();
    delay(1000);
  
  }}
