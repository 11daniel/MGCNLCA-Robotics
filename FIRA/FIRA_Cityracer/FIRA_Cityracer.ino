#include <ATX2.h>	
int Ref=600;
int left3,left2,right1,right0;
int Cnt=0;
void setup() {
  XIO();	
  OK();
  motor(1,45);
  motor(2,45);
  motor(3,45);
  motor(4,45);
  delay(2000);
}

void loop() {
while(Cnt=15){
  left3=analogRead(3);
  left2=analogRead(2);
  right1=analogRead(1);
  right0=analogRead(0);
  
    if ((left2<Ref) && (right1<Ref)){
      Cross;
      }
    else if ((left2>Ref) && (right1>Ref)){
      motor(1,45);
      motor(2,45);
      motor(3,45);
      motor(4,45);
    }
    else if (left2<Ref){ //spin left
      motor(1,40);
      motor(3,40);
      motor(2,-40);
      motor(4,-40);
      delay(40);
    }
    else if (right1<Ref){ // spin right
      motor(1,-40);
      motor(3,-40);
      motor(2,40);
      motor(4,40);
      delay(40);
    }
  }
}

void Cross() { 
  Cnt++;
  if (Cnt==1){
    Left90;
    }
  else if (Cnt==2){ 
    Right90;
    }
  /*else if (Cnt==3){
    Left90;
    }
  else if (Cnt==4){
    
    }
  else if (Cnt==6){
    ao();
    motor(1,-70);
    motor(2,-70);
    motor(3,70);
    motor(4,70);
    delay(700);
    motor(1,70);
    motor(2,70);
    motor(3,70);
    motor(4,70);
    delay(300);
    }
   else if (Cnt==7){
    Right90;
    }
   else if (Cnt==8){
    motor(1,70);
    motor(2,70);
    motor(3,70);
    motor(4,70);
    delay(300);
    }
   else if (Cnt==9){
    Right90;
    }
   else if (Cnt==10){
    motor(1,70);
    motor(2,70);
    motor(3,70);
    motor(4,70);
    delay(300);
    ao();
    motor(1,-70);
    motor(2,-70);
    motor(3,70);
    motor(4,70);
    delay(600);
   }
   else if (Cnt==11){
    motor(1,70);
    motor(2,70);
    motor(3,70);
    motor(4,70);
    delay(300);
    }
   else if (Cnt==12){
   ao();
   motor(5,50);
   motor(6,50);
   delay(200);
   }
   else if (Cnt==15){
    ao();
    }*/
  }

void Right90(){
  motor(1,50);
  motor(2,50);
  motor(3,50);
  motor(4,50);
  delay(250);
  ao();
  motor(2,50);
  motor(4,50);
  motor(1,-50);
  motor(3,-50);
  delay(640);
  }

void Left90(){
  motor(1,70);
  motor(2,70);
  motor(3,70);
  motor(4,70);
  delay(250);
  ao();
  motor(2,-70);
  motor(4,-70);
  motor(3,70);
  motor(1,70);
  delay(640);
  }
