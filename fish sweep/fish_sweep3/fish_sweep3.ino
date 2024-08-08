#include <IRremote.h>
#define MY_DEBUG 1
#define DEFAULT_DELAY 10
#include <Servo.h> 

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

struct RoboFish
{
  Servo tail;
  int pos;
  
  int pos_0;
  int pos_1;

  int speed;

  void setup(int servo_pin)
  {
    pos = 0;
    speed = 100;
    
    pos_0 = 1;
    pos_1 = 180;

    tail.attach(servo_pin);
  }
  
  
  int set_speed(int _speed=0)
  {
    int res = DEFAULT_DELAY;
    
    if(_speed > 0) {
      res = 1000/_speed;
    }
    
    return res;
  }

  void swim(int _speed=0)
  {
    int del = set_speed(_speed);

// переделываем пример Sweep
    for(pos = pos_0; pos < pos_1; pos++) {
      tail.write(pos);             
      delay(del);
    }
#if MY_DEBUG
      Serial.println("<");
#endif    
    for(pos = pos_1; pos >= pos_0; pos--) {                                
      tail.write(pos);
      delay(del);
    }
#if MY_DEBUG
      Serial.println(">");
#endif    
  }
  
  void forward(int _speed=0)
  {
#if MY_DEBUG
      Serial.println("forward"); // fish goes foward
#endif

    pos_0 = 45;
    pos_1 = 125;
    
    swim(_speed);
  }
  
  void left(int _speed=0)
  {
#if MY_DEBUG
      Serial.println("left");// fish goes left
#endif
    
    pos_0 = 20;
    pos_1 = 60;
    
    swim(_speed);
  }
  
  void right(int _speed=0)
  {
#if MY_DEBUG
      Serial.println("right"); //fish goes right
#endif    
    
    pos_0 = 120;
    pos_1 = 160;
    
    swim(_speed);
  }  
};

RoboFish robot;  

int randnum = 0;
bool leftflag = false;
bool rightflag = false;

void setup() 
{ 
  irrecv.enableIRIn();
  irrecv.blink13(true);
  
#if MY_DEBUG
  Serial.begin(9600);
#endif

  robot.setup(9);
  robot.speed = 100;

  randomSeed(analogRead(0));
} 


void loop() 
{
#if 0  
 robot.left(50);
 delay(100);

 robot.forward(100);
 delay(50);
  
  robot.right(50);
  delay(100);
#endif

#if 0

  robot.pos_0 = 55;//65
  robot.pos_1 = 115;//105
  robot.swim( robot.speed+40 ); 
#endif

/*#if 1
  randnum = random(400);
  if(randnum > 380) {
    
    randnum = random(400);
    if(randnum > 200 && !rightflag)
    {
      leftflag=true;
      robot.left(robot.speed);   
    }
    else
    {
      rightflag=true;
      robot.right(robot.speed);  
    }
  }*/
  if (1){
    leftflag = false;
    rightflag = false;
    //robot.forward( robot.speed );  
    robot.pos_0 = 70;
    robot.pos_1 = 100;
    robot.swim( robot.speed+100 );
  }
  
if (irrecv.decode(&results)){

        switch(results.value){
          case 0xFF10EF: //Keypad button "4"
          robot.left(robot.speed); 
          }

        switch(results.value){
          case 0xFF5AA5: //Keypad button "6"
          robot.right(robot.speed);  
          }

        irrecv.resume(); 
    }
//#endif  
}
