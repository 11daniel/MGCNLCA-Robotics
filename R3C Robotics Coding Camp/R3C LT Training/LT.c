int L, R, Dis, countB = 0, countW = 0;
int a = 0, b = 0, c = 0, d = 0;

void setup()  
{
     
}

void loop()
{
    L = analog(0);
    R = analog(4);
    Dis = analog(8);
    SB();
    SW();
    LTB();
    LTW();
    
    //lcd("L %d R %d", left, right);
    
    /*
    fd(100); // forward
    sleep(3000); //duration
   
    bk(100);
    sleep(3000);
   
    sl(100);
    sleep(450);
   
    sr(100);
    sleep(450);
   
    ao();   //motor stop
    sleep(5000);
    */
}

void SB()//single-line black
{
    int L = analog(0);
    int R = analog(4);
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

void SW() //single-line white
{
    int L = analog(0);
    int R = analog(4);
    int Dis = analog(8);
    
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
       lcd("CountB %d", countB);
       
       if (countB == 2)
       {
           fd(100);
           sleep(1200);
       }
       if (countB == 3)
       {
           obj();
           keep_up();
           a = 1;
           while (a == 1)
           {
              SW();
              LTW();
           }
       }
      if (countB == 4)
      {
          c =1;
          while (c == 1)
          {
              SW();
              LTW();
          }
      }
   }
}

void LTW() //cross-line white
{
    int L = analog(0);
    int R = analog(4);
    int Dis = analog(8);
    
    if (L > 500 && R > 500)
    {
        fd(100);
        sleep(170);
        
        countW++;
        lcd("CountW %d", countW);
        
        if (countW == 6)
        {
            keep_down();
            fd(100);
            sleep(1200);
        }
        if (countW == 7)
        {
            b = 1;
            while (b == 1)
            {
                SB();
                LTB();
            }
        }
        if (countW == 8)
        {
            SB();
            LTB();
        }
    }
}

void obj()
{
    int L = analog(0);
    int R = analog(4);
    int Dis = analog(8);
    
    if (Dis > 10)
    {
        keep_up(); //pick up object
    }
}