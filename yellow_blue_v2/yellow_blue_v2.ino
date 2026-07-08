int yellowLedPin = 9;
int blueLedPin = 2;

int yellowBlink;
int defaultYellowBlink = 5;
int blueBlink = 3;

int yellowDelayOnMs = 100;
int yewllowDelayOffMs = 300;

int blueDelayOnMs = 300;
int blueDelayOffMs = 100;

int blueVoltage;
int defaultBlueVoltage = 255;

String yellowBlinkMsg = "Yellow led blinks";
String blueBlinkMsg = "Blue led blinks";

String blinkMsg = "   Blink: ";
String yellowBlinkPrompt = "Enter number of yellow blinks";
String blueVoltPrompt = "Enter voltage for blue led from 1 to 255 (51 = 1v, 255 = 5v)";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(yellowLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT); 
  
  yellowBlink = readIntOrDefault(yellowBlinkPrompt, defaultYellowBlink);
  blueVoltage = readIntOrDefault(blueVoltPrompt, defaultBlueVoltage);
}


int readIntOrDefault(String prompt, int defaultValue) {
  Serial.println(prompt);

  while (Serial.available() == 0) { }

  int value = Serial.parseInt();

  while (Serial.available() > 0) {
    Serial.read();
  }

  return value == 0 ? defaultValue : value;
}


void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(yellowBlinkMsg);
  for (int i=0; i<yellowBlink; i++){
      Serial.print(blinkMsg);
      Serial.println(i);

      digitalWrite(yellowLedPin, HIGH);
      delay(yellowDelayOnMs);

      digitalWrite(yellowLedPin, LOW);
      delay(yewllowDelayOffMs);
    
  }

  Serial.println(blueBlinkMsg);
  for (int i=0; i<blueBlink; i++){
      Serial.print(blinkMsg);
      Serial.println(i);

      analogWrite(blueLedPin, blueVoltage); // 51 = 1V; 255 = 5V
      delay(blueDelayOnMs);

      analogWrite(blueLedPin, 0);
      delay(blueDelayOffMs);    
  }
   
}