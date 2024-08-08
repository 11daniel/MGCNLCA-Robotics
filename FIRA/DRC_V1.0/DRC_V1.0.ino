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
//****
//****ultrasonic sensor pin assignments

#define trigPinA 48 //ultrasonic sensor 1 GPIO
#define echoPinA 47
#define trigPinB 52 //ultrasonic sensor 2 GPIO
#define echoPinB 51
#define trigPinC 50 //ultrasonic sensor 3 GPIO
#define echoPinC 49
#define trigPinD 48 //ultrasonic sensor 4 GPIO
#define echoPinD 47
#define trigPinE 48 //ultrasonic sensor 5 GPIO
#define echoPinE 47

//****
char F='F'; //move forward command
char L='L'; //turn left command
char R='R'; //turn right command
char B='B'; //move backward command
char S='S'; //stop command

//{not used,1st sensor trigpin,2nd sensor, etc.., 5th sensor trigpin} 
int trigPin[6]={0,48,52,50,48,48}; // int array to set which pins to use
int echoPin[6]={0,47,51,49,47,47}; // for the ultrasonic sensors 
                                   // e.g.
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
  //ultrasonic pin configurations
//  pinMode(trigPinA, OUTPUT);
//  pinMode(echoPinA, INPUT);
//  pinMode(trigPinB, OUTPUT);
//  pinMode(echoPinB, INPUT);
//  pinMode(trigPinC, OUTPUT);
//  pinMode(echoPinC, INPUT);
//  pinMode(trigPinD, OUTPUT);
//  pinMode(echoPinD, INPUT);
//  pinMode(trigPinE, OUTPUT);
//  pinMode(echoPinE, INPUT);
  //Serial Monitor enable for debugging
  Serial.begin(9600);
  }

void moveMotor(char motorDirection, int motorSpeedR, int motorSpeedL){

  if (motorDirection=='F'){
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
  
  if (motorDirection=='R'){
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
  cm = microsecondsToCentimeters(duration);

  //printing the current readings to ther serial display
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  return cm;
}

long microsecondsToCentimeters(long microseconds)

{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void loop() { //main program loop

  moveMotor(F,255,255); //default temporary movement

  int val1 = pingCheck(1);  //distance reading from sensor 1 in this case the front sensor
  int val2 = pingCheck(2);  //distance reading from sensor 2
  int val3 = pingCheck(3);  //distance reading from sensor 3
//  int val4 = pingCheck(4);  //distance reading from sensor 4
//  int val5 = pingCheck(5);  //distance reading from sensor 5

  Serial.println("Sensor1: " + String(val1) + " Sensor2: "+ String(val2) + " Sensor3: " + String(val3));
  
    if (val1<=5){ //movement for sensor 1 condition only we need 3-5 sensors for finer movement
      moveMotor(R,255,255);
      delay(550); //for 30rpm motor with wheel circumference of 188mm
                  //with fine tuning this is for N20 dc motors only
                  //you can calculate distance travelled based on rpm
                  //using the wheel circumference and time
    }
}

