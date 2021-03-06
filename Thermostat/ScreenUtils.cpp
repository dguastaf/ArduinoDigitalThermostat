#include <Arduino.h>
#include <LiquidCrystal.h>

const float CELSIUS_MULT = 1.8;
const float CELSIUS_OFFSET = 32;

//Number of rows/cols in the LCD screen
const int NUM_ROWS = 2;
const int NUM_COLS = 16;

float celsiusToFahrenheit(float tempCelsius);

void printMsg(String message) {
  Serial.print("Printing: ");
  Serial.println(message);
  
  //Setup unique to my board's wiring
  LiquidCrystal lcd(10, 9, 8, 4, 3, 2);
  lcd.begin(NUM_COLS, NUM_ROWS);
  lcd.clear();
  lcd.setCursor(0,0);
  
  lcd.print(message);
}

float celsiusToFahrenheit(float celsius) {
  return celsius * CELSIUS_MULT + CELSIUS_OFFSET; 
}




