#include<ATX2.h>
void setup() {
  OK();
  delay(5000);
}

void loop() {
  motor(1, 100);
  motor(2, 100);

  if (analogRead(2) >= (200)) { //left distance sensor
    motor(1, -100);
    motor(2, 100);
    delay(250);
  }
  else if (analogRead(3) >= (200)) { // right distance sensor
    motor(1, 100);
    motor(2, -100);
    delay(250);
  }
  else if (analogRead(0) >= (900)) { // left IR sensor
    motor(1, -100);
    motor(2, -100);
    delay(500);
    motor(1, 100);
    motor(2, -100);
    delay(750);
  }
  else if (analogRead(1) >= (900)) { //right IR sensor
    motor(1, -100);
    motor(2, -100);
    delay(500);
    motor(1, -100);
    motor(2, 100);
    delay(750);
  }
}
