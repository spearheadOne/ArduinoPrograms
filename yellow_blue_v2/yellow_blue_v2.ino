int yellowLedPin = 9;
int blueLedPin = 2;

int yellowBlink = 5;
int blueBlink = 3;

int yellowDelayOnMs = 100;
int yewllowDelayOffMs = 300;

int blueDelayOnMs = 300;
int blueDelayOffMs = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(yellowLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Yellow led blinks");
  for (int i=0; i<yellowBlink; i++){
      Serial.print("   Blink: ");
      Serial.println(i);

      digitalWrite(yellowLedPin, HIGH);
      delay(yellowDelayOnMs);

      digitalWrite(blueLedPin, LOW);
      delay(blueDelayOffMs);
  }

  Serial.println("Blue led blinks");
  for (int i=0; i<blueBlink; i++){
      Serial.print("   Blink: ");
      Serial.println(i);

      digitalWrite(blueLedPin, HIGH);
      delay(blueDelayOnMs);

      digitalWrite(yellowLedPin, LOW);
      delay(yewllowDelayOffMs);
  }
   
}