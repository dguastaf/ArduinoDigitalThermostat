#include <Arduino.h>

const int SENSOR_PIN = A0;
const float VOLTAGE_MAX = 1024.0;
const float VOLTAGE_MULT = 5.0;
const float TEMP_OFFSET = 0.5;

const float CELSIUS_MULT = 1.8;
const float CELSIUS_OFFSET = 32;

//The number of readings we'll collect then compute the average
const int NUM_READINGS = 7;

/*
Takes a series of readings from the temperature sensor and then computes the average. I've found
this greatly iproves the accuracy of the measurement as the sensor is very noisy and occasionally
outputs readings that are a couple degrees off from the actual temperature. 

My board has a 10k ohm resistor between GND and the voltage output to reduce noise as suggested
in the TMP 36 datasheet.
*/
float getTempFromSensor() {
  
  int readingTotal = 0;
 
  // Collect multiple readings and keep track of the sum
  Serial.print("Readings: ");
  for (int i = 0; i < NUM_READINGS; i++) {
      int reading = analogRead(SENSOR_PIN);
      
      Serial.print(reading);
      Serial.print(" ");
      readingTotal += reading;
  }
  Serial.println();
  //Compute the average here
  int averageReading = readingTotal / NUM_READINGS;
  Serial.print("Average reading: ");
  Serial.println(averageReading);
  
  //Convert the output to the voltage
  float voltage = (averageReading / VOLTAGE_MAX) * VOLTAGE_MULT;

  //Convert the voltage to Celsius and return it
  return (voltage - TEMP_OFFSET) * 100;
}
