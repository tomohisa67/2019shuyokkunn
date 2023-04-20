# shuyokkun_2019
 esp02とシリアル通信しているarduino①に書き込むためのプログラムがwifi_esp02
 サーボと音声を動作させるためのarduino②に書き込むためのプログラムがshuyokkunn_control
 htmlをサーバーにアップロードしてください。Dockerで動作確認済み

 ・構成
 wifiルーター
 Mac book //サーバー
 スマホのボタン→php→esp02→arduino①→arduino②→サーボ、音声
　　　　　　　　　 |__appleSet.php→applelog.txt→appleGet.txt 
　　　　　　　　　 
　こちらのサイトを参考にしました。 https://ics.media/entry/10457/　　　　　　　　 
　他にもいろいろ方法があると思うので試してみてください。
　
 # wifi_esp02
 ・スマホとesp02をwifiで接続して、信号をarduino②に送るためのプログラムです。
 ・このプログラムを書き込む前にesp02との通信速度をATコマンドで115200から9600に変えるためにSoftwareSerialExample_esp02を書き込んでください。
 ・ATコマンドは一度aruduinoスケッチを書き込むと使えなくなるので使えるようにリセットしてください。https://keijirotanabe.github.io/blog/2017/02/06/esp8266-at-reset-170207/
 ・ESP8266.hのライブラリーの#define ESP8266_USE_SOFTWARE_SERIALの部分をコメントアウトしてください。
    コメントアウトすることでesp02のライブラリーをArduinoに書き込んでそのまま使えます。
    ESP8266.hに関してはこちらhttps://github.com/itead/ITEADLIB_Arduino_WeeESP8266
  ・esp02はwifiルーターによっては繋がりません。tcp errになる。たぶん。

# 2019shuyokkunn_control_mk3
・arduino①からの信号を受信してサーボと音声を動かすためのプログラムです。

# arduino①とarduino②とのシリアル通信
・arduinoを2つ使った理由はサーボとのシリアル通信の影響でarduino内で干渉するらしい。ESP8266.hが使えなくなった。
・arduino間のシリアル通信に失敗したのでarduino①でdigitalWrite HIGHにしてarduino②のアナログピンを強制的にHIGHにして完了させました。

# hogeフォルダーの構成

hoge
|____index.html
|____cs___styles.css
|____js___apple2.js                  //appleSet.phpの実行
|        |___jquery.3.4.1.min.js    //(ajax) apple2.jsのためのもの
|        |___main.js       //アニメーション         
|
|___appleSet.php //文字列をapple.txtに書き込む
|___applelog.txt   //文字列が書き込まれる
|___appleGet.php //文字列をapplelog.txtから取得

