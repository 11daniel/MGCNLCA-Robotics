/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.
                                                        
  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/
#include<Servo.h>
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
Servo servo;
int posF = 180;
int posA = 0;
long tF = 720;
long tA = 0;
int tDelay = 0;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  servo.attach(9);

  pinMode(9, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  //  tF = tF * 1000;
  tDelay = tF/posF;
  servo.write(posA);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:    
  /*if (posA != posF && tA <= tF) {
    mueveServo();
  }*/
  if (analogRead(2) <= (50)){
  servo.write(0);
  delay(1000);
  servo.write(180);
  delay(20000);
  servo.write(0);
  delay(1000);
  servo.write(180);
  }
  /*else if (analogRead(2) >= (200)){
  servo.write(0);
  delay(1000);
  servo.write(180);
  delay(10000);
  servo.write(0);
  delay(1000);
  servo.write(180);
  }*/
  
  if (buttonState == HIGH) {
    // turn LED on:
    servo.write(180);
  }
  else {
    // turn LED off:
    servo.write(0);
  }
}
void mueveServo() {
  servo.write(posA);
  posA = posA + 1;
  delay(tDelay);
  tA = tA + tDelay;
  Serial.print(posA); Serial.print("   "); Serial.println(tA);
}
