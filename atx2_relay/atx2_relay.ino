#include <ATX2.h>
int led1 = 26;

void setup() {
  // put your setup code here, to run once:
  OK();
  pinMode(led1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1, HIGH);
}S
