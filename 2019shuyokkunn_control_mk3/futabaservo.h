#include <SoftwareSerial.h>
#include "pinassign.h"

SoftwareSerial servo_serial(SERVO_RX, SERVO_TX);

// 関数のプロトタイプ宣言
void servo_torque(unsigned char , unsigned char );
void servo_move(unsigned char , int , int );
void servo_reboot(unsigned char );
unsigned char checksum(unsigned char * , int );
void packet_data_send(unsigned char * , int );

// サーボモータアサイン
#define HEAD_SERVO 2
#define ARM_SERVO 1
