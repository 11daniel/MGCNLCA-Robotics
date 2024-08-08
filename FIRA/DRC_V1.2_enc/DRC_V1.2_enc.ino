#include <TimerOne.h>
#include "PinChangeInterrupt.h"

//for robot using tracks

//****encoder pin assignments
#define optoR A15
#define optoL 11

//****motor pin assignments
#define OUT1A 25     //left track
#define OUT2A 24
#define EN1A  12

#define OUT3A 22    //right track
#define OUT4A 23
#define EN2A  13

//****move commands for moveMotor function
char F='F'; //move forward command
char L='L'; //turn left command
char R='R'; //turn right command
char B='B'; //move backward command
char S='S'; //stop command

//****GPIO assignments for the ultrasonic sensors
int trigPin[6]={0,48,52,50,20,23}; // int array to set which pins to use
int echoPin[6]={0,47,51,49,21,22}; // for the ultrasonic sensors 
            //={unused,frontUS,frontRUS,frontLUS,backRUS,backLUS}  
int frontUS = 1;  //front sensor
int frontLUS = 2; //front left sensor
int frontRUS = 3; //front right sensor
int backLUS = 4;  //back left sensor
int backRUS = 5;  //back right sensor

//****moveButton pin assignment
int moveButton = 21;

//****ultrasonic min distance
int minDistance = 10; //value to change for sensor minimum distance

//****encoder variables
unsigned int encoderCountR,encoderCountL;
//****timer interrupt variables
unsigned int clockCount;

void setup() {
  //motor pin configurations
  pinMode(OUT1A,OUTPUT);  //
  pinMode(OUT2A,OUTPUT);
  pinMode(EN1A,OUTPUT);
  pinMode(OUT3A,OUTPUT);  //
  pinMode(OUT4A,OUTPUT);
  pinMode(EN2A,OUTPUT);
  //pin change interrupt for encoders
  pinMode(optoR, INPUT_PULLUP);
  pinMode(optoL, INPUT_PULLUP);
  //Serial Monitor enable for debugging
//  Serial.begin(9600);
  //moveButton pinmode
  pinMode(moveButton,INPUT_PULLUP); //enable input pullups for move button (default unpressed state is HIGH);

  //enable interrupts
  Timer1.initialize(100000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( timerIsr ); // attach the service routine here

  attachPCINT(digitalPinToPCINT(optoR), encoderISRright, CHANGE);
  attachPCINT(digitalPinToPCINT(optoL), encoderISRleft, CHANGE);
  }

void moveMotor(char motorDirection, int motorSpeedR, int motorSpeedL){  //port manipulation would work better here

  if (motorDirection=='F'){   //move forward
    digitalWrite(OUT1A,LOW);
    digitalWrite(OUT2A,HIGH);    
    analogWrite(EN1A,motorSpeedR);
    digitalWrite(OUT3A,HIGH);
    digitalWrite(OUT4A,LOW);    
    analogWrite(EN2A,motorSpeedL);
  }
  
  if (motorDirection=='R'){ //rotate right
    digitalWrite(OUT1A,LOW);
    digitalWrite(OUT2A,HIGH);    
    analogWrite(EN1A,motorSpeedR);
    digitalWrite(OUT3A,LOW);
    digitalWrite(OUT4A,HIGH);    
    analogWrite(EN2A,motorSpeedL);
  }
  
  if (motorDirection=='L'){  
    digitalWrite(OUT1A,HIGH);
    digitalWrite(OUT2A,LOW);    
    analogWrite(EN1A,motorSpeedR);
    digitalWrite(OUT3A,HIGH);
    digitalWrite(OUT4A,LOW);    
    analogWrite(EN2A,motorSpeedL);
  }
  
  if (motorDirection=='B'){   
    digitalWrite(OUT1A,HIGH);
    digitalWrite(OUT2A,LOW);    
    analogWrite(EN1A,motorSpeedR);
    digitalWrite(OUT3A,LOW);
    digitalWrite(OUT4A,HIGH);    
    analogWrite(EN2A,motorSpeedL);
  }

  if (motorDirection=='S'){   
    digitalWrite(OUT1A,HIGH);
    digitalWrite(OUT2A,HIGH);    
    analogWrite(EN1A,motorSpeedR);
    digitalWrite(OUT3A,HIGH);
    digitalWrite(OUT4A,HIGH);    
    analogWrite(EN2A,motorSpeedL);
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

  // convert the time into a distance
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.

  cm = duration / 29 / 2;
  return cm;
}

void timerIsr(){  //timer interrupt service routine
  clockCount++; //.1ms increment interval
}

void encoderISRleft(void) { //interrupt on change service routine
  if (digitalRead(optoL)==HIGH) encoderCountL++;
}
void encoderISRright(void) { //interrupt on change service routine
  if (digitalRead(optoR)==HIGH) encoderCountR++;
}


void loop() { //main program loop

  moveMotor(R,255,255); //default temporary movement
  encoderCountL=0;
  while(encoderCountL<12){ //GPIO reading using interrupts
//  Serial.println("Right Encoder: " + String(encoderCountR) + " , Left Encoder: " + String(encoderCountL)); //for debugging purposes
      delay(1);
  } 
  moveMotor(L,255,255); //default temporary movement
  delay(10);             
  moveMotor(S,255,255);
  clockCount=0;
  while(clockCount<50){  //5s delay using interrupts
    Serial.println("Locked");    
  }
  

//  int val1 = pingCheck(frontUS);  //distance reading from sensor 1 in this case the front sensor
//  int val2 = pingCheck(frontRUS);  //distance reading from sensor 2
//  int val3 = pingCheck(frontLUS);  //distance reading from sensor 3
//  int val4 = pingCheck(backRUS);  //distance reading from sensor 4
//  int val5 = pingCheck(backLUS);  //distance reading from sensor 5
//
//  Serial.println("Sensor1: " + String(val1) + " Sensor2: "+ String(val2) + " Sensor3: " + String(val3) + " Sensor4: " + String(val4)+ " Sensor5: " + String(val5)); //for debugging purposes

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

//****navigate walls using 2 ultrasonic / obstacle avoidance sensors (back-right and back-left) readings

//****balance ultrasonic readings for left or right with slight motor movement adjustments

}
