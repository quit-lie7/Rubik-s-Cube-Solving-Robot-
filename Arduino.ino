#include <Servo.h>

Servo rot;
Servo push;

// Углы вращения
int rotLeft  = 0;
int rotMid   = 90;
int rotRight = 180;

// Углы толкателя (твои)
int pushRest = 62;
int pushHold = 110;
int pushPush = 146;

char moves[] = {'R','L','U','D','F'};
int moveCount = 5;

void setup() {
  rot.attach(10);
  push.attach(9);

  push.write(pushRest);
  rot.write(rotMid);

  randomSeed(analogRead(A0)); // генерация случайности
}

void loop() {

  char m = moves[random(moveCount)];

  doMove(m);

  delay(1500); // пауза между ходами
}

void doMove(char m) {

  // Захват
  push.write(pushHold);
  delay(1000);

  // Толчок
  push.write(pushPush);
  delay(1000);

  // Вращение
  rot.write(rotRight);
  delay(1000);

  // Отпуск
  push.write(pushRest);
  delay(1000);

  // Возврат
  rot.write(rotMid);
  delay(1000);
}