#include <ATX2.h>  // ATX2 Board
int left1,right1,FFRight,FFLeft;
int Cnt=0;
int x = 0;

void setup() 
{
  OK();
}

void loop() {
 while(Cnt<30){ // idk value
  left1=digitalRead(25);
  right1=digitalRead(24);
  FFLeft=analogRead(2);
  FFRight=analogRead(3);
   if ((left1==1) && (right1==1)){ //both detect black 
    Cross();
    ao();
    //beep(19);
    }
   else if ((left1==0) && (right1==0)){ // both detect white
    motor(1,30);
    motor(2,30);
    }
    else if (right1==1){ // detect black
    motor(1,30);
    motor(2,-30);
    ao();
  }
  else if (left1==1){ // detect black
    motor(1,-30);
    motor(2,30);
    ao();
  }
 }
}

void Cross(){
  Cnt++;
  if (Cnt==30){
    ao();
  }
  else if (Cnt==1 || Cnt==2 || Cnt==7 || Cnt==8){
    beep();
    ao();
    motor(1,50);
    motor(2,50);
    delay(70);
    Left90();
    motor(1,30);
    motor(2,30);
    delay(500);
  }
  else if(Cnt==3 || Cnt==5 || Cnt==10){
  beep();
  motor(1,20);
  motor(2,20);
  delay(300);
  ao();
  FSLB();
  FSRB();
  motor(1,-30);
  motor(2,-30);
  motor(1,30);
  motor(2,-30);
  delay(1800);
  ao();
  delay(300);
  motor(1,30);
  motor(2,30);
  }
  else if (Cnt==4 || Cnt==15 || Cnt==25) {
    beep();
    ao();
    motor(1,30);
    motor(2,30);
    delay(70);
    Left90();
    motor(1,30);
    motor(2,30);
    delay(260);
  }
else if (Cnt==6 || Cnt==19 || Cnt==24){
 beep();
 ao();
 motor(1,30);
 motor(2,30);
 delay(500);
}
else if (Cnt==9 || Cnt==11 || Cnt==13 || Cnt==23 || Cnt==25 || Cnt==27 || Cnt==28){
  beep();
  ao();
  motor(1,30);
  motor(2,30);
  delay(50);
  Right90();
  motor(1,30);
  motor(2,30);
  delay(550);
  }
else if (Cnt==12){
 beep();
 ao();
 FSLB();
 motor(1,30);
 motor(2,30);
 delay(500);
}
else if (Cnt==14){
  beep();
  ao();
  motor(1,30);
  motor(2,30);
  delay(50);
  Right90();
  ao();
  FSLB();
  motor(1,30);
  motor(2,30);
  delay(550);
  }
else if (Cnt==16 || Cnt==18){
  beep();
  ao();
  motor(1,30);
  motor(2,30);
  delay(50);
  Right90();
  motor(1,30);
  motor(2,30);
  delay(550);
  }
else if(Cnt==17 || Cnt==21){
   beep();
   ao();
   delay(300);
   motor(1,-30);
   motor(2,-30);
   motor(1,-30);
   motor(2,30);
   delay(1800);
   ao();
   delay(300);
  }
else if (Cnt==20 || Cnt== 22){
  beep();
  ao();
  motor(1,30);
  motor(2,30);
  delay(50);
  Right90();
  motor(1,30);
  motor(2,30);
  delay(500);
 }
 else if (Cnt==26){
  beep();
  ao();
  motor(1,30);
  motor(2,30);
  delay(50);
  ao();
  FSLB();
  Right90();
  motor(1,30);
  motor(2,30);
  delay(500);
 }
 else if (Cnt==29){
  beep();
  ao();
  FSLB();
 }
}

void Right90(){
  motor(1,10);
  motor(2,10);
  delay(700);
  ao();
  motor(1,25);
  motor(2,-25);
  delay(900);
  //ao();
  while(digitalRead(24) == 0);
  delay(100);
}

void Left90(){
  motor(1,10);
  motor(2,10);
  delay(700);
  ao();
  delay(500);
  motor(1,-25);
  motor(2,25);
  delay(860);
  //ao();
  while(digitalRead(25) == 0);
  delay(100);
}
void FSRB(){
 if(FFRight<500){
 out(31,1);
 delay(1000);
 out(31,0);
 delay(1000);
 }
}
 void FSLB(){
 if(FFLeft<500){
 out(30,1);
 delay(1000);
 out(30,0);
 delay(1000);
 }
}
/*void degrees90L(){
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
  if (x>=29)
  {x=0;}
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
}*/
