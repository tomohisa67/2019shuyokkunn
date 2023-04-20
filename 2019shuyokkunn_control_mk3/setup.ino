#include "pinassign.h"

void led_set(){
  pinMode(LED_R_R, OUTPUT);
  pinMode(LED_R_G, OUTPUT);
  pinMode(LED_R_B, OUTPUT);
  pinMode(LED_L_R, OUTPUT);
  pinMode(LED_L_G, OUTPUT);
  pinMode(LED_L_B, OUTPUT);
}

void distance_set(){
  pinMode(TRG, OUTPUT);
  pinMode(ECH, INPUT);
}

void servo_set(){
  pinMode(SERVO_REDE, OUTPUT);
  servo_serial.begin(9600);
  servo_reboot(1);
  servo_reboot(2);
  servo_torque(1, 1);
  servo_torque(2, 1);
}
