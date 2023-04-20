#include "pinassign.h"

float get_distance(){
  int diff;
  float distance;

  digitalWrite(TRG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRG, LOW);

  diff = pulseIn(ECH, HIGH);
  distance = (float)diff * 0.01715;
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("cm");

  return distance;
}

void eye_red(){
  digitalWrite(LED_R_R, HIGH);
  digitalWrite(LED_R_G, LOW);
  digitalWrite(LED_R_B, LOW);
  digitalWrite(LED_L_R, HIGH);
  digitalWrite(LED_L_G, LOW);
  digitalWrite(LED_L_B, LOW);
}

void eye_green(){
  digitalWrite(LED_R_R, LOW);
  digitalWrite(LED_R_G, HIGH);
  digitalWrite(LED_R_B, LOW);
  digitalWrite(LED_L_R, LOW);
  digitalWrite(LED_L_G, HIGH);
  digitalWrite(LED_L_B, LOW);
}

void eye_blue(){
  digitalWrite(LED_R_R, LOW);
  digitalWrite(LED_R_G, LOW);
  digitalWrite(LED_R_B, HIGH);
  digitalWrite(LED_L_R, LOW);
  digitalWrite(LED_L_G, LOW);
  digitalWrite(LED_L_B, HIGH);
}
