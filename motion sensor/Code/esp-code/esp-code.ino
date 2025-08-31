/*

UNTESTED this def needs to be fixed. PCBs havent been made yet and the motion sensors havent been delivered :sob:

*/

#include <WiFi.h>
#include <WiFiUdp.h>

// Wi-Fi ssid and pass
const char* ssid = "ssid_pi";
const char* password = "password1234";

// Pi IP and UDP port
const char* udpAddress = "1.1.1.1";
const int udpPort = 4210;

// motion sensor pin
#define PIR_PIN 1

WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);

  // Wi-Fi BS
  WiFi.begin(ssid, password);
  Serial.println("Connecting to Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int motionDetected = digitalRead(PIR_PIN);

  if (motionDetected == HIGH) {
    Serial.println("Motion detected! Sending alert...");
    udp.beginPacket(udpAddress, udpPort);
    udp.print("MOTION_DETECTED");
    udp.endPacket();
    delay(2000); // Debounce delay prob needs to be shortened
  }
  delay(100);
}
