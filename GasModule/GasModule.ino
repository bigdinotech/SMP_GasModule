//GAS Module
//Dino Tinitigan

byte ID = 42;
byte header = 170;
byte dataLength = 8;
int COMSB;
int COLSB;
byte AlcoholMSB;
byte AlcoholLSB;
byte MethaneMSB;
byte MethaneLSB;
byte FlammableMSB;
byte FlammableLSB;
byte packet[10];
byte commandPacket[8];
//calibrated Ro Values
//todo get calibrated values
double CORo = 8000;
double AlcoholRo = 8600;
double MethaneRo = 10000;
double FlammableRo = 10000;

int bPin = 10;
int sPin = 11;
int ledPin = 13;
int priority = 200;
int wait = 100;

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

//################################################################################################################
//################################################################################################################
void setup()
{
  Serial.begin(115200);
  pinMode(bPin, INPUT);
  pinMode(sPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(sPin, HIGH);
  delay(30000);    //allow heaters in sensor time to heat up
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
  
  packet[0] = ID;
  packet[1] = dataLength;
  packet[2] = COMSB;
  packet[3] = COLSB;
  packet[4] = AlcoholMSB;
  packet[5] = AlcoholLSB;
  packet[6] = MethaneMSB;
  packet[7] = MethaneLSB;
  packet[8] = FlammableMSB;
  packet[9] = FlammableLSB;
  
  
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
      transmitData(packet, dataLength);
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
