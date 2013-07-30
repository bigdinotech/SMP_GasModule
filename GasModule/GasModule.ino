//GAS Module
//Dino Tinitigan
#include<SMP.h>
byte ID = 42;
byte header = 170;
byte dataLength = 12;
int COMSB;
int COLSB;
byte AlcoholMSB;
byte AlcoholLSB;
byte MethaneMSB;
byte MethaneLSB;
byte FlammableMSB;
byte FlammableLSB;
byte packet[12];
byte commandPacket[8];
//calibrated Ro Values
//todo get calibrated values
double CORo = 8000;
double AlcoholRo = 10000;
double MethaneRo = 10000;
double FlammableRo = 10000;

int ledPin = 13;
int priority = 200;
int wait = 1000;

int COSensor = 0;
int AlcoholSensor = 1;
int MethaneSensor = 2;
int FlammableGasSensor = 3;


int prevCOValue = 0;
int prevAlcoholValue = 0;
int prevFlammableValue = 0;
int prevMethaneValue = 0;

unsigned long last = 0;
unsigned long current = 0;
bool timedOut;

#include<SMP.h>
SMP gasModule(ID, Serial, 10, 11);

//################################################################################################################
//################################################################################################################
void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  delay(15000);    //allow heaters in sensor time to heat up
}
//################################################################################################################
//################################################################################################################
void loop()
{
  //Serial.println();
  //Serial.println(millis());
  current = millis();
  int currCOValue = analogRead(COSensor);
  int currAlcoholValue = analogRead(AlcoholSensor);
  int currMethaneValue = analogRead(MethaneSensor);
  int currFlammableValue = analogRead(FlammableGasSensor);
  
  if(currCOValue == 0)
  {
    currCOValue = 1;
  }
  if(currAlcoholValue == 0)
  {
    currAlcoholValue = 1;
  }
  if(currMethaneValue == 0)
  {
    currMethaneValue = 1;
  }
  if(currFlammableValue == 0)
  {
    currFlammableValue = 1;
  }
  
  //calculate approx ppm for each sensor
  double CORs = ((1023.0 - currCOValue)/currCOValue) * 10000.0;
  int COPPM = convertCOtoPPM(CORs/CORo);
  COMSB = COPPM/256;
  COLSB = COPPM%256;
  
  double AlcoholRs = ((1023.0 - currAlcoholValue)/currAlcoholValue) * 200000.0;
  double AlcmgL = convertAlctomgL(AlcoholRs/AlcoholRo);
  int iAlcoholmg10L = AlcmgL * 1000;
  AlcoholMSB = iAlcoholmg10L/256;
  AlcoholLSB = iAlcoholmg10L%256;
  
  
  double MethaneRs = ((1023.0 - currMethaneValue)/currMethaneValue) * 22000.0;
  int MethanePPM = convertMethanetoPPM(MethaneRs/MethaneRo);
  MethaneMSB = MethanePPM/256;
  MethaneLSB = MethanePPM%256;
  
  double FlammableRs = ((1024.0 - currFlammableValue)/currFlammableValue) * 10000.0;
  int FlammablePPM = convertFlammabletoPPM(FlammableRs/FlammableRo);
  FlammableMSB = FlammablePPM/256;
  FlammableLSB = FlammablePPM%256;
  
 
  packet[0] = dataLength;
  packet[1] = 'c';
  packet[2] = COMSB;
  packet[3] = COLSB;
  packet[4] = 'a';
  packet[5] = AlcoholMSB;
  packet[6] = AlcoholLSB;
  packet[7] = 'm';
  packet[8] = MethaneMSB;
  packet[9] = MethaneLSB;
  packet[10] = 'f';
  packet[11] = FlammableMSB;
  packet[12] = FlammableLSB;
  
  
  
  //debug
  /**
  Serial.print("CO: ");
  //Serial.println(currCOValue);
  Serial.print(COPPM);
  Serial.println(" PPM");
  //Serial.println(CORs);
  
  Serial.print("Alcohol: ");
  //Serial.println(currAlcoholValue);
  Serial.print(AlcmgL);
  Serial.println(" mg/L");
  //Serial.println(AlcoholRs);
  
  Serial.print("Methane: ");
  //Serial.println(currMethaneValue);
  Serial.print(MethanePPM);
  Serial.println(" PPM");
  //Serial.println(MethaneRs);
  
  Serial.print("Flammable: ");
  //Serial.println(currFlammableValue);
  Serial.print(FlammablePPM);
  Serial.println(" PPM");
  //Serial.println(FlammableRs); 
  **/
  
  if((current - last) > wait)
  {
    //if((currCOValue == prevCOValue) && (currAlcoholValue == prevAlcoholValue) && (currFlammableValue == prevFlammableValue) && (currMethaneValue == prevMethaneValue))
    {
    }
    //else
    {
      //transmitData(packet, dataLength);
      gasModule.sendData(packet);
      last = millis();
    }
  }
  //timer overflow
  if(current < last)
  {
    current = millis();
    last = current;
  }
  //delay(1000);
  
}
//################################################################################################################
//################################################################################################################
