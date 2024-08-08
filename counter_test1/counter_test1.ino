#include <ATX2.h>	// ATX2 Board
int x; 
void setup() {
  XIO();	// ATX2 initialize
  OK();
}

void loop() {
degrees90L();
degrees90R();
degrees180();
}
void degrees90L(){
  if (x>=10)x=0;
  sl(30); // spin L
   while(x < 10 ) {     // 36=1 full rotation
    if(digitalRead(28)==HIGH) {   //90 deg turn
    x++;
   while(digitalRead(28)==HIGH) { // do nothing & wait
      //debounce
       }   
      Serial.println(x); 
    }
  }
  ao(); // stop
  //motor2.stop();
  delay(1000);

}
void degrees90R(){
  if (x>=10)x=0;
  sr(30); // spin R
   while(x < 10 ) {                 // 36=1 full rotation
    if(digitalRead(29)==HIGH) {   //90 deg turn
    x++;
   while(digitalRead(29)==HIGH) { // do nothing & wait
      //debounce
       }   
      Serial.println(x); 
    }
  }
  ao(); // stop
  //motor2.stop();
  delay(2000);
}
void degrees180(){
  if (x>=29)x=0;
  sl(30); // spin L
   while(x < 29 ) {               // 36=1 full rotation
    if(digitalRead(28)==HIGH) {   //90 deg turn
    x++;
   while(digitalRead(28)==HIGH) { // do nothing & wait
      //debounce
       }   
      Serial.println(x); 
    }
  }
  ao(); // stop
  //motor2.stop();
  delay(2000);
}
   
