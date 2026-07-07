int ledPin = 13;

int delayOnMs = 100;
int delayOffMs = 900;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  delay(delayOnMs);

  digitalWrite(ledPin, LOW);
  delay(delayOffMs);
}
