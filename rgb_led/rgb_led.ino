int redPin = 3;
int greenPin = 4;
int bluePin = 5;

int redBrightness = 50;
int blueBrightness = 20;
int greenBrightness = 10;

String color;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  

}

void loop() {
  
  Serial.println("Enter a desired color ");
  while(Serial.available()==0){

  }

  color = Serial.readString();

  while (Serial.available() > 0) {
    Serial.read();
  }

  if (color == "red"){
     analogWrite(redPin, redBrightness);
     analogWrite(bluePin, 0);
     analogWrite(greenPin, 0);
  }

  if (color == "blue"){
     analogWrite(bluePin, blueBrightness);
     analogWrite(redPin, 0);
     analogWrite(greenPin, 0);
  }
  
  if (color == "green"){
    analogWrite(greenPin, greenBrightness);
    analogWrite(redPin, 0);
    analogWrite(bluePin, 0);
  }

  if (color == "mix"){
    analogWrite(redPin, redBrightness);
    analogWrite(bluePin, blueBrightness);
    analogWrite(greenPin, greenBrightness);
  }
}
