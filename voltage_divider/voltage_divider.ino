int potPin = A0;
int rawVoltage;// 0v = 0; 5v = 1023; 
float voltage;



void setup() {
  // put your setup code here, to run once:
  pinMode(potPin,INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  rawVoltage = analogRead(potPin);
  voltage  = (5./1023.)*rawVoltage;

  Serial.print("Current voltage: ");
  Serial.print(voltage);
  Serial.println(" v");
  delay(250);
}
