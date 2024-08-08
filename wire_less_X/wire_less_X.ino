#include <ATX2.h>	// POP-X2 Board
byte x;


void setup() {
 XIO();
}

void loop() {
 while(uart1_ready()>0){
   x=uart1_read();
 }
  if(x==0x01) { bk(80); }
  else if(x==0x02) {
   sl(60); }   // sl
  else if(x==0x04) {
   sr(60); }   // sr
  else if(x==0x08) { 
    fd(80); }   // fd
 else { AO();}  
}

//void home{
 
//}
