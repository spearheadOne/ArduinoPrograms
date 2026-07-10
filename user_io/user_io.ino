String name;
int age;
float height;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enter your name: "); 
  while(Serial.available()==0){}
  name = Serial.readString();
  while (Serial.available() > 0) {
    Serial.read();
  }

  Serial.println("Enter your age: "); 
  while(Serial.available()==0){}
  age = Serial.parseInt();
  while (Serial.available() > 0) {
    Serial.read();
  }

  Serial.println("Enter your height: "); 
  while(Serial.available()==0){}
  height = Serial.parseFloat();
  while (Serial.available() > 0) {
    Serial.read();
  }

  Serial.print("Hello ");
  Serial.print(name);
  Serial.print(" of age ");
  Serial.print(age);
  Serial.print(" years ")
  Serial.print("and height ");
  Serial.print(height);
  Serial.print(" m");
  Serial.println("");
}
