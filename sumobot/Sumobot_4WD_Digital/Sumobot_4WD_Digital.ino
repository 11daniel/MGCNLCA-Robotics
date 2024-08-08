#include<ATX2.h>

void setup() {
  OK();
  delay(5000);
}

void loop() {
  motor(1, 50);
  motor(2, 50);
  motor(3, 50);
  motor(4, 50);

  if (analogRead(2) >= (200)) {
    motor(1, 80);
    motor(2, 80);
    motor(3, 80);
    motor(4, 80);
    delay(250);
  }
  /*else if (analogRead(0) >= (200)){

    motor(1,100);
    motor(2,100);
    motor(3,-100);
    motor(4,-100);
    delay(150);
    }*/
  else if (digitalRead(24) == (1)) {
    motor(1, -50);
    motor(2, -50);
    motor(3, -50);
    motor(4, -50);
    delay(500);
    motor(1, -50);
    motor(2, -50);
    motor(3, 50);
    motor(4, 50);
    delay(750);
  }
  else if (digitalRead(25) == (1)) {
    motor(1, -50);
    motor(2, -50);
    motor(3, -50);
    motor(4, -50);
    delay(500);
    motor(1, 50);
    motor(2, 50);
    motor(3, -50);
    motor(4, -50);
    delay(750);
  }
}
