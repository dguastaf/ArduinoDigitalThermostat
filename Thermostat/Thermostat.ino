

/*Hack - to make the Arduino compiler happy you have to include it here even 
though this library is not used in this file.
See http://stackoverflow.com/questions/6504211/is-it-possible-to-include-a-library-from-another-library-using-the-arduino-ide
*/
#include <LiquidCrystal.h>
#include <SPI.h>
#include <WiFi101.h>

#include "Secrets.h"
#include "ScreenUtils.h"
#include "TempReader.h"

void setup() {
  Serial.begin(9600);
 
  //Wait for wifi to connect
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  connectToWifi();
}

const float MILLS_IN_SEC = 1000.0;
const int READING_DELAY_SEC = 10; 

void loop() {
//  float temp = getTempFromSensor();
//  printToScreen(temp);
    
  //Take a reading every 30 seconds
  delay(READING_DELAY_SEC * MILLS_IN_SEC);
  
}

void connectToWifi() {
   int status = WL_IDLE_STATUS; 

  Serial.print("Connecting to WiFi... ");
    // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    return;
  }

  status = WiFi.begin(SSID, WIFI_PASSWORD);

  // if you're not connected, stop here:
  if ( status != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
    return;
  } 
  // if you are connected, print out info about the connection:
  else {
    Serial.println("Connected");
  }
}

void printMacAddress() {
  // the MAC address of your Wifi shield
  byte mac[6];                     
  Serial.print("Getting mac.. ");
  // print your MAC address:
  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  Serial.print(mac[5],HEX);
  Serial.print(":");
  Serial.print(mac[4],HEX);
  Serial.print(":");
  Serial.print(mac[3],HEX);
  Serial.print(":");
  Serial.print(mac[2],HEX);
  Serial.print(":");
  Serial.print(mac[1],HEX);
  Serial.print(":");
  Serial.println(mac[0],HEX);
}

void listNetworks() {
  // scan for nearby networks:
  Serial.println("** Scan Networks **");
  byte numSsid = WiFi.scanNetworks();

  // print the list of networks seen:
  Serial.println("number of available networks:");
  Serial.println(numSsid);

  // print the network number and name for each network found:
  for (int thisNet = 0; thisNet<numSsid; thisNet++) {
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.print(WiFi.SSID(thisNet));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    Serial.print("\tEncryption: ");
    Serial.println(WiFi.encryptionType(thisNet));
  }
}


