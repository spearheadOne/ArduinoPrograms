#include<Servo.h>

int servoPin = 6;
int triggerPin = 8;
int echoPin = 11;


Servo servo;

float speedOfSound = 1235.0; //default spead of sound in km/h
float servoAngle;

int servoDelay = 25;

void setup() {
  Serial.begin(9600);
  
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(servoPin, OUTPUT);

  servo.attach(servoPin);
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delay(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(15);

  digitalWrite(triggerPin, LOW);
  
  unsigned long pingTimeUs = pulseIn(echoPin, HIGH);
  float targetDistance = speedOfSound * pingTimeUs / 72000.0; //in cm

  int servoAngle = map(targetDistance, 0, 10, 37, 143); //0-10 cm, 37-143 degrees
  servo.write(servoAngle);

  Serial.print("The distance to target is: ");
  Serial.print(targetDistance);
  Serial.println( "cm ");
  delay(100);


}
