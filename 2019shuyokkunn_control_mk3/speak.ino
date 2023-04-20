#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"
//https://github.com/DFRobot/DFRobotDFPlayerMini

SoftwareSerial speak_serial(DFPlayer_RX, DFPlayer_TX); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void speak_set(){
  speak_serial.begin(9600);
  
//  Serial.println();
//  Serial.println(F("DFRobot DFPlayer Mini Demo"));
//  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
 
//  if (!myDFPlayer.begin(speak_serial)){  //Use softwareSerial to communicate with mp3.
//    Serial.println(F("Unable to begin:"));
//    Serial.println(F("1.Please recheck the connection!"));
//    Serial.println(F("2.Please insert the SD card!"));
//    while(true);
//  }
//  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(10);  //Set volume value. From 0 to 30
}

void speak_apple(){
  myDFPlayer.playMp3Folder(1);
}

void speak_banana(){
  myDFPlayer.playMp3Folder(2);
}

void speak_melon(){
  myDFPlayer.playMp3Folder(3);
}
