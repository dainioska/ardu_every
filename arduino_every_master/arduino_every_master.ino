//Arduino Nano Every i2c_master example (version: 2020-04-15)

#include <Wire.h>

//Array of patterns  version "hex"
int datArray[20]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

void setup() {
  Serial.begin(9600);
  Wire.begin();
  delay(10000);   //delay 10sek. 
}

void loop() {

for(int i =0; i<20; i++)     //init parallel sequence of patterns from array at chip PCAL6524
{  
Wire.beginTransmission(0x40);  //chip PCAL6524 I2C address 
Wire.write(datArray[i]);
Wire.endTransmission();
delay(3000);
Serial.print("Pattern FIRST: ");
Serial.println(i);
}
//delay(60000);
}
