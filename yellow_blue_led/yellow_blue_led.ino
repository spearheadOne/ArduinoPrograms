int yellowLedPin = 9;
int blueLedPin = 2;

int delayOnMs = 500;
int delayOffMs = 500;

float voltage;

void setup() {
  // put your setup code here, to run once:

  pinMode(yellowLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(yellowLedPin, HIGH);
  digitalWrite(blueLedPin, LOW);
  delay(delayOnMs);

  digitalWrite(yellowLedPin, LOW);
  digitalWrite(blueLedPin, HIGH);
  delay(delayOffMs);
}