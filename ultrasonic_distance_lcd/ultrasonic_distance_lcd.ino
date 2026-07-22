#include <LiquidCrystal.h>

int triggerPin = 8;
int echoPin = 11;

float speedOfSound = 1235.0; //default spead of sound in km/h

LiquidCrystal lcd(12,9,5,4,3,2);

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Target distance");

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  digitalWrite(triggerPin, LOW);
  delay(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(15);

  digitalWrite(triggerPin, LOW);
  
  unsigned long pingTimeMs = pulseIn(echoPin, HIGH);

  float targetDistance = speedOfSound * pingTimeMs / 72000.0; //in cm

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);

  lcd.print(targetDistance); 
  lcd.print(" cm "); 
  
  delay(250);
}
