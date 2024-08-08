//****motor pin assignments
#define OUT1A 35     //front right
#define OUT2A 36
#define EN1A  5

#define OUT1B 41      //back  right
#define OUT2B 42
#define EN1B  3

#define OUT3A 37    //front left
#define OUT4A 38
#define EN2A  4

#define OUT3B 43     //back left
#define OUT4B 44
#define EN2B  2

//****move commands for moveMotor function
char F='F'; //move forward command
char L='L'; //turn left command
char R='R'; //turn right command
char B='B'; //move backward command
char S='S'; //stop command

//****GPIO assignments for the ultrasonic sensors
int trigPin[6]={0,48,52,50,48,48}; // int array to set which pins to use
int echoPin[6]={0,47,51,49,47,47}; // for the ultrasonic sensors 
            //={unused,frontUS,frontRUS,frontLUS,backRUS,backLUS}  
int frontUS = 1;  //front sensor
int frontLUS = 2; //front left sensor
int frontRUS = 3; //front right sensor
int backLUS = 4;  //back left sensor
int backRUS = 5;  //back right sensor

//****moveButton pin assignment
int moveButton = 9;

//****ultrasonic min distance
int minDistance = 10; //value to change for sensor minimum distance

void setup() {
  //motor pin configurations
  pinMode(OUT1A,OUTPUT);  //
  pinMode(OUT2A,OUTPUT);
  pinMode(EN1A,OUTPUT);
  pinMode(OUT3A,OUTPUT);  //
  pinMode(OUT4A,OUTPUT);
  pinMode(EN2A,OUTPUT);
  pinMode(OUT1B,OUTPUT);  //
  pinMode(OUT2B,OUTPUT);
  pinMode(EN1B,OUTPUT);  
  pinMode(OUT3B,OUTPUT);  //
  pinMode(OUT4B,OUTPUT);
  pinMode(EN2B,OUTPUT);
  //Serial Monitor enable for debugging
  Serial.begin(9600);
  //moveButton pinmode
  pinMode(moveButton,INPUT_PULLUP); //enable input pullups for move button (default unpressed state is HIGH);
  }

void moveMotor(char motorDirection, int motorSpeedR, int motorSpeedL){  //port manipulation would work better here

  if (motorDirection=='F'){   //move forward
    digitalWrite(OUT1A,HIGH);
    digitalWrite(OUT2A,LOW);    
    analogWrite(EN1A,motorSpeedR);
    digitalWrite(OUT1B,HIGH);
    digitalWrite(OUT2B,LOW);    
    analogWrite(EN1B,motorSpeedR);

    digitalWrite(OUT3A,HIGH);
    digitalWrite(OUT4A,LOW);    
    analogWrite(EN2A,motorSpeedL);
    digitalWrite(OUT3B,HIGH);
    digitalWrite(OUT4B,LOW);    
    analogWrite(EN2B,motorSpeedL);
  }
  
  if (motorDirection=='R'){ //rotate right
    digitalWrite(OUT1A,LOW);
    digitalWrite(OUT2A,HIGH);    
    analogWrite(EN1A,motorSpeedR);
    digitalWrite(OUT1B,LOW);
    digitalWrite(OUT2B,HIGH);    
    analogWrite(EN1B,motorSpeedR);

    digitalWrite(OUT3A,HIGH);
    digitalWrite(OUT4A,LOW);    
    analogWrite(EN2A,motorSpeedL);
    digitalWrite(OUT3B,HIGH);
    digitalWrite(OUT4B,LOW);    
    analogWrite(EN2B,motorSpeedL);  
  }
  
  if (motorDirection=='L'){  
    digitalWrite(OUT1A,HIGH);
    digitalWrite(OUT2A,LOW);    
    analogWrite(EN1A,motorSpeedR);
    digitalWrite(OUT1B,HIGH);
    digitalWrite(OUT2B,LOW);    
    analogWrite(EN1B,motorSpeedR);

    digitalWrite(OUT3A,LOW);
    digitalWrite(OUT4A,HIGH);    
    analogWrite(EN2A,motorSpeedL);
    digitalWrite(OUT3B,LOW);
    digitalWrite(OUT4B,HIGH);    
    analogWrite(EN2B,motorSpeedL);
  }
  
  if (motorDirection=='B'){   
    digitalWrite(OUT1A,LOW);
    digitalWrite(OUT2A,HIGH);    
    analogWrite(EN1A,motorSpeedR);
    digitalWrite(OUT1B,LOW);
    digitalWrite(OUT2B,HIGH);    
    analogWrite(EN1B,motorSpeedR);

    digitalWrite(OUT3A,LOW);
    digitalWrite(OUT4A,HIGH);    
    analogWrite(EN2A,motorSpeedL);
    digitalWrite(OUT3B,LOW);
    digitalWrite(OUT4B,HIGH);    
    analogWrite(EN2B,motorSpeedL);
  }

  if (motorDirection=='S'){   
    digitalWrite(OUT1A,HIGH);
    digitalWrite(OUT2A,HIGH);    
    analogWrite(EN1A,motorSpeedR);
    digitalWrite(OUT1B,HIGH);
    digitalWrite(OUT2B,HIGH);    
    analogWrite(EN1B,motorSpeedR);

    digitalWrite(OUT3A,HIGH);
    digitalWrite(OUT4A,HIGH);    
    analogWrite(EN2A,motorSpeedL);
    digitalWrite(OUT3B,HIGH);
    digitalWrite(OUT4B,HIGH);    
    analogWrite(EN2B,motorSpeedL);
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


void loop() { //main program loop

  moveMotor(F,255,255); //default temporary movement

  int val1 = pingCheck(frontUS);  //distance reading from sensor 1 in this case the front sensor
  int val2 = pingCheck(frontRUS);  //distance reading from sensor 2
  int val3 = pingCheck(frontLUS);  //distance reading from sensor 3
//  int val4 = pingCheck(backRUS);  //distance reading from sensor 4
//  int val5 = pingCheck(backLUS);  //distance reading from sensor 5

//  Serial.println("Sensor1: " + String(val1) + " Sensor2: "+ String(val2) + " Sensor3: " + String(val3)); //for debugging purposes

//  Nested IF statements for prioritization of ultrasonic sensor reading conditions. 
//  There are 8 possible sensor reading combinations. For each combination we should prepare a default action for navigation.
//  This is not final.
//  1 - front sensor only detects wall/obstruction (go straight)
//  2 - front and front-right sensor detects wall/obstruction (turn left)
//  3 - front and front-left sensor detects wall/obstruction (turn right)
//  4 - front-right sensor only detects wall/obstruction (follow right wall)
//  5 - front-left sensor only detects wall/obstruction (follow left wall)
//  6 - no walls are detected (move forward blindly until wall/obstruction is detected)
//  7 - all three sensors detects wall (reverse)
//  8 - front-right and front-left sensors detect wall/obstruction (?)

    if (val1>minDistance && val2>minDistance && val3>minDistance){ //  000  no detections (go straight)
      moveMotor(F,255,255);
    }
      else if (val1<=minDistance && val2>minDistance && val3>minDistance){ // 100 only front sensor detects wall (turn according to 'moveButton')
        switch(digitalRead(moveButton)){
          case(HIGH):
            moveMotor(R,255,255);
            break;
          case(LOW):
            moveMotor(L,255,255);
            break;
        }
        delay(600); //delay for N20 90 deg turn
      }
        else if(val1<=minDistance && val2>minDistance && val3>minDistance){ //110 front and front right sensor detects wall (rotate left)      
          moveMotor(L,255,255);
          delay(600); //delay for N20 90 deg turn (slot optocouplers/trackball mouse sensors would work better here)
        }
          else if(val1<=minDistance && val2>minDistance && val3>minDistance){ //101 front and front left sensor detects wall  (rotate right)
            moveMotor(R,255,255);
            delay(600); //delay for N20 90 deg turn (slot optocouplers/trackball mouse sensors would work better here)
          }
//            else if(){
//            }

}
