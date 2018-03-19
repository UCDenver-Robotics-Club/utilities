#include <Wire.h>
#include <ArduinoJson.h>
#include <stdint.h>
#include <string.h> // c string lib, sometimes faster
#include <avr/io.h>

bool isRunning;

void setup() 
{
  Wire.begin(8); // join as address 8
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  isRunning = false;
  // set pin 13 to output
  DDRB |= (1<<PB5);
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
  //Serial.println(commandBuffer);
  parseCommand(String(commandBuffer));
}

void parseCommand(String rawcommand)
{
  // convert the string from raw text to an object
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(rawcommand);
  const char* device = root["device"];
  const char* action = root["action"];

  if(strcmp(device,"led") == 0)
  {
    setLed(action);
  }
  
}


void setLed(char *action)
{
  Serial.println(action);
  if(strcmp(action,"on") == 0)
  {
    PORTB |= (1<<PB5);
  }
  else if(strcmp(action,"off") == 0)
  {
    PORTB &= ~(1 << PB5);
  }
}

