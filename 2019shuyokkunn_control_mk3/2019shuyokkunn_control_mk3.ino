//受信用arduino
//サーボと音声用のarduino②に書き込んでください

#include "pinassign.h"
#include "setup.h"
#include "eye.h"
#include "futabaservo.h"
#include "move_function.h"
#include "speak.h"

int mode = 0; // 動作モード
int state = 1; // ロックオンモード中の状態
int direct = 0; // 向き25分割
int turn = 0; // 回転の向き
float dist;

void setup() {
  servo_set();
  Serial.begin(9600);
  while(!Serial);
  eye_red();
  // 誤りなる場合次をコメントアウト
  //Serial.println(9600);
  // 以下動作確認用　最初のdelayにより、機械的にローテクに角度の調整が可能
  servo_move(HEAD_SERVO, 0, 50);
  delay(1000);
  servo_move(ARM_SERVO, 0, 50);
  delay(1000);

  servo_move(HEAD_SERVO, 10 * DEG, INTERVAL); 
  delay(1000);
  servo_move(HEAD_SERVO, -10 * DEG, INTERVAL);
  delay(1000);
  servo_move(ARM_SERVO, 10 * DEG, INTERVAL); 
  delay(1000);
  servo_move(ARM_SERVO, -10 * DEG, INTERVAL);
  delay(1000);

  pinMode(A1,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

  //リンゴのボタンを押した時
  if(analogRead(A1) >= 512){
    servo_move(ARM_SERVO, 1200, 100);//アームを動かす
    speak_apple();//リンゴ　好き
    digitalWrite(11, HIGH);
    delay(2000);
    digitalWrite(11, LOW);
    delay(1000);
    
  //バナナのボタンを押した時  
  }else if(analogRead(A4) >= 512){
    servo_move(HEAD_SERVO, 900, 100);//頭用サーボ動かす
    speak_banana();//バナナ　嫌い
    digitalWrite(12, HIGH);
    delay(2000);
    digitalWrite(12, LOW);
    delay(1000);

  //メロンのボタンを押した時
  }else if(analogRead(A5) >= 512){
    servo_move(ARM_SERVO, 1200, 100);//アームを大きく動かす
    speak_melon();//メロン　大好き
    digitalWrite(13, HIGH);
    delay(2000);
    digitalWrite(13, LOW);
    delay(1000);
    
  }else{
    ;
  }
  delay(50);

}
