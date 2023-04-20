#include "eye.h"
#include "pinassign.h"

////モジュールごとの駆動関数

//捜索モード
// turn: 向き (左右)
// direct: 向きの25分割
int search(int turn, int direct) {

  int dist;

  servo_move(HEAD_SERVO, (direct + turn) * DEG, INTERVAL);//頭用サーボ動かす。
  delay(10 * INTERVAL);

  dist = get_distance();
  Serial.println("Search Deg: " + String((direct + turn) * DEG) + ", Distance: " + String(dist) + "cm");

  if (dist > MAX_RANGE) {
    return SEARCH_MODE;
  }
  return LOCK_ON_MODE;//もし人を発見したらロックオンモードになる。
}

////ロックオンモード
int lock_on(int direct) {
  float dist[3];

  servo_move(HEAD_SERVO, direct * DEG, INTERVAL);
  delay(10 * SLOW);
//以下９行、人が真正面にいない場合があるため、三方向にサーボを動かし探査する。
  servo_move(HEAD_SERVO, (direct - 1) * DEG, SLOW);
  delay(10 * SLOW);
  dist[LEFT_LOCK] = get_distance();
  servo_move(HEAD_SERVO, direct *  DEG, SLOW);
  delay(10 * SLOW);
  dist[MIDDLE_LOCK] = get_distance();
  servo_move(HEAD_SERVO, (direct + 1) * DEG, SLOW);
  delay(10 * SLOW);
  dist[RIGHT_LOCK] = get_distance();

//最も近いものをclosestへ
  float closest = min(dist[MIDDLE_LOCK], dist[RIGHT_LOCK]);
  closest = min(closest, dist[LEFT_LOCK]);

//シリアルモニタにてどの方向に人がいるかを表示するためにstateに、方向に対応した変数を入れている。stateこれで返してメイン関数の方でその方向を向くようにする。
  int state;
  for (state = 0; state < 3; state++) {
    if (closest == dist[state]) break;
  }
  Serial.print("LOCK ");
  if (state == LEFT_LOCK) {
    Serial.print("LEFT\t");
  } else if (state == MIDDLE_LOCK) {
    Serial.print("MIDDLE\t");
  } else {
    Serial.print("RIGHT\t");
  }
  Serial.print("\tDIST: " + String(dist[state]) + "cm\t\t");

  for(uint8_t i = 0; i < 3; i++) {
    Serial.print(String(dist[i]) + "\t");
  }
  Serial.println();
  
//三方向の中で一番近い方向に向く
  servo_move(HEAD_SERVO, (direct - 1 + state) * DEG , SLOW);
  delay(SLOW * 10);

//もし三方向とも最大距離を示した場合はSEARCH MODE に戻す
  if ((dist[0] > MAX_RANGE) && (dist[1] > MAX_RANGE) && (dist[2] > MAX_RANGE)) return -1;

  return state;
}
