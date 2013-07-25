//################################################################################################################
//################################################################################################################
void transmitData(byte dataPacket[], int dataPacketLength)
{
  byte dataChecksum = 0;
  for(int i = 0; i < dataPacketLength; i++)
  {
    dataChecksum += dataPacket[i];
  }
  /**
  dataChecksum += ID;
  dataChecksum += dataLength;
  dataChecksum += COMSB;
  dataChecksum += COLSB;
  dataChecksum += AlcoholMSB;
  dataChecksum += AlcoholLSB;
  dataChecksum += MethaneMSB;
  dataChecksum += MethaneLSB;
  dataChecksum += FlammableMSB;
  dataChecksum += FlammableLSB;
  **/
  int test = digitalRead(bPin);
  int timeout = 0;
  //test = 0;
  //Serial.print("bpin: ");
  //Serial.println(test);
  while(test && timeout<100)//busy waiting
  {
    int x = random(10);
    delay(x);
    test = digitalRead(bPin);
    timeout++;
    timedOut = true;
  }
  if(!timedOut)
  {
    digitalWrite(sPin,LOW); //pull LOW to signify sending
    for(int i = 0; i < dataPacketLength; i++)
    {
      Serial.write(dataPacket[i]);
    }
    Serial.write(dataChecksum);
    Serial.flush();  
    digitalWrite(sPin, HIGH); //pull LOW to signify done sending
  }
  timedOut = false; 
}
//################################################################################################################
//################################################################################################################
int readData(byte cmdPacket[])
{
  byte buff;
  byte tempID;
  byte cmdChecksum = 0;
  if(Serial.available())
  {
    buff = Serial.read();  //header byte
    if(buff == header)
    {
      buff = Serial.read();  //ID byte
      tempID = buff;
      cmdChecksum += buff;
      buff = Serial.read();  //length byte
      cmdChecksum += buff;
      for(int i=0; i<buff; i++)
      {
        cmdPacket[i] = Serial.read();  //command byte/s
        cmdChecksum += cmdPacket[i];
      } 
      buff = Serial.read();  //checksum byte
      if(cmdChecksum == buff)
      {
        //valid checksum
        if(tempID == ID)
        {
          //valid ID
          return 1;
        }
        else
        {
          //invalid ID
          return 0;
        }
      }
      else
      {
        //bad checksum
        return 0;
      }      
    }
    else
    {
      //bad header, restart from beginning
      if(Serial.available())
      {  
        if(readData(cmdPacket))
        {
          return 1;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    return 0;
  }
}
//################################################################################################################
//################################################################################################################
