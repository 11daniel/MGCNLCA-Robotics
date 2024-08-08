#include <ATX2.h>
  int x = 1;
  int str = 1;
  int ds, ls, rs, ds2;



void setup()
  {
    setTextSize(2);
    glcdMode(1);
    
    while(sw_OK() == LOW)
    {
      if(x == 1)
      {
        x++;
      }
    glcd(4,4,"  ");
    glcd(1,1,"Press OK");
    glcd(2,3,"Strategy 1");
    glcd(3,3,"Strategy 2");
    
    if((knob() <= 400))
    {
      glcd(2,1,">");
      glcd(3,1," ");
      str = 1;
    }
    
    if(knob() > 600)
    {
      glcd(2,1," ");
      glcd(3,1,">");
      str = 2;
    }
    }    
    while (knob() == HIGH) // For auto pressing
    {
      
    }
    

    glcdClear();
    glcd(3,1,"Strategy %d", str);
    delay(4780);//The 5 second delay before starting to move
    beep();
   
    if(str == 1)// STRATEGY 1, THE ACTION BEFORE LOOPING
    {
      fd4(20);
      delay(1);
    }
    
    if(str == 2)// STRATEGY 2, THE ACTION BEFORE LOOPING 2.0
    {
     motor(1,100);
      motor(2,100);
      delay(200);
    }
    
    glcdClear();
  
  }
  
      
void loop()
{
fd4(20);
 if((analogRead(0)) > (700) || (analogRead(2)) > (700))
 {
   Retreat();
   delay(1);
 }
if((digitalRead(25)) == (0))
 {
   Left();
   delay(230);
 }
 if((digitalRead(27)) == (0))
 {
   SRight();
   delay(90);
 }
 if((digitalRead(29)) == (0) || (digitalRead(28)) == (0))
 {
   Kill();
   delay(180);
 }
 if((digitalRead(31)) == (0))
 {
   SLeft();
   delay(90);
 }
 if((digitalRead(30)) == (0))
 {
   Right();
   delay(230);
 }
}

void Kill()
{
  motor(12,100);
}
void Left()
{
   motor(1,-30);
   motor(2,30);
}
void Right()
{
   motor(1,30);
   motor(2,-30);
}
void SRight()
{
   motor(1,30);
   motor(2,-30);
}
void SLeft()
{
   motor(1,-30);
   motor(2,30);
}
void Retreat()
{
   motor(1,-30);
   motor(2,-30);
   delay(400);
   motor(1,-30);
   motor(2,30);
   delay(400);
}
