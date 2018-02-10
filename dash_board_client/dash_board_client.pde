import processing.serial.*;

Serial robotChassis;

void setup()
{
  size(800,500);
  printArray(Serial.list());
  robotChassis = new Serial(this,Serial.list()[1],9600);
  // send a test byte 
  //robotChassis.write(118);
  //byte[] buffer = new byte[7];
  //robotChassis.readBytes(buffer);
  //if(buffer != null)
  //{
  //   String res = new String(buffer);
  //   println(res);
  //}
}

void draw()
{
  background(0);
  
}

void keyPressed()
{
  println(key); 
  robotChassis.write(key);
}

void keyReleased()
{
  println("key up!");
  robotChassis.write('x');  
}