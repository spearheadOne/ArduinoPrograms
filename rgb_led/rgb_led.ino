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
  color.trim();

  handleColor(color);
}


void setRgb(int redBr, int greenBr, int blueBr) {
  analogWrite(redPin, redBr);
  analogWrite(greenPin, greenBr);
  analogWrite(bluePin, blueBr);
}  

void handleColor(String color) {
  if (color == "red") {
    setRgb(redBrightness, 0, 0);
  }  else if (color == "green") {
    setRgb(0, greenBrightness, 0);
  } else if (color == "blue") {
    setRgb(0, 0, blueBrightness);
  }  else if (color == "mix") {
    setRgb(redBrightness, greenBrightness, blueBrightness);
  } else if (color == "off") {
    setRgb(0, 0, 0);
  } else {
    Serial.println("Unknown color");
  }
}

