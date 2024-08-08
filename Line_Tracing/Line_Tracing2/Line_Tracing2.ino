#include <popx2.h >
/*#include <L29x.h>
L29x motor1(3,2,4);
L29x motor2(6,5,7);*/
int left1,right1;
int Cnt=0;

void setup() {
  // put your setup code here, to run once:
  //pinMode(10,"INPUT");
  //pinMode(11,"INPUT");
}

void loop() {
  // put your main code here, to run repeatedly:
  //while(Cnt<8){
  left1=digitalRead(24);
  right1=digitalRead(26);

  if ((left1 == 0) && (right1 == 0)){ // sensors detect black
  //Cross();
  ao();
  delay(200);
  }
 
  else if ((left1 == 1) && (right1 == 1)) { // sensors detect white
  fd(50);
  delay(100);
  }
  
  else if(right1 == 0){
  motor(1,-70);
  motor(2,70);
  delay(10);
  }
  else if(left1 == 0){
  motor(1,70);
  motor(2,-70);
  delay(10);
  }
 //}
}

/*void Cross(){
  Cnt++;
  if(Cnt==8){
  motor1.stop();
  motor2.stop();
  }
  else if(Cnt==1){
  Left90();
  }
  else if(Cnt==2){
  Left90();
  }
  else if(Cnt==3){
  Right90();
  }
  else if(Cnt==4){
  Right90();
  }
  else if(Cnt==5){
  Right90();
  }
  else if(Cnt==6){
  Right90();
  }
  else if(Cnt==7){
  Left90();
  }
}*/
  
void Right90(){
  /*motor1.rotPos(70);
  motor2.rotPos(70);
  delay(100);*/
  ao();
  motor(1,-70);
  motor(2,70);
  delay(400);
  ao();
  //while(digitalRead(10) == 0);
  delay(500);
}


void Left90(){
  /*motor1.rotPos(127);
  motor2.rotPos(127);
  delay(100);*/
  ao();
  motor(1,50);
  motor(2,-50);
  delay(300);
  ao();
  //while(digitalRead(11) == 0);
  delay(500);
}
