#include <Servo.h>

Servo redLeftServo;
Servo redRightServo;
Servo blueLeftServo;
Servo blueRightServo;

int signalPin = 4;
long gen = 0;
int high = 15;
int low = 5;
int trick = 5;

void setup()
{
  gen = random(0, 10);
  Serial.begin(9600);
  
  pinMode(signalPin, INPUT);
  
  redLeftServo.attach(9);
  blueLeftServo.attach(10);
  blueRightServo.attach(11);
  redRightServo.attach(6);
}

void loop() 
{
  int sensorVal = digitalRead(signalPin);
  Serial.println(sensorVal);
  
  //if(sensorVal == 1)
  //{
    if(gen > 5)
    {
      //left side hot
      blueLeftServo.write(high+trick);
      redLeftServo.write(high+trick);
      blueRightServo.write(low);
      redRightServo.write(low);
      
      delay(1000);
      
      blueLeftServo.write(high);
      redLeftServo.write(high);
      
      delay(4000);
      
      blueLeftServo.write(low - trick);
      redLeftServo.write(low - trick);
      blueRightServo.write(high);
      redRightServo.write(high);
      
      delay(1000);
      
      blueLeftServo.write(low);
      redLeftServo.write(low);
    }
    else
    {
      //right side hot
      blueRightServo.write(high+trick);
      redRightServo.write(high+trick);
      blueLeftServo.write(low);
      redLeftServo.write(low);
      
      delay(1000);
      
      blueRightServo.write(high);
      redRightServo.write(high);
      
      delay(4000);
      
      blueRightServo.write(low - trick);
      redRightServo.write(low - trick);
      blueLeftServo.write(high);
      redLeftServo.write(high);
      
      delay(1000);
      
      blueRightServo.write(low);
      redRightServo.write(low);
    }
    
    delay(4000);
    
    blueLeftServo.write(low);
    redLeftServo.write(low);
    blueRightServo.write(low);
    redRightServo.write(low);
    
    delay(3600000);
  //}
}

