int L, R, Dis, countB = 0,countW = 0;
int a = 0,b = 0,c = 0, d = 0;
void setup()  
{
     
}
void loop()
{
    L = analog(0);
    R = analog(4);
    Dis = analog(8);
    
    //lcd("Value %d", Dis);
    SB();
    LTB();
    obj();
      
}

void LTB() //black cross line
{
   int L = analog(0);
   int R = analog(4);
   int Dis = analog(8); 

  if (L < 500 && R < 500)  
  {
      fd(100);
      sleep(170);  

      countB++; //add by 1 
      lcd("CountB %d",countB);
       
      if (countB == 4)
      {
          fd(100);
          sleep(120);
      }
      if (countB == 5)
      {
          keep_down();
          sr(100);
          sleep(910);
      }
      if (countB == 6)
      {
          sl(100);
          sleep(400);
      }
      if (countB == 7)
      {
          sl(100);
          sleep(410);
      }
      if (countB == 8)
      {
          keep_down();
          sr(100);
          sleep(900);
      }
      if (countB == 9)
      {
          sl(100);
          sleep(400);
      }
      if (countB == 10)
      {
          sl(100);
          sleep(420);
      }
      if (countB == 11)
      {
          keep_down();
          sr(100);
          sleep(900);
      }
      if (countB == 14)
      {
          sr(100);
          sleep(420);
      }
  } 
} 

void LTW()
{
    //white cross line 
   int L = analog(0);
   int  R = analog(4);
   int Dis = analog(8); 
    
    if (L > 500 && R > 500)  
  {
      fd(100);
      sleep(170);  

      countW++; //add by 1 
      lcd("CountW %d",countW);
      
      if (countW == 3)
      {
          fd(100);
          sleep(500);
          sl(100);
          sleep(900);
          keep_down();
          sr(100);
          sleep(900);
      }
      
      if (countW == 6)
      {
          keep_down();
         fd(100);
         sleep(1200);   
      }
     if (countW == 7)
     {
         b=1;
         while (b == 1)
         {
            SB();   
            LTB();
         }
     }
     if (countW == 8)
     {
         sr(100);
         sleep(200);
         d = 1;
         while (d == 1)
         {
             SB();
             LTB();  
         } 
     }
  } 
} 

void SW()  //line tracing for white line
{
   int L = analog(0);
   int R = analog(4);
   int Dis = analog(8); 
   //Single line white line
   if (L > 500)
  {
      sl(100);
  }
  else if (R > 500)
  {
      sr(100); 
  }
  else
  {
      fd(100);
  }   
}

void SB()
{
    //Single line black line
       int L = analog(0);
   int  R = analog(4);
   int Dis = analog(8); 
    
  if (L < 500)
  {
      sl(100);
  }
  else if (R < 500)
  {
      sr(100); 
  }
  else
  {
      fd(100);
  }
}

void obj()
{
   int L = analog(0);
   int R = analog(4);
   int Dis = analog(8);   
   if (Dis > 165)
   {
      keep_up();  //pick an object
      fd(100);
   }
   
}