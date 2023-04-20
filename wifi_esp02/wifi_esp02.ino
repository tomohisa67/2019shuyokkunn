//wifi機能のためのArduino①に書き込んでください（esp02とシリアル通信しているArduino）
//ssidとpasswordとhost_nameを書き換えてください

#include "ESP8266.h"
#include <SoftwareSerial.h>
#include "setupLED.h"//ledには使わないよ

#define SSID "xxxxxxxx"
#define PASSWORD "xxxxxxxxxx"
#define HOST_NAME "192.168.xxx.xx"
#define FILE_NAME "appleGet.php"

SoftwareSerial mySerial(2, 3);  //RX, TX
ESP8266 wifi(mySerial);

/**
 * 初期設定
 */
void setup(void)
{
  Serial.begin(9600);

  if (wifi.setOprToStationSoftAP()) {
    Serial.println("to station ok");
  } else {
    Serial.println("to station error");
  }

  if (wifi.joinAP(SSID, PASSWORD)) {
    Serial.println("connect success");
  } else {
    Serial.println("connect error");
  }

  if (wifi.disableMUX()) {
    Serial.println("disable mux success");
  } else {
    Serial.println("disable mux error");
  } 

  pinMode(LED_R,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(LED_Y,OUTPUT);
  pinMode(A1,INPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(A2,INPUT);
  
}

void loop(void)
{
  uint8_t buffer[512] = {0};

  // TCPで接続
  wifi.createTCP(HOST_NAME, 80);

  // TCPで接続
  if (wifi.createTCP(HOST_NAME, 80)) {
    Serial.print("create tcp ok\r\n");
  } else {
    Serial.print("create tcp err\r\n");
  }
  
  // サーバーへ渡す情報
 char sendStr[128];
 sprintf(sendStr, "GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: arduino\r\n\r\n", FILE_NAME, HOST_NAME);
 wifi.send((const uint8_t*)sendStr, strlen(sendStr));

//サーバからの文字列を入れるための変数
  String resultCode = "";

  // 取得した文字列の長さ
  uint32_t len = wifi.recv(buffer, sizeof(buffer), 10000);

  // 取得した文字数が0でなければ
  if (len > 0) {
    for(uint32_t i = 0; i < len; i++) {
      resultCode += (char)buffer[i];
    }

    // lastIndexOfでresultCodeの最後から改行を探す
    int lastLF = resultCode.lastIndexOf('\n');

    // resultCodeの長さを求める
    int resultCodeLength = resultCode.length();
  
    // substringで改行コードの次の文字から最後までを求める
    String resultString = resultCode.substring(lastLF+1, resultCodeLength);

    // 前後のスペースを取り除く
    resultString.trim();

    Serial.println(resultCode);
    Serial.println(resultString);

    // 取得した文字列がONならば
    if(resultString == "a_ON") {
      digitalWrite(LED_R, HIGH);
      
    } else {
      digitalWrite(LED_R, LOW);
      
    }
    
    if(resultString == "b_ON"){
      digitalWrite(LED_Y, HIGH);
      
    } else {
      digitalWrite(LED_Y, LOW);
      
    }
    
    if(resultString == "m_ON"){
      digitalWrite(LED_G, HIGH);

    }else {
      digitalWrite(LED_G, LOW);
      
    }
  }

  // 200ミリ秒待つ
  delay(200);
  
 }
