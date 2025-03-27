#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

const char* ssid = "poco";
const char* password = "karthi18";

TinyGPSPlus gps;
SoftwareSerial ss(4, 5); // RX, TX
WiFiServer server(80);

double lastLat = 0.0, lastLng = 0.0; // Store last known coordinates

void setup() {
  Serial.begin(115200);
  ss.begin(9600);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");

  Serial.print("ESP8266 IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  // Continuously read and update GPS data
  while (ss.available() > 0) {
    gps.encode(ss.read());

    // If a new valid location is received, store it
    if (gps.location.isValid()) {
      lastLat = gps.location.lat();
      lastLng = gps.location.lng();
    }
  }

  WiFiClient client = server.available();
  if (!client) return;

  Serial.println("Client connected!");

  String request = client.readStringUntil('\r');
  client.flush();

  // Get latest available GPS data
  String lat_str = "13.0827";
  String lng_str = "80.2707";
  
  if (lastLat != 0.0 && lastLng != 0.0) {
    lat_str = String(lastLat, 6);
    lng_str = String(lastLng, 6);
    Serial.print("Latitude: ");
    Serial.println(lat_str);
    Serial.print("Longitude: ");
    Serial.println(lng_str);
  } else {
    Serial.println("GPS data not yet available!");
  }

  // Send Response
  String response = "HTTP/1.1 200 OK\r\n";
  response += "Content-Type: text/plain\r\n";
  response += "Connection: close\r\n\r\n";  // Close connection to prevent waiting issues
  response += lat_str + "," + lng_str;

  client.print(response);
  delay(100);  
  client.stop();  
  Serial.println("Client disconnected");
}