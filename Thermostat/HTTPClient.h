#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <WiFi101.h>

class HTTPClient {
  boolean isConnectedToServer;
  IPAddress serverIP;
  WiFiClient client;
  boolean printedNewLine;

public:
  HTTPClient();
  void connectToServer();
  void sendGet();
  void readData();
};

#endif
