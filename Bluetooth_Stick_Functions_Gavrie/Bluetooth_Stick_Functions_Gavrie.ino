#include <ATX2.h>
byte x;
Servo servo1;
void setup()
{
  OK();
  servo1.attach(13);
  pinMode(2,INPUT_PULLUP);
  //servo(2,35);
  servo1.write(75);  // Gripper set Home position
}
void Grab()
{
  //servo(2,160); delay(200);  // Arm Down
  for(int i = servo1.read() ; i < 75 ; i++)
  {
    servo1.write(i);
    delay(10);
  }  // Hand Grab
  // servo(2.35);
  //delay(200);  // Arm Up
}
void Release()  //Release gripper function
{
  //servo(2,160); delay(200); // Arm Down
  for(int i = servo1.read() ; i > 40 ; i--)
  {
    servo1.write(i);
    delay(10);
  }  // Hand Grab  //Hand Release
  //servo(2,35);  delay(200);  // Arm Up
}
void loop()
{
  if(uart1_available())  // Get the serial command from UART1
  {
    x=uart1_getkey();  // Serial command from BlueStick
    if(x==0x38)
    {
      motor(1,100);
      motor(2,100);
      motor(3,100);
      motor(4,100);
    }
    else if(x==0x32){motor(1,-100);motor(2,-100);motor(3,-100);motor(4,-100);}  // Ox32 is backward moving command
    else if(x==0x34){motor(1,100);motor(2,-100);motor(3,-100);motor(4,100);}  // 0x34 is right spinning command
    else if(x==0x36){motor(1,-100);motor(2,100);motor(3,100);motor(4,-100);}  // 0x36 is left spinning command
    else if(x==0x43){Grab();}  // 0x43 is grab command
    else if(x==0x44){Release();}  // 0x44 is release gripper command
    else if(x==0x45){motor(1,100);motor(3,100);}  // 0x45 is right turn command
    else if(x==0x46){motor(2,100);motor(2,100);}  // 0x46 is leftt turn command
    else{ao();}  // Off all motors to stop movement
  }
}

