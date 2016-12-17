/*
    Author: Camiel Kerkhofs
    Version: 0.1
    Date: Dec 2016

    Description: Initial program, testing arduino sensor shield with single servo
*/

#include <Servo.h>
#include <EEPROM.h>

//initiate servos
Servo servo_L1J1; // leg 1, joint 1

//servo position variables
int servo_L1J1_pos = 30;

//servo EEPROM adresses
byte servo_L1J1_adress = 0;



void setup() {

  //Serial
  Serial.begin(9600);
  Serial.println("Hexapod entered startup");

  //attach servos
  servo_L1J1.attach(9);

  //read last servo positions from non volatile EEPROM
  servo_L1J1_pos = EEPROM.read(servo_L1J1_adress);
  Serial.println(servo_L1J1_pos);

  //sweep back to start pos
  while (servo_L1J1_pos > 30) {
    servo_L1J1.write(servo_L1J1_pos);
    servo_L1J1_pos = servo_L1J1_pos - 1;
    delay(5);
  }
}

void loop() {



  
  for (servo_L1J1_pos = 30; servo_L1J1_pos <= 160; servo_L1J1_pos += 1) {
    servo_L1J1.write(servo_L1J1_pos);
    delay(5);

    save_positions();
  }

  for (servo_L1J1_pos = 160; servo_L1J1_pos >= 30; servo_L1J1_pos -= 1) {
    servo_L1J1.write(servo_L1J1_pos);
    delay(5);

    save_positions();
  }
}

void save_positions() {
  //save the current servo positions to the non volatile EEPROM, to prevent servo jerks at startup

  EEPROM.write(servo_L1J1_adress, servo_L1J1_pos);
  Serial.println(servo_L1J1_pos);
  
}


