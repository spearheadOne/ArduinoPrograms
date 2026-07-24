#include <Wire.h>
#include <Adafruit_BME280.h>
#include <SD.h>
#include <SPI.h>

Adafruit_BME280 sensor;


float temperature;
float pressure;

//sd reader pins
int csPin = 53; //chip select

File sensorData;
String fileName = "PTData.txt";


void setup() {
  sensor.begin(0x77); // 0x77 - I2C address

  pinMode(csPin, OUTPUT); 
  SD.begin(csPin);

}

void loop() {
  temperature = sensor.readTemperature();
  pressure = sensor.readPressure();

  sensorData = SD.open(fileName, FILE_WRITE);
 
  sensorData.print(temperature);
  sensorData.print(" ");
  sensorData.print("C");
 
  sensorData.print(",");
 
  sensorData.print(pressure);
  sensorData.print(" ");
  sensorData.println("PA");

  sensorData.close();

  delay(300);
}
