#include <AccelStepper.h>
#include <MultiStepper.h>



#define rightEndStopPin     23
#define leftEndStopPin      22

#define spindleStepPin      34
#define spindleDirPin       33
#define spindleEnablePin    32

#define followerStepPin     46
#define followerDirPin      45
#define followerEnablePin   44

#define dummyPin 37
#define revolutionPin        3

#define xJoyPin               A0
#define yJoyPin               A1



#define LEFT 1
#define RIGHT 0
#define FORWARD 0
#define BACKWARD 1

byte followerDirection;

long revCount=0;
boolean canRun=false;

AccelStepper spindle(AccelStepper::DRIVER,spindleStepPin,dummyPin);
AccelStepper follower(AccelStepper::DRIVER,followerStepPin,dummyPin);

void setup()
{  
    Serial.begin(115200);
    attachInterrupt(digitalPinToInterrupt(rightEndStopPin), rightEndStop, RISING);
    attachInterrupt(digitalPinToInterrupt(leftEndStopPin), leftEndStop, RISING);
    attachInterrupt(digitalPinToInterrupt(revolutionPin), revolutionCounter, FALLING);
    pinMode(spindleDirPin,OUTPUT);
    pinMode(followerDirPin,OUTPUT);
    //testMovement();

 Serial.println("Setup finished");   
}



void loop(){
static long oldMillis=0;
if  (oldMillis+200<millis()){
  readXAxis();
  readYAxis();
  oldMillis=millis();
}
//  spindle.canRun=true;
// while(spindle.distanceToGo()){
//  //spindle.runSpeed(); 
//  spindle.run();
// }
//   
// delay(2000);
// testMovement();  
}
    



void show(){

}
