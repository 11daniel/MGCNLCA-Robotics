#include <ATX2.h>	// ATX2 Board
void setup() {
  XIO();	// ATX2 initialize
  OK();
}

void loop() {
  motor(1, 100);
  motor(2, 75);
}
