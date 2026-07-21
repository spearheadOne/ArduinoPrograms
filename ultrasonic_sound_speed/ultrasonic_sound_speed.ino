int triggerPin = 8;
int echoPin = 11;

float pingTime;
float speedOfSound;
float targetDistance = 15.24; //in cm

void setup() {
  Serial.begin(9600);
  
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delay(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin, LOW);

  pingTime = pulseIn(echoPin, HIGH);

  speedOfSound = (2.0 * targetDistance / pingTime) * 36000.0;

  Serial.print("Speed of sound is: ");
  Serial.print(speedOfSound);
  Serial.println(" km/h. ");

  delay(3000);
}
