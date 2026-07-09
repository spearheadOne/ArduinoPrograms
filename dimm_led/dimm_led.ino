int ledPin = 3;
int potPin = A0;

int rawVoltage; 
int voltage;

void setup() {
  // put your setup code here, to run once:
  pinMode(potPin,INPUT);
  pinMode(ledPin, OUTPUT);


  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  rawVoltage = analogRead(potPin);

  voltage  = (2555./1023.)*rawVoltage;
  analogWrite(ledPin, voltage);

}
