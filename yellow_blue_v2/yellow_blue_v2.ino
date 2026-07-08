int yellowLedPin = 9;
int blueLedPin = 2;

int yellowBlink;
int blueBlink = 3;

int yellowDelayOnMs = 100;
int yewllowDelayOffMs = 300;

int blueDelayOnMs = 300;
int blueDelayOffMs = 100;

String yellowBlinkMsg = "Yellow led blinks";
String blueBlinkMsg = "Blue led blinks";

String blinkMsg = "   Blink: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(yellowLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);  

  Serial.println("Enter number of yellow blinks");
  while(Serial.available()==0){
    
  }

  int input = Serial.parseInt();
  yellowBlink = input == 0 ? 5: input;
  Serial.read();

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(yellowBlinkMsg);
  for (int i=0; i<yellowBlink; i++){
      Serial.print(blinkMsg);
      Serial.println(i);

      digitalWrite(yellowLedPin, HIGH);
      delay(yellowDelayOnMs);

      digitalWrite(blueLedPin, LOW);
      delay(blueDelayOffMs);
  }

  Serial.println(blueBlinkMsg);
  for (int i=0; i<blueBlink; i++){
      Serial.print(blinkMsg);
      Serial.println(i);

      digitalWrite(blueLedPin, HIGH);
      delay(blueDelayOnMs);

      digitalWrite(yellowLedPin, LOW);
      delay(yewllowDelayOffMs);
  }
   
}