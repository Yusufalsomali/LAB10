/*
 * Project LAB10
 * Description:
 * Author:
 * Date:
 */
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
#include <Wire.h>




void setup() {
  //set up wire, and serial
  Serial.begin(9600);
  Wire.begin();

}

void loop() {

  while (!Serial.isConnected()); //dont start until Serial is connected
  
  if (Serial.available()) {
     //char x = '?'; 
     char x = Serial.read(); 
    Serial.println(x);

  

  
  //transmit value of light to slave bus
  if (x == '0' || x == '1')
  {
    Wire.beginTransmission(0x2A); // transmit to slave device 
    Wire.write((char) x);             // sends one byte
    Wire.endTransmission();    // stop transmitting
  }
  //receive transmission
  else if (x == '?')
  {
    //read request and print to serial
    Wire.requestFrom(0x2a, 1);
    char state = Wire.read();
    Serial.print(state);
  }
  
}
}