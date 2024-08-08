#include<Servo.h>
#define trigPin 13
#define echoPin 12
#define led 11
Servo servo1;
Servo servo2;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(10);
  servo2.attach(8);

  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance < 150) {
    {
      //digitalWrite(led, HIGH);
      servo2.write(90);
      servo1.write(90);
      delay(500);
      servo1.write(0);
      delay(500);
    }
    //servo2.write(90);
    delay(1000);
  }
  else {
    //digitalWrite(led, LOW);
    servo1.write(0);
    servo2.write(0);
    //delay(10000);
  }
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
