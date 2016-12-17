/*
    Author: Camiel Kerkhofs
    Version: 0.1
    Date: Dec 2016

    Description: Initial program, testing arduino sensor shield with single servo
*/

#include <Servo.h>

//initiate servos
Servo servo_L1J1; // leg 1, joint 1

//servo position variables
int servo_L1J1_pos = 0;

void setup() {

  //attach servos
  servo_L1J1.attach(9);
}

void loop() {
  
  for (servo_L1J1_pos = 30; servo_L1J1_pos <= 160; servo_L1J1_pos += 1) {
    servo_L1J1.write(servo_L1J1_pos);
    delay(5);
  }

  for (servo_L1J1_pos = 160; servo_L1J1_pos >= 30; servo_L1J1_pos -= 1) {
    servo_L1J1.write(servo_L1J1_pos);
    delay(5);
  }
}
