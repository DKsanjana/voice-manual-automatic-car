#include<Servo.h>
#include<AFMotor.h>
#include<NewPing.h>

#define MAX_SPEED 190
#define LEFT A3
#define RIGHT A2


int trigpin =5;
int echopin=7;
int speedSet = 0;
int range2;
boolean goesForward=false;

String voice;


long duration,distance,inches,cm,range;

AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR34_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);


Servo myservo;
int pos =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RIGHT,INPUT);
  pinMode(LEFT,INPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);

  digitalWrite(trigpin,LOW);
  
}

void loop() {  
  
    //digitalWrite(13,HIGH);// put your main code here, to run repeatedly:
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin,LOW);
  
  
  // unsigned int distance = sonar.ping_cm();
  duration=pulseIn(echopin,HIGH);
  cm=(duration/2)/29.1;
  inches=(duration/2)/74;
     
   
 // Serial.println(cm);
   
  while (Serial.available()){  
  delay(10); 
  char c = Serial.read(); 
  if (c == '#') {break;} 
  voice += c;
    

  
  } 



   
    if (voice.length() > 0) {
     
       if(voice == "activate Mark 1."||voice == "activate Mark 1"||voice == "Activate mark 1.") {
          
          Mark1();
       }  
       
       if(voice == "Lights on."||voice == "lights on"||voice == "lights on.") {
        
         
       }  

       if(voice == "activate following protocol"||voice == "adobe"||voice == "Adobe") {
         
         
       }  
   
   if(voice == "Lights off."||voice == "lights off"||voice == "lights off."){
    Serial.print("lights off");
    
      
  }

  if(voice == "activate manual control"){
    
                    remoteC();
   }

   if(voice == "activate defence mode"){
    
                    obstacle();
   }

  if(voice == "Friday introduce yourself"){
    
      Serial.print("hello! my name is friday.'i'm developed by sir kaveen to control his hardware divices.'including this robot car.");
  }
  if(voice == "Friday"){
    
      Serial.print("yes");
      }
  
 // else if(voice == "*fade")
   }  
   
voice=""; //Reset the variable after initiating


 
  
  } 


     
      void Mark1(){
      Serial.print("Mark one activated");
      myservo.attach(10);
     {
         for(pos = 90; pos <= 180; pos += 1){
          myservo.write(pos);
          delay(15);
     } for(pos = 180; pos >= 0; pos-= 1) {
         myservo.write(pos);
        delay(15);
     }for(pos = 0; pos<=90; pos += 1) {
       myservo.write(pos);
       delay(15);
       }
      }
      
      while(true){
          while (Serial.available()){
            delay(10);
            char c = Serial.read(); 
             if (c == '#') {break;} 
             voice += c; 
            // Serial.print("inside.");
            }

              
            int right = digitalRead(RIGHT);
            int left = digitalRead(LEFT);

            digitalWrite(trigpin,HIGH);
            delayMicroseconds(10);
            digitalWrite(trigpin,LOW);
  
           duration=pulseIn(echopin,HIGH);
           cm=(duration/2)/29.1;
          inches=(duration/2)/74;
       
          
  
   
  if(right==0&&left==1){
     
      Motor1.setSpeed(225);
      Motor1.run(FORWARD);
      Motor4.setSpeed(225);
      Motor4.run(FORWARD);
      Motor2.setSpeed(200);
      Motor2.run(BACKWARD);
       Motor3.setSpeed(200);
      Motor3.run(BACKWARD); 
    }
    else if(left==0&&right==1){
       
          Motor1.setSpeed(200);
          Motor1.run(BACKWARD);
          Motor2.setSpeed(225);
          Motor2.run(FORWARD);
          Motor3.setSpeed(225);
          Motor3.run(FORWARD);
          Motor4.setSpeed(200);
          Motor4.run(BACKWARD);
      }

   else if((right==1) && (distance>=10 && distance<=30)&&((left)==1)){
       
           Motor1.setSpeed(225);
          Motor1.run(FORWARD);
          Motor2.setSpeed(225);
          Motor2.run(FORWARD);
          Motor3.setSpeed(225);
          Motor3.run(FORWARD);
          Motor4.setSpeed(225);
          Motor4.run(FORWARD);
    
    }

      else if(right==0&&left==0)
      {
        //Serial.println("forward");
        }
        else if(left==1 && right==1){
         
          Motor1.setSpeed(0);
          Motor1.run(RELEASE);
          Motor2.setSpeed(0);
          Motor2.run(RELEASE);
          Motor3.setSpeed(0);
          Motor3.run(RELEASE);
          Motor4.setSpeed(0);
          Motor4.run(RELEASE);
        
      }
     


          if (voice.length() > 0) {
                 if(voice == "activate manual control"){
    
                    remoteC();
                  }
                if(voice == "Friday"){
    
                    Serial.print("yes.");
                  }
                 if(voice == "deactivate"){
                    Serial.print("deactivating.");
                    break;
                  } 

                  if(voice == "go forward"){
                    
                     Motor1.setSpeed(225);
                    Motor1.run(FORWARD);
                     Motor2.setSpeed(225);
                      Motor2.run(FORWARD);
                     Motor3.setSpeed(225);
                     Motor3.run(FORWARD);
                     Motor4.setSpeed(225);
                      Motor4.run(FORWARD);
                   
                    
                  } 
                   if(voice == "stop"){
                     Motor1.setSpeed(0);
                     Motor1.run(RELEASE);
                     Motor2.setSpeed(0);
                      Motor2.run(RELEASE);
                    Motor3.setSpeed(0);
                     Motor3.run(RELEASE);
                   Motor4.setSpeed(0);
                   Motor4.run(RELEASE);
                    
                  } 

                  if(voice == "go backward"){
                     Motor1.setSpeed(225);
                    Motor1.run(BACKWARD);
                     Motor2.setSpeed(225);
                      Motor2.run(BACKWARD);
                     Motor3.setSpeed(225);
                     Motor3.run(BACKWARD);
                     Motor4.setSpeed(225);
                      Motor4.run(BACKWARD);
                    
                  } 
            
            }
            voice=""; 

      }       
  }

char command; 
  void remoteC(){
       Serial.print("Manual control activated");
         while(true){
          while (Serial.available()){
            
            char c = Serial.read(); 
             if (c == '#') {break;} 
             voice += c; 
            // Serial.print("inside.");
            }
          
                   if(Serial.available() > 0){ 
                 command = Serial.read(); 
                 Stop(); //initialize with motors stoped
                //Change pin mode only if new command is different from previous.   
              // Serial.println(command);
           switch(command){
            case 'F':  
             Motor1.setSpeed(255); 
             Motor1.run(FORWARD); 
             Motor2.setSpeed(255); 
             Motor2.run(FORWARD); 
             Motor3.setSpeed(255);
             Motor3.run(FORWARD); 
             Motor4.setSpeed(255);
             Motor4.run(FORWARD); 
            break;
           case 'B':  
              Motor1.setSpeed(255); 
              Motor1.run(BACKWARD); 
              Motor2.setSpeed(255); 
              Motor2.run(BACKWARD); 
              Motor3.setSpeed(255); 
              Motor3.run(BACKWARD); 
              Motor4.setSpeed(255); 
              Motor4.run(BACKWARD); 
             break;
           case 'L':  
              Motor1.setSpeed(200);
              Motor1.run(BACKWARD);
              Motor2.setSpeed(225);
              Motor2.run(FORWARD);
              Motor3.setSpeed(225);
              Motor3.run(FORWARD);
              Motor4.setSpeed(200);
              Motor4.run(BACKWARD);
              break;
          case 'R':
              Motor1.setSpeed(225);
              Motor1.run(FORWARD);
              Motor4.setSpeed(225);
              Motor4.run(FORWARD);
              Motor2.setSpeed(200);
              Motor2.run(BACKWARD);
              Motor3.setSpeed(200);
              Motor3.run(BACKWARD); 
            break;
          default:
             Motor1.setSpeed(0); //Define minimum velocity
             Motor1.run(RELEASE); //stop the motor when release the button
             Motor2.setSpeed(0); //Define minimum velocity
             Motor2.run(RELEASE); //rotate the motor clockwise
             Motor3.setSpeed(0); //Define minimum velocity
             Motor3.run(RELEASE); //stop the motor when release the button
             Motor4.setSpeed(0); //Define minimum velocity
             Motor4.run(RELEASE); //stop the motor when release the button
           break;
          //command ="";
        }
       } 
        if (voice.length() > 0) {

                if(voice == "Friday"){
    
                    Serial.print("yes.");
                  }
                 if(voice == "deactivate"){
                    Serial.print("deactivating.");
                    break;
                  } 
        }

          voice="";
          
    }
    
  }




 void obstacle(){
     int distanceR = 0;
     int distanceL =  0;
   
     Serial.print("defence system activated");
      myservo.attach(10);  
      myservo.write(115); 
      delay(2000);
      range = dist();
      delay(100);
      range = dist();
     delay(100);
     range = dist();
     delay(100);
     range = dist();
     delay(100); 
     
         while(true){
          while (Serial.available()){
            
            char c = Serial.read(); 
             if (c == '#') {break;} 
             voice += c; 
            // Serial.print("inside.");
            }
  if(range<=15)
  {
     Stop();
    delay(100);
    back();
    delay(300);
    Stop();
    delay(200);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);

  if(distanceR>=distanceL)
  {
    right();
    Stop();
  }else
  {
    left();
    Stop();
  }
  }else
 {
   forward();
 }
 range = dist(); 
  if (voice.length() > 0) {

                if(voice == "Friday"){
    
                    Serial.print("yes.");
                  }
                 if(voice == "deactivate"){
                    Serial.print("deactivating.");
                    break;
                  } 
        }

          voice="";
 }

}


 void forward()
{
  if(!goesForward)
  {
    goesForward=true;
    Motor1.run(FORWARD);      
    Motor2.run(FORWARD);
    Motor3.run(FORWARD); 
    Motor4.run(FORWARD);     
   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
   {
    Motor1.setSpeed(speedSet);
    Motor2.setSpeed(speedSet);
    Motor3.setSpeed(speedSet);
    Motor4.setSpeed(speedSet);
    delay(5);
   }
  }
}

void back()
{
 goesForward=false;
    Motor1.run(BACKWARD);      
    Motor2.run(BACKWARD);
    Motor3.run(BACKWARD);
    Motor4.run(BACKWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
  {
    Motor1.setSpeed(speedSet);
    Motor2.setSpeed(speedSet);
    Motor3.setSpeed(speedSet);
    Motor4.setSpeed(speedSet);
    delay(5);
  }
}

void left()
{
          Motor1.setSpeed(255);
          Motor1.run(BACKWARD);
          Motor2.setSpeed(225);
          Motor2.run(FORWARD);
          Motor3.setSpeed(225);
          Motor3.run(FORWARD);
          Motor4.setSpeed(255);
          Motor4.run(BACKWARD);
}

void right()
{
      Motor1.setSpeed(225);
      Motor1.run(FORWARD);
      Motor4.setSpeed(225);
      Motor4.run(FORWARD);
      Motor2.setSpeed(255);
      Motor2.run(BACKWARD);
      Motor3.setSpeed(255);
      Motor3.run(BACKWARD); 
} 

void Stop()
{
  Motor1.setSpeed(0); 
  Motor1.run(RELEASE); 
  Motor2.setSpeed(0);
  Motor2.run(RELEASE);
  Motor3.setSpeed(0); 
  Motor3.run(RELEASE); 
  Motor4.setSpeed(0); 
  Motor4.run(RELEASE); 
  
}

int dist(){
     digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin,LOW);
  
    duration=pulseIn(echopin,HIGH);
    cm=(duration/2)/29.1;
    inches=(duration/2)/74;

    return cm;
  }

int lookRight()
{
    myservo.write(50); 
    delay(500);
    range2 = dist();
    delay(100);
    myservo.write(115); 
    return range2;
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int range2 = dist();
    delay(100);
    myservo.write(115); 
    return range2;
    delay(100);
}





  
