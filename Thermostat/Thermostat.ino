#include "WiFiService.h"
#include "HTTPClient.h"
#include "ScreenUtils.h"
#include <Servo.h>
#include "Log.h"

#define SERVO_PIN 6
#define IS_TESTING true
#define MIN_TEMP 40
#define MAX_TEMP 80

Servo servo;
WiFiService wifiService;
HTTPClient httpClient;

void setup() {
  servo.attach(SERVO_PIN);
  
  Serial.begin(9600);

  wifiService.connectToWifi();
  httpClient.connectToServer();
  httpClient.sendGet();
  
}

void loop() {
  httpClient.readData();
}

void setTemp(int temp) {
  if (temp < MIN_TEMP || temp > MAX_TEMP) {
    return;
  }

  turnDialToTemp(temp);

  String tempStr = String("Temp set to ") + temp;
  Log::debug(tempStr);
  
  printMsg(tempStr);
}

int turnDialToTemp(int temp) {
  servo.write(tempToAngle(temp));
}

int tempToAngle(int temp) {
  int scaledAngle = map(temp, 40, 80, 8, 162);
  
  #if IS_TESTING
  return scaledAngle;
  #else
  return 180 - scaledAngle;
  #endif
}

