#include<ATX2.h>
void setup() {
  Serial.begin(9600);
}

void loop() {
Serial.print("test");
Serial.print("");
Serial.print(analogRead(2));
Serial.print("");
Serial.println();
}
