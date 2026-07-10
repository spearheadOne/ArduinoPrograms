int redPin = 3;
int greenPin = 4;
int bluePin = 5;

int redBrightness = 50;
int blueBrightness = 20;
int greenBrightness = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(redPin, redBrightness);
  analogWrite(bluePin, blueBrightness);
  analogWrite(greenPin, greenBrightness);
}
