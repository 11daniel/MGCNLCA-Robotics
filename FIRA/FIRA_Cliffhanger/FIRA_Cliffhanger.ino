#include<ipst.h>

void setup() {
  OK();
  delay(5000);
}

void loop() {

  motor(1,100);
  motor(2,90);

if(analogRead(0) > 200){ //sees white line
  motor(1,100);
  motor(2,90);
  delay(1000);
}
  
if(analogRead(1) < 150){ //sees white line
  motor(1,-100);
  motor(2,-90);
  delay(900);
  motor(1,-100);
  motor(2,90);
  delay(1000);
  }
  
  if(analogRead(2) < 900){ //sees white/silver line
  motor(1,-100);
  motor(2,-90);
  delay(900);
  motor(1,-100);
  motor(2,90);
  delay(1000);
  }

  if(analogRead(3) < 900){ //sees white line
  motor(1,-100);
  motor(2,-90);
  delay(900);
  motor(1,100);
  motor(2,-90);
  delay(1000);
  }
}
