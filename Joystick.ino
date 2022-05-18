void readXAxis(){
  int dist=5000;
  
  int value=analogRead(xJoyPin);
 
  if (value<300){
    follower.canRun=true;
    setFollowerDirection(LEFT);
    follower.setMaxSpeed(800);
    follower.setAcceleration(900);
    follower.move(dist);
    while(follower.distanceToGo()>0){
      
      if(!digitalRead(leftEndStopPin)){
        follower.run();
      }
      else{
       follower.setCurrentPosition(0);
      }
      //Serial.println(follower.distanceToGo());
    }
  }
  if (value>800){
     follower.canRun=true;
   setFollowerDirection(RIGHT);
    follower.setMaxSpeed(800);
    follower.setAcceleration(900);
    follower.move(dist);
    while(follower.distanceToGo()>0){
     
      follower.run();
      //Serial.println(follower.distanceToGo());
    }
  }
}


void readYAxis(){
  int value=analogRead(yJoyPin);
 
  if (value<300){
    spindle.canRun=true;
    setSpindleDirection(BACKWARD);
    spindle.setMaxSpeed(800);
    spindle.setAcceleration(900);
    spindle.move(200);
    while(spindle.distanceToGo()>0){
      
      spindle.run();
      //Serial.println(spindle.distanceToGo());
    }
  }
  if (value>800){
     spindle.canRun=true;
   setSpindleDirection(FORWARD);
    spindle.setMaxSpeed(800);
    spindle.setAcceleration(900);
    spindle.move(200);
    while(spindle.distanceToGo()>0){
     
      spindle.run();
      //Serial.println(spindle.distanceToGo());
    }
  }
}



void setFollowerDirection(byte dir){
  if (dir==LEFT){
   
    digitalWrite(followerDirPin,LEFT);
     Serial.print("Left  ");Serial.println(digitalRead(followerDirPin));
  }
   if (dir==RIGHT){
   
    digitalWrite(followerDirPin,RIGHT);
     Serial.print("Right  ");Serial.println(digitalRead(followerDirPin));
   }
  
}

void setSpindleDirection(byte dir){
  if (dir==FORWARD){
   
    digitalWrite(spindleDirPin,FORWARD);
     Serial.print("FORWARD  ");Serial.println(digitalRead(spindleDirPin));
  }
   if (dir==BACKWARD){
   
    digitalWrite(spindleDirPin,BACKWARD);
     Serial.print("BACKWARD  ");Serial.println(digitalRead(spindleDirPin));
   }
  
}
