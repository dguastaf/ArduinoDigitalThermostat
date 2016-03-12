#include "ScreenUtils.h"
#include "TempReader.h"
/*Hack - to make the Arduino compiler happy you have to include it here even 
though this library is not used in this file.
See http://stackoverflow.com/questions/6504211/is-it-possible-to-include-a-library-from-another-library-using-the-arduino-ide
*/
#include <LiquidCrystal.h>

void setup() {
  Serial.begin(9600);
}

const float MILLS_IN_SEC = 1000.0;
const int READING_DELAY_SEC = 30;

void loop() {
  float temp = getTempFromSensor();
  printToScreen(temp);
  
  //Take a reading every 30 seconds
  delay(READING_DELAY_SEC * MILLS_IN_SEC);
}


