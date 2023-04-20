#include "pinassign.h"

// トルクの種類を設定
void servo_torque(unsigned char ID, unsigned char data){
  unsigned char tx_data[9];    // 送信データバッファ [9byte]
  
  // パケットデータ生成
  tx_data[0] = 0xFA;                                     //Header
  tx_data[1] = 0xAF;                                     //Header
  tx_data[2] = ID;                                       //ID
  tx_data[3] = 0x00;                                     //Flags
  tx_data[4] = 0x24;                                     //Address
  tx_data[5] = 0x01;                                     //Length
  tx_data[6] = 0x01;                                     //Count
  tx_data[7] = data;                                     //ON/OFF
  // チェックサム計算
  tx_data[8] = checksum(tx_data, 8);               //CheckSum
  // パケットデータ送信
  packet_data_send(tx_data, 9);
}

void servo_move(unsigned char ID, int angle, int movetime){
  unsigned char tx_data[12];    // 送信データバッファ [12byte]
  
  // パケットデータ生成
  tx_data[0] = 0xFA;                            //Header
  tx_data[1] = 0xAF;                            //Header
  tx_data[2] = ID;                              //ID
  tx_data[3] = 0x00;                            //Flags
  tx_data[4] = 0x1E;                            //Address
  tx_data[5] = 0x04;                            //Length
  tx_data[6] = 0x01;                            //Count
  tx_data[7] = (unsigned char)0x00FF & angle;   //Angle
  tx_data[8] = (unsigned char)0x00FF & (angle >> 8);   //Angle
  tx_data[9] = (unsigned char)0x00FF & movetime;   //Time
  tx_data[10] = (unsigned char)0x00FF & (movetime >> 8);  //Time
  // チェックサム計算
  tx_data[11] = checksum(tx_data, 11);    //Checksum
  // パケットデータ送信
  packet_data_send(tx_data, 12);
}

// サーボ再起動
void servo_reboot(unsigned char ID){
  unsigned char tx_data[8];    // 送信データバッファ [8byte]
  
  // パケットデータ生成
  tx_data[0] = 0xFA;                                     //Header
  tx_data[1] = 0xAF;                                     //Header
  tx_data[2] = ID;                                       //ID
  tx_data[3] = 0x20;                                     //Flags
  tx_data[4] = 0xFF;                                     //Address
  tx_data[5] = 0x00;                                     //Length
  tx_data[6] = 0x00;                                     //Count
  // チェックサム計算
  tx_data[7] = checksum(tx_data, 7);               //CheckSum
  // パケットデータ送信
  packet_data_send(tx_data, 8);
  delay(100);
}

// チェックサム計算
unsigned char checksum(unsigned char * data, int data_len){
  unsigned char sum = 0;     // チェックサム計算用変数
  for (int i=2; i<data_len; i++){
    sum ^= data[i];          // XOR計算 
  }
  
  return sum;
}

// パケットデータ送信
void packet_data_send(unsigned char * data, int data_length){
    digitalWrite(SERVO_REDE, HIGH);     // 送信許可
    for(int i=0; i<data_length; i++){
        servo_serial.write(data[i]);
    }
    servo_serial.write(data, data_length);
    servo_serial.flush();              // データ送信完了待ち
    digitalWrite(SERVO_REDE, LOW);      // 送信禁止
}
