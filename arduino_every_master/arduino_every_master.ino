//Arduino Nano Every i2c_master example (version: 2020-04-15)
//I/O expander PCAL6524 I2c_slave testing

#include <Wire.h>

//Array of patterns (hex)
const int datArray[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

//Array of port outputs (hex)
const int portArray[3]={0x04,0x05,0x06};


void setup() {
  Serial.begin(9600);
  Wire.begin(); 
  
  Wire.beginTransmission(0x23);  // PCAL6524 device I2C address without R/W (version ADDR Vdd)
  Wire.write(0x0C);  //Port_0 configuration  register address
  Wire.write(0x00);  //OUTPUT value
  Wire.write(0x0D);  //Port_1 configuration  register address
  Wire.write(0x00);  //OUTPUT value
  Wire.write(0x0E);  //Port_2 configuration  register address
  Wire.write(0x00);  //OUTPUT value
  Wire.endTransmission();

  Wire.beginTransmission(0x23);  
  Wire.write(0x04);  //Port_0 output register address
  Wire.write(0x00);  //OUTPUT values "00h"
  Wire.write(0x05);  //Port_1 output register address
  Wire.write(0x00);  //OUTPUT values"00h"
  Wire.write(0x06);  //Port_2 output register address
  Wire.write(0x00);  //OUTPUT values "00h"
  Wire.endTransmission();

  delay(10000);   //delay 10sec. to init
}

void loop() {

for(int i =0; i<3; i++)     //init parallel sequence of ports from portArray
{  
  for(int j =0; j<8; j++)     //init parallel sequence of patterns from datArray
  {  
  Wire.beginTransmission(portArray[i]);  
  Wire.write(datArray[j]);
  Wire.endTransmission();
  Serial.print("Port: ");
  Serial.print(i);
  Serial.print("  Pattern: ");
  Serial.println(j);
  delay(3000);
  }
} 
 //delay(60000);   //delay 60sec. need to change to interrupt "millis"
}
