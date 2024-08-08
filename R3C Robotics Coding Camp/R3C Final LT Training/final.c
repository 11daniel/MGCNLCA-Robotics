int L, R, Dis, countB=0,countW=0;
int a=0,b=0,c=0,d=0;
void setup()  
{
     
}
void loop()
{
    L = analog(0);
    R = analog(4);
    Dis = analog(8);
    
    SB();
    LTB();
      
}

void LTB() //black cross line
{
   int L = analog(0);
   int  R = analog(4);
   int Dis = analog(8); 

  if (L < 500 && R < 500)  
  {
      fd(100);
      sleep(170);  

      countB++; //add by 1 
      lcd("CountB %d",countB);
      
      if (countB == 2)
      {
          fd(100);
          sleep(1200);
      }    
      if (countB == 3)
      {
          obj();
          keep_up();
          a=1;
        while (a == 1)
        {
            SW();
           LTW();
        }  
      }  
      if (countB == 4)
      {
             c=1;
             while (c==1)
             {
               SW(); 
               LTW();  
             }
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
      
      if (countW == 6)
      {
          keep_down();
         fd(100);
         sleep(1200);   
      }
     if (countW== 7)
     {
         b=1;
         while (b==1)
         {
            SB();   
            LTB();
         }
     }
     if (countW== 8)
     {
        SB();
        LTB();   
     }
  } 
} 

void SW()  //line tracing for white line
{
       int L = analog(0);
   int  R = analog(4);
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
   int  R = analog(4);
   int Dis = analog(8);   
   if (Dis > 10)
   {
      keep_up();  //pick an object
      fd(100);
   }
   
}