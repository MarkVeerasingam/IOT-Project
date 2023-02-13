#include <esp_Audio_Process.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "homepage.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

const char* ssid = "eir74877685";//"eir74877685" "Galaxy A52s 5G"
const char* password = "NB9rBE2gd8";//"NB9rBE2gd8" "iamaleech"

AudioProcess processaudio;

WebServer server(80);
//function to simulate effect
String effectDelay(){
  return " ";
}
String effectDistortion(){
  return " ";
}
String effectReverb(){
  return " ";
}

void handleRoot() {
  String message = homePagePart1;
  message += effectDelay();
  message += homePagePart2;
  message += effectDistortion();
  message += homePagePart3;
  message += effectReverb();
  
  server.send(200, "text/html", message);
}
void handleKeyPress(){
  String keyPress=server.arg("button");
  String recievedData="You Pressed: " + server.arg("button");
  Serial.println(recievedData);
  server.send(200);
}
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void audioTask(void *pvParameters) {
  for (;;) {
    processaudio.playAudio();
  }
}

void httpTask(void *pvParameters) {
  for (;;) {
    server.handleClient();
  }
}

void setup(void) {
  processaudio.prepareAudio();
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
Serial.println(ssid);
Serial.print("IP address: ");
Serial.println(WiFi.localIP());

if (MDNS.begin("esp32")) {
Serial.println("MDNS responder started");
}

server.on("/", handleRoot);
server.on("/sentKeyPressToWebServer", handleKeyPress);
server.on("/inline", []() {
server.send(200, "text/plain", "this works as well");
});

server.onNotFound(handleNotFound);

server.begin();
Serial.println("HTTP server started");
}

void loop(void) {
processaudio.playAudio();
server.handleClient();
delay(2);//allow the cpu to switch to other tasks
}
