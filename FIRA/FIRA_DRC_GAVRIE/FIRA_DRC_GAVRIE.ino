#include <L29x.h>	
L29x motor1 (3,2,4);
L29x motor2 (6,5,7);

//****move commands for moveMotor function
char F='F'; //move forward command
char L='L'; //turn left command
char R='R'; //turn right command
char B='B'; //move backward command
char S='S'; //stop command

int trigPin[6] = {0,25,8,33,41,45};
int echoPin[6] = {0,24,9,32,40,44};

int frontUS = 1;
int frontRUS = 2;
int frontLUS = 3;
int backRUS = 4;
int backLUS = 5;

int minDistance = 10; //value to change for sensor minimum distance

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
  
  moveMotor(F); //default temp

  int val1 = pingCheck(frontUS);  //distance reading from sensor 1 in this case the front sensor
  int val2 = pingCheck(frontRUS);  //distance reading from sensor 2
  int val3 = pingCheck(frontLUS);  //distance reading from sensor 3
  int val4 = pingCheck(backRUS);  //distance reading from sensor 4
  int val5 = pingCheck(backLUS);  //distance reading from sensor 5

  Serial.println("Sensor1: " + String(val1) + " Sensor2: "+ String(val2) + " Sensor3: " + String(val3) + " Sensor4: " + String(val4) + " Sensor5: " + String(val5)); //for debugging purposes

//  Nested IF statements for prioritization of ultrasonic sensor reading conditions. 
//  There are 8 possible sensor reading combinations. For each combination we should prepare a default action for navigation.
//  This is not final.
//  1 - front sensor only detects wall/obstruction (go straight)  implemented
//  2 - front and front-right sensor detects wall/obstruction (turn left) implemented
//  3 - front and front-left sensor detects wall/obstruction (turn right) implemented
//  4 - front-right sensor only detects wall/obstruction (follow right wall)
//  5 - front-left sensor only detects wall/obstruction (follow left wall)
//  6 - no walls are detected (move forward blindly until wall/obstruction is detected) implemented
//  7 - all three sensors detects wall (reverse)
//  8 - front-right and front-left sensors detect wall/obstruction (?)

  
    if(val1<=minDistance && val2<=minDistance && val3>minDistance){ //110 front and front right sensor detects wall (rotate left)       
      moveMotor(L);
      delay(1100); //delay for N20 90 deg turn (slot optocouplers/trackball mouse sensors would work better here)
      moveMotor(S);
    }
    
   else if(val1<=minDistance && val2>minDistance && val3<=minDistance){ //101 front and front left sensor detects wall  (rotate right)
        moveMotor(R);
        delay(1100); //delay for N20 90 deg turn (slot optocouplers/trackball mouse sensors would work better here)
        moveMotor(S);
    }

    else if (val1<=minDistance && val2>minDistance && val3>minDistance){ // follow left wall
      moveMotor(L);
      delay(1100);
      moveMotor(S);
      }
     
     /*else if (val1>minDistance && val2>minDistance && val3>minDistance){ //  000  no detections (go straight)
     moveMotor(F);
     delay(600);
     }

     /*else if (val1<=minDistance && val2<=minDistance && val3<=minDistance){//frontRUS & backRUS follow right wall
      moveMotor(B);
      delay(600);
      }*/


//****navigate walls using 2 ultrasonic / obstacle avoidance sensors (back-right and back-left) readings

//****balance ultrasonic readings for left or right with slight motor movement adjustments
}
