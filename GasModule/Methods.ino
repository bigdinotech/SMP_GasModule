//################################################################################################################
//################################################################################################################
int convertCOtoPPM(double ratio)
{
  //approximates the log/log scale on data sheet by linearizing it in several points
  int PPM = 50;
  double slope = 0;
  if(ratio >1.8)
  {
    PPM = 0;
  }
  else if(ratio >1.5)
  {
    PPM = 50;
    slope = 0.03;
    PPM += (1.8-ratio) / (slope); 
  }
  else if(ratio >1.33)
  {
    PPM = 60;
    slope = 0.017;
    PPM += (1.5-ratio) / (slope); 
  }
  else if(ratio >1.15)
  {
    PPM = 70;
    slope = 0.018;
    PPM += (1.33-ratio) / (slope); 
  }
  else if(ratio >1.05)
  {
    PPM = 80;
    slope = 0.01;
    PPM += (1.15-ratio) / (slope); 
  }
  else if(ratio >1)
  {
    PPM = 90;
    slope = 0.005;
    PPM += (1.05-ratio) / (slope); 
  }
  else if(ratio > 0.6)  
  {
    PPM = 100;
    slope = 0.004;
    PPM += (1.0-ratio) / (slope); 
  }
  else if(ratio >0.47)
  {
    PPM = 200;
    slope = 0.0013;
    PPM += (0.6-ratio) / (slope); 
  }
  else if(ratio >0.39)
  {
    PPM = 300;
    slope = 0.0008;
    PPM += (0.47-ratio) / (slope); 
  }
  else if(ratio >0.34)
  {
    PPM = 400;
    slope = 0.0005;
    PPM += (0.39-ratio) / (slope); 
  }
  else if(ratio >0.3)
  {
    PPM = 500;
    slope = 0.0004;
    PPM += (0.34-ratio) / (slope); 
  }
  else if(ratio >0.275)
  {
    PPM = 600;
    slope = 0.00025;
    PPM += (0.3-ratio) / (slope); 
  }
  else if(ratio >0.25)
  {
    PPM = 700;
    slope = 0.00025;
    PPM += (0.275-ratio) / (slope); 
  }
  else if(ratio >0.24)
  {
    PPM = 800;
    slope = 0.0001;
    PPM += (0.25-ratio) / (slope); 
  }
  else if(ratio >0.22)
  {
    PPM = 900;
    slope = 0.0002;
    PPM += (0.24-ratio) / (slope); 
  }
  else if(ratio >0.16)
  {
    PPM = 1000;
    slope = 0.00006;
    PPM += (0.22-ratio) / (slope); 
  }
  else if(ratio >0.11)
  {
    PPM = 2000;
    slope = 0.00005;
    PPM += (0.16-ratio) / (slope); 
  }
  else if(ratio >0.09)
  {
    PPM = 2000;
    slope = 0.00002;
    PPM += (0.11-ratio) / (slope); 
  }
  else if(ratio >0.01)
  {
    PPM = 2000;
    slope = 0.000013;
    PPM += (0.09-ratio) / (slope); 
  }
  else
  {
    PPM = 10000;
  }
  return PPM; 
}
//################################################################################################################
//################################################################################################################
double convertAlctomgL(double ratio)
{
  double mg10L = 1;
  double slope = 0;
  if(ratio > 2.2)  //2.2mg/L is minimum reading
  {
    mg10L = 0;
  }
  else if(ratio > 1.67)  
  {
    mg10L = 1;
  }
  else if(ratio > 1.3)  
  {
    mg10L = 2;
  }
  else if(ratio > 1)  
  {
    mg10L = 3;
  }
  else if(ratio > 0.89)  
  {
    mg10L = 4;
  }
  else if(ratio > 0.79)  
  {
    mg10L = 5;
  }
  else if(ratio > 0.7)  
  {
    mg10L = 6;
  }
  else if(ratio > 0.65)  
  {
    mg10L = 7;
  }
  else if(ratio > 0.6)  
  {
    mg10L = 8;
  }
  else if(ratio > 0.54)  
  {
    mg10L = 9;
  }
  else if(ratio > 0.35)
  {
    mg10L = 10;
    slope = 0.19;
    mg10L += (0.54-ratio) / (slope) * 10; 
  }
  else if(ratio > 0.26)
  {
    mg10L = 20;
    slope = 0.09;
    mg10L += (0.35-ratio) / (slope) * 10; 
  }
  else if(ratio > 0.2)
  {
    mg10L = 30;
    slope = 0.06;
    mg10L += (0.26-ratio) / (slope) * 10; 
  }
  else if(ratio > 0.19)
  {
    mg10L = 40;
    slope = 0.01;
    mg10L += (0.20-ratio) / (slope) * 10; 
  }
  else if(ratio > 0.175)
  {
    mg10L = 50;
    slope = 0.015;
    mg10L += (0.19-ratio) / (slope) * 10; 
  }
  else if(ratio > 0.15)
  {
    mg10L = 60;
    slope = 0.025;
    mg10L += (0.175-ratio) / (slope) * 10; 
  }
  else if(ratio > 0.14)
  {
    mg10L = 70;
    slope = 0.01;
    mg10L += (0.15-ratio) / (slope) * 10; 
  }
  else if(ratio > 0.125)
  {
    mg10L = 80;
    slope = 0.015;
    mg10L += (0.14-ratio) / (slope) * 10; 
  }
  else if(ratio > 0.11)
  {
    mg10L = 90;
    slope = 0.015;
    mg10L += (0.125-ratio) / (slope) * 10; 
  }
  else
  {
    mg10L = 100;
  }
  return (mg10L / 10.0);
}
//################################################################################################################
//################################################################################################################
int convertMethanetoPPM(double ratio)
{
  //approximates the log/log scale on data sheet by linearizing it in several points
  int PPM = 0;
  double slope = 0;
  if(ratio > 1.9)
  {
    PPM = 0;
  }
  else if(ratio > 1.66)
  {
    PPM = 200;
    slope = 0.0024;
    PPM += (1.9-ratio) / (slope); 
  }
  else if(ratio > 1.5)
  {
    PPM = 300;
    slope = 0.0016;
    PPM += (1.66-ratio) / (slope); 
  }
  else if(ratio > 1.4)
  {
    PPM = 400;
    slope = 0.001;
    PPM += (1.5-ratio) / (slope); 
  }
  else if(ratio > 1.33)
  {
    PPM = 500;
    slope = 0.0007;
    PPM += (1.4-ratio) / (slope); 
  }
  else if(ratio > 1.1)
  {
    PPM = 600;
    slope = 0.0023;
    PPM += (1.33-ratio) / (slope); 
  }
  else if(ratio > 1.05)
  {
    PPM = 700;
    slope = 0.0005;
    PPM += (1.1-ratio) / (slope); 
  }
  else if(ratio > 1.025)
  {
    PPM = 800;
    slope = 0.00025;
    PPM += (1.05-ratio) / (slope); 
  }
  else if(ratio > 1.0)
  {
    PPM = 900;
    slope = 0.00025;
    PPM += (1.025-ratio) / (slope); 
  }
  else if(ratio > 0.79)
  {
    PPM = 1000;
    slope = 0.00021;
    PPM += (1.0-ratio) / (slope); 
  }
  else if(ratio > 0.69)
  {
    PPM = 2000;
    slope = 0.0001;
    PPM += (0.79-ratio) / (slope); 
  }
  else if(ratio > 0.62)
  {
    PPM = 3000;
    slope = 0.00005;
    PPM += (0.69-ratio) / (slope); 
  }
  else if(ratio > 0.58)
  {
    PPM = 4000;
    slope = 0.00004;
    PPM += (0.62-ratio) / (slope); 
  }
  else if(ratio > 0.55)
  {
    PPM = 5000;
    slope = 0.00003;
    PPM += (0.58-ratio) / (slope); 
  }
  else if(ratio > 0.5)
  {
    PPM = 6000;
    slope = 0.00005;
    PPM += (0.55-ratio) / (slope); 
  }
  else if(ratio > 0.485)
  {
    PPM = 7000;
    slope = 0.000015;
    PPM += (0.5-ratio) / (slope); 
  }
  else if(ratio > 0.47)
  {
    PPM = 8000;
    slope = 0.000015;
    PPM += (0.485-ratio) / (slope); 
  }
  else if(ratio > 0.45)
  {
    PPM = 9000;
    slope = 0.00002;
    PPM += (0.47-ratio) / (slope); 
  }
  else
  {
    PPM = 10000;
  }
  return PPM;
  
}
//################################################################################################################
//################################################################################################################
int convertFlammabletoPPM(double ratio)
{
  int PPM = 200;
  double slope;
  if(ratio > 1.75)  //lowest that can be measured is 200PPM
  {
    PPM = 0;
  }
  else if(ratio > 1.5)
  {
    PPM = 200;
    slope = 0.0025;
    PPM += (1.75-ratio) / (slope); 
  }
  else if(ratio > 1.33)
  {
    PPM = 300;
    slope = 0.0017;
    PPM += (1.5-ratio) / (slope); 
  }
  else if(ratio > 1.08)
  {
    PPM = 400;
    slope = 0.0025;
    PPM += (1.33-ratio) / (slope); 
  }
  else if(ratio > 1.0)
  {
    PPM = 500;
    slope = 0.0008;
    PPM += (1.08-ratio) / (slope); 
  }
  else if(ratio > 0.94)
  {
    PPM = 600;
    slope = 0.0006;
    PPM += (1.0-ratio) / (slope); 
  }
  else if(ratio > 0.87)
  {
    PPM = 700;
    slope = 0.0007;
    PPM += (0.94-ratio) / (slope); 
  }
  else if(ratio > 0.83)
  {
    PPM = 800;
    slope = 0.0004;
    PPM += (0.87-ratio) / (slope); 
  }
  else if(ratio > 0.8)
  {
    PPM = 900;
    slope = 0.0003;
    PPM += (0.83-ratio) / (slope); 
  }
  else if(ratio > 0.59)
  {
    PPM = 1000;
    slope = 0.00021;
    PPM += (0.8-ratio) / (slope); 
  }
  else if(ratio > 0.48)
  {
    PPM = 2000;
    slope = 0.00011;
    PPM += (0.59-ratio) / (slope); 
  }
  else if(ratio > 0.41)
  {
    PPM = 3000;
    slope = 0.00007;
    PPM += (0.48-ratio) / (slope); 
  }
  else if(ratio > 0.38)
  {
    PPM = 4000;
    slope = 0.00003;
    PPM += (0.41-ratio) / (slope); 
  }
  else if(ratio > 0.35)
  {
    PPM = 5000;
    slope = 0.00003;
    PPM += (0.38-ratio) / (slope); 
  }
  else if(ratio > 0.31)
  {
    PPM = 6000;
    slope = 0.00004;
    PPM += (0.35-ratio) / (slope); 
  }
  else if(ratio > 0.295)
  {
    PPM = 7000;
    slope = 0.000015;
    PPM += (0.31-ratio) / (slope); 
  }
  else if(ratio > 0.28)
  {
    PPM = 8000;
    slope = 0.000015;
    PPM += (0.31-ratio) / (slope); 
  }
  else if(ratio > 0.28)
  {
    PPM = 9000;
    slope = 0.000005;
    PPM += (0.31-ratio) / (slope); 
  }
  else
  {
    PPM = 10000;
  }
  return PPM;
}
//################################################################################################################
//################################################################################################################
