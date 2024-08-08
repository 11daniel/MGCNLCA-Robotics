#include <popx2.h>

#define NUMSENSOR   5
#define MAXVALUE    1024

#define Pwm1 6
#define Dir1 5
#define Pwm2 7
#define Dir2 4

#define STOP {  motorControl(0,0); }
int maxValue[5] = {992,992,990,991,992};
int minValue[5] = {150,150,150,139,149};

unsigned int calibratedMinimum[NUMSENSOR];
unsigned int calibratedMaximum[NUMSENSOR];
unsigned int sensorValue[NUMSENSOR];

int sensorPin[NUMSENSOR] = {A0, A1, A2, A3, A4};

int leftPower, rightPower;
int error, last_error;
int PD_Value;
unsigned long LastTime = 0;
bool DIR1, DIR2;
unsigned int Position = 0;

void setup() {
  
  initial();
  sw_OK_press();
  beep();
//  calibrate(200);
 // showValue();
        PDTimer(100,0.3,0.2,3000);
}

void loop() {
// Serial.println(readLine(0,200,50));
 //delay(50);
//     stdPD(200,0.3,0.2);        //(base speed of the motor must be close to line148
       PDTimer(100,0.3,0.2,3000);
}

void initial() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

void readSensor(){
   for(int i = 0; i <5;i++){
    sensorValue[i] = analogRead(sensorPin[i]);
   }
}

void calibrate(int sample){
  int i;
  unsigned int max_sensor_values[8];
  unsigned int min_sensor_values[8];

  for (i = 0; i < NUMSENSOR; i++){
    calibratedMinimum[i] = 0;                //1024
    calibratedMaximum[i] = 1024;                  //0
  }
  for (int runcal = 0; runcal < sample; runcal++){
    int j;
    for (j = 0; j <10; j++){
      readSensor();
      for(i =0; i < NUMSENSOR; i++){
        if(calibratedMinimum[i] > sensorValue[i]) calibratedMinimum[i] = sensorValue[i];
        if(calibratedMaximum[i] < sensorValue[i]) calibratedMaximum[i] = sensorValue[i];
      }
      delay(5);
    }
  }
}

void showValue(){
  glcdClear();
  for(int i = 0; i < 5; i++){
    Serial.print(calibratedMaximum[i]); Serial.print("\t");
    glcd(i,0,"%d    ",calibratedMaximum[i]);
  }
  Serial.print("\n");
  for(int i = 0; i < 5; i++){
    glcd(i,10,"%d    ",calibratedMinimum[i]);
    Serial.print(calibratedMaximum[i]); Serial.print("\t");
  }
}

void readCalibrated(){
  int i;
  readSensor();
  for(i = 0; i < NUMSENSOR; i++){
    unsigned int calmin, calmax;
    unsigned int denominator;
    calmax = maxValue[i];
    calmin = minValue[i];                                              //mAxValue
    denominator = calmax - calmin;
    signed long x;
    x = (((signed long)sensorValue[i]) - calmin) * 1000;
    if (x < 0) x = 0;
    if (denominator !=0) x = x / denominator;
    x = (x > 1000 ? 1000 : x);
    sensorValue[i] = x;
  }
}

int readLine(unsigned char white_line, int keep_track, int noise_threshold) {
  unsigned char i, on_line = 0;
  unsigned long avg,sum;
  static int last_value = 0;
  readCalibrated();
  avg = 0; sum = 0;
  for(i = 0; i < NUMSENSOR; i++){
    int value = sensorValue[i];
    if (!white_line) value = 1000 - value;
    if (value > keep_track) on_line = 1;
    if (value > noise_threshold){
      avg += (long)(value) * (i * 1000);
      sum += value;
    }
  }
  if(!on_line){
    if(last_value < (NUMSENSOR) * 1000 / 2) return 0;
    else return(NUMSENSOR-1) * 1000;
  }
  last_value = avg/sum;
  return last_value;
}
void stdPD(int BaseSpeed, float Kp, float Kd) {
  Position = readLine(0, 200, 50 );        //200,50
  error = Position - 2000;
  PD_Value = (Kp * error) + (Kd * (error - last_error));
  last_error = error;
  if (PD_Value > BaseSpeed) PD_Value = BaseSpeed;
  if (PD_Value < -BaseSpeed) PD_Value = -BaseSpeed;
  leftPower = BaseSpeed + PD_Value;
  rightPower = BaseSpeed - PD_Value;
  if (leftPower >= 255) leftPower = 255;      //250
  if (leftPower <= 0) leftPower = -10;          //20 and -150
  if (rightPower >= 255) rightPower = 255;
  if (rightPower <= 0) rightPower = -10;
  motorControl(leftPower, rightPower);
}

void PDTimer(int BaseSpeed, float Kp, float Kd, unsigned int timer){
  unsigned long startTime;
  startTime = millis();
  while(millis() -startTime <= timer){
    stdPD(BaseSpeed,Kp,Kd);
  }
  motorControl(0,0); 
}
/*
voidPDCross(int BaseSpeed, float Kp, float Kd){
  readLine(0, 200, 50);
  while (sensorValue[0] , 500 | | sensorValue[4] , 500){ 
  }
  motorControl(0,0); 
}
*/
void motorControl(int motorL, int motorR) {
//  if (motorL == 0){                 // its the same as line 61 and 62                            
//    DIR1 = 0;
//  } else {
//    DIR1 = 1;
//  }
  
  DIR1 = (motorL >= 0 ? 0 : 1);                //error = position - setpoint; >>if you want to make it center and the vaalue of center is '2000'
  DIR2 = (motorR >= 0 ? 0 : 1);

  digitalWrite(Dir1, DIR1);
  analogWrite(Pwm1, abs(motorL));

  digitalWrite(Dir2, DIR2);
  analogWrite(Pwm2, abs(motorR));

}
