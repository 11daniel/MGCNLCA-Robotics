#include<L29x.h>
L29x motor1 (3,2,4);
L29x motor2 (6,5,7);

int Ref=15;
int FUS,FRUS,FLUS,BRUS,BLUS;
int Cnt=0;
char F='F'; //move forward command
char L='L'; //turn left command
char R='R'; //turn right command
char B='B'; //move backward command
char S='S'; //stop command

int trigPin[6] = {0,25,8,33,41,45};
int echoPin[6] = {0,24,9,32,40,44};

int frontUS = 1; //front sensor
int frontRUS = 2; //front right sensor
int frontLUS = 3; //front left sensor
int backRUS = 4; //back right sensor
int backLUS = 5; //back left sensor

void setup() {
  Serial.begin(9600);
}

void moveMotor(char motorDirection){  //port manipulation would work better here

  if (motorDirection=='F'){   //move forward
    motor1.rotPos(255); // fastest speed in one direction
    motor2.rotPos(255);    
  }
  
  if (motorDirection=='R'){ //rotate right
    motor1.rotNeg(255); // fastest speed in one direction
    motor2.rotPos(255);
  }
  
  if (motorDirection=='L'){ 
    motor1.rotPos(255); 
    motor2.rotNeg(255);
  }
  
  if (motorDirection=='B'){   
    motor1.rotNeg(255); // fastest speed in one direction
    motor2.rotNeg(255);
  }

  if (motorDirection=='S'){   
    motor1.stop();
    motor2.stop();
  }
  
}

long pingCheck(int x){ //routine to get the distance from the ultrasonic sensor

  long cm, duration;

  pinMode(trigPin[x], OUTPUT);
  pinMode(echoPin[x], INPUT);

  //sending the signal, starting with LOW for a clean signal
  digitalWrite(trigPin[x], LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin[x], HIGH);
  delayMicroseconds(5);
  digitalWrite(echoPin[x], LOW);

  duration = pulseIn(echoPin[x], HIGH);

  cm = duration / 29 / 2;
  return cm;
}

void loop() {
//while(Cnt>){
  if((FUS<=Ref) && (FRUS<=Ref) || (FUS<=Ref) && (FLUS<=Ref)){
    //Cross;
    moveMotor(S);
    }

  else if ((FUS>=Ref) && (FRUS>=Ref) && (FLUS<=Ref)){
    moveMotor(F);
    }

  else if  ((FRUS>=Ref) && (BRUS>=Ref)){
    moveMotor(S);
    delay(400);
    moveMotor(R);
    delay(300);
    moveMotor(S);
    }
    
   else if  ((FLUS>=Ref) && (BLUS>=Ref)){
    moveMotor(S);
    delay(400);
    moveMotor(L);
    delay(300);
    moveMotor(S);
    } 
  }
