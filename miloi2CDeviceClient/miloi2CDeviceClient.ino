#include <Wire.h>
#include <ArduinoJson.h>
#include <stdint.h>

void setup() 
{
  Wire.begin(8); // join as address 8
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() 
{
 
}

void receiveEvent(int howMany)
{
  int index = 0;
  char commandBuffer[80];
  while(0 < Wire.available())
  {
    char c = Wire.read();
    commandBuffer[index] = c;
    index++;
  }

  commandBuffer[index] = '\0';
  Serial.println(commandBuffer);
}
