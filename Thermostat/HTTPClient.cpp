#include "HTTPClient.h"

HTTPClient::HTTPClient() {
  serverIP = IPAddress(192,168,1,12);
  printedNewLine = true;
}

void HTTPClient::connectToServer() {
 client.stop();
  
 Serial.println("Connecting to server");
 isConnectedToServer = client.connect(serverIP, 8080); 
 if (isConnectedToServer) {
  Serial.println("Connected successfully");
 } else {
  Serial.println("Failed to connect");
 }
}

void HTTPClient::sendGet() {
  if (!isConnectedToServer) {
    Serial.println("not connected");
    return;
  }

  Serial.println("Sending request");
  // Make a HTTP request:
  client.println("GET /");
  client.println();
  Serial.println("Sent");
}

void HTTPClient::readData() {

  if (!client.available() && !printedNewLine) {
    Serial.println();
    Serial.println("------------------------");
    printedNewLine = true;
  }

  if (client.available() && printedNewLine) {
    Serial.println();
    Serial.println("------- Response -------");
    printedNewLine = false;
  }
  
  while (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
}


