#include<Servo.h>

Servo servo;

int servoPin = 3;
int potPin = A0;

int rawVoltage; // 0v = 0; 5v = 1023; 

int pos = 0;   
int minPos = 15;
int servoDelay = 25;

void setup() {
   servo.attach(servoPin);
}

void loop() {
 rawVoltage = analogRead(potPin);

 int maxPos = (155./1023.)*rawVoltage + minPos; //assume min pos as 15 == 0.0; max pos as 170 == 1023

 rotate(maxPos); 
}

void rotate(int maxPos){
  for (pos=minPos; pos<=maxPos; pos+=1){
     servo.write(pos);
     delay(servoDelay);
  }

  for (pos=maxPos; pos>=minPos; pos-=1){
     servo.write(pos);
     delay(servoDelay);
  }
}

