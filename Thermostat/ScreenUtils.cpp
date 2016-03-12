#include <Arduino.h>
#include <LiquidCrystal.h>

const float CELSIUS_MULT = 1.8;
const float CELSIUS_OFFSET = 32;

//Number of rows/cols in the LCD screen
const int NUM_ROWS = 2;
const int NUM_COLS = 16;

float celsiusToFahrenheit(float tempCelsius);

void printToScreen(float tempCelsius) {
  float tempInFahrenheit = celsiusToFahrenheit(tempCelsius);

  Serial.print("Temp in fahrenheit: ");
  Serial.println(tempInFahrenheit);
  
  //Setup unique to my board's wiring
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  lcd.begin(NUM_COLS, NUM_ROWS);
  
  lcd.print("Temp: ");
  lcd.print(tempInFahrenheit);
  lcd.print(" F");
}

float celsiusToFahrenheit(float celsius) {
  return celsius * CELSIUS_MULT + CELSIUS_OFFSET; 
}




