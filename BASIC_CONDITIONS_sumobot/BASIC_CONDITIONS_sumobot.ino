#include<ATX2.h>

int x = 1;
int str = 1;

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
    glcd(4,3,"Strategy 3");
    
    if((knob() < 50))
    {
      glcd(2,1,">");
      glcd(3,1," ");
      glcd(4,1," ");
      str = 1;
    }
    
    if(knob() > 900)
    {
      glcd(2,1," ");
      glcd(3,1,">");
      glcd(4,1," ");
      str = 2;
    }
    
    if ((knob() > 100 )&&( knob() < 800))
    {
      glcd(2,1," ");
      glcd(3,1," ");
      glcd(4,1,">");
      str = 3;
    }
    
    }    
    while (knob() == HIGH) // For auto pressing
    {
      
    }
    
    glcdClear();
    glcd(3,1,"Strategy %d", str);
    delay(4900);//The 5 second delay before starting to move
    beep();
   
    if(str == 1)// STRATEGY 1, THE ACTION BEFORE LOOPING
    {
      beep();
      delay(150);
    }
    
    if(str == 2)// STRATEGY 2, THE ACTION BEFORE LOOPING 2.0
    {
      motor(1,100);
      motor(3,100);
      delay(5);
    }
    
    if(str == 3)// STRATEGY 3, THE ACTION BEFORE LOOPING 3.0
    {
      motor(1,-60);
      motor(3,60);
      delay(60);
      
      while ((analogRead(6)) > (100))
     {
       motor(1,10);
       motor(3,10);
       delay(30);
     }
     
      if((analogRead(6)) < (100))
     { 
       motor(1,15);
       motor(3,-10);
       delay(5);
     }
    }
    
    glcdClear();
}


//=======================================================\\
//=======================================================\\
//=======================================================\\
//=======================================================\\
//=======================================================\\










void loop()
{
  motor(1,15);
  motor(3,15);
  delay(30);
  
  
  
  if((digitalRead(24)) == (0))
  {
    motor(1,60);
    motor(3,-60);
    delay(50);
  }
  
  if((digitalRead(26)) == (0))
  {
    motor(1,100);
    motor(3,100);
    delay(150);
  }
  
  if((digitalRead(31)) == (0))
  {
    motor(1,-60);
    motor(3,60);
    delay(50);
  }

    if((analogRead(A4)) < (100) || (analogRead(A6)) < (100))
    {
      motor(1,-30);
      motor(3,-30);
      delay(400);
      
      motor(1,40);
      motor(3,-40);
      delay(170);
    }
}










