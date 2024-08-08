#include<ATX2.h>
void setup() {
  OK();
  delay(5000);
}

void loop() {
  motor(1, 100);
  motor(2, 100);
  motor(3, 100);
  motor(4, 100);

  if (analogRead(6) >= (200)) { //distance sensor
    motor(1, 100);
    motor(2, 100);
    motor(3, 100);
    motor(4, 100);
    delay(250);
  }
  else if (analogRead(1) >= (900)) { // Left IR sensor
    motor(1, -100);
    motor(2, -100);
    motor(3, -100);
    motor(4, -100);
    delay(500);
    motor(1, 100);
    motor(2, 100);
    motor(3, -100);
    motor(4, -100);
    delay(750);
  }
  else if (analogRead(2) >= (900)) { //Right IR sensor
    motor(1, -100);
    motor(2, -100);
    motor(3, -100);
    motor(4, -100);
    delay(500);
    motor(1, -100);
    motor(2, -100);
    motor(3, 100);
    motor(4, 100);
    delay(750);
  }
}
