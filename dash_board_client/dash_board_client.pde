import processing.serial.*;

Serial robotChassis;
boolean risingEdge=false;

void setup()
{
  size(800,500);
  textSize(32);
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
  if(key > 0 && keyPressed)
  {
    fill(0,255,0); // yellow
    //String str = new String(key);
    text(key+"",10,90);
    //println(key); 
    robotChassis.write(key);
    println("running");
  }
  else if(!keyPressed) // if no key is currently being pressed
  {
    println("stopped");
    robotChassis.write('x');
    fill(255,0,0); // red 
    text("full stop",45,90);
  }
}

/*
  for some reason the keyReleased event is getting stuck
  This is preventing the robot from moving
  from what I can tell from google this is an issue with
  proccesing which makes me really sad 
*/

//void keyPressed()
//{
//  println(key); 
//  robotChassis.write(key);
//}

//void keyReleased()
//{
//  println("key up!");
//  robotChassis.write('x');  
//}