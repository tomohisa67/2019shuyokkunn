// 距離センサー
#define TRG 5
#define ECH 6

// LED
#define LED_R_R 4
#define LED_R_G 3
#define LED_R_B 2
#define LED_L_R A0
#define LED_L_G A3
#define LED_L_B A1

// 音声
#define DFPlayer_RX 9
#define DFPlayer_TX 10

// サーボモータ
#define SERVO_RX 13
#define SERVO_REDE 12
#define SERVO_TX 11

//その他サーボ用設定
#define FAST 10
#define INTERVAL 50
#define SLOW 100
#define HEAD 300
#define DEG 50//これにより角度+-60度(-600～600,１は0.1度)までの間を２５分割する。
#define MOVE 600

//捜索・照準モード切替
#define SEARCH_MODE 0
#define LOCK_ON_MODE 1

//閾値
#define MIN_RANGE 30 //最小距離
#define MIDDLE_RANGE 60//中距離
#define MAX_RANGE 100//最大距離

//右転・左転
#define RIGHT_TURN 1
#define LEFT_TURN -1

//照準時左右ずれ調整
#define LEFT_LOCK 0
#define MIDDLE_LOCK 1
#define RIGHT_LOCK 2


//旋回限界
#define LEFT_LIMIT -12
#define RIGHT_LIMIT 12
