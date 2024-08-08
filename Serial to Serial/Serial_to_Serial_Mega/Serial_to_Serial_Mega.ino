//Fritzing File: Serial to Serial Connection.fzz

//int ledPin = 13;
int board;   // 1 = Uno. 2 = Mega.
int on_off;  // 1 = On. 0 = Off.
int buzzerPin = 9;
int Ack_tx = 2; //Acknowledgement tx.
int rec;

// SETUP *************************************************************************
void setup()
{
  Serial.begin(9600);      // start serial communication at 9600bps
  Serial1.begin(9600);     // start serial1 communication at 9600bps
 
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.flush();
  Serial1.flush();
  
} // End Setup


// LOOP *************************************************************************
void loop()
{

  Serial.println("Enter Uno=1/Mega=0 ...");  //Select board
  //  if(!Serial){ board = Serial.read();}
  while(Serial.available()==0) { // Wait for User to Input Data
  }
  board = Serial.parseInt();  //Read the data the user has input


  Serial.println("Enter LED On=1/Off=0 ...");  //Select On or Off
  while (Serial.available()==0) { // Wait for User to Input Data
  }
  on_off = Serial.parseInt();

  Serial.println();
  
  
  switch (board) {

  case 0:  //Mega board
    if (on_off == 1) digitalWrite(ledPin, HIGH); //Select Uno LED On
    else digitalWrite(ledPin, LOW);              //Select Uno LED Off
    break;  //End Case

  case 1:  //Uno board
    //Serial.println("Off to Uno...");
    //Send on_off info to Uno
    Serial1.write(on_off/256); //Send the Quotient or "how many times" value
    Serial1.write(on_off%256); //Send the Modulo or Remainder.
    delay(1000); //Wait for the serial port.

    while(Serial1.available()<2) //Wait for 2 bytes to arrive
     {
      //do nothing
     } //End While


  byte b1=Serial1.read();  //Read Upper byte
  byte b2=Serial1.read();  //Read Lower byte
  rec=(b1*256)+b2; 

    if (rec == Ack_tx) tone(buzzerPin, 300, 300); //Ack_tx from Uno
    break;
  } //End Switch Case

}  // End Loop.
