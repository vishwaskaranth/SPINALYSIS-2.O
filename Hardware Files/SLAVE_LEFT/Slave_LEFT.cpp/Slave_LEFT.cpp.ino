#include <WiFi.h>

#define NUM_SENSORS 6
int sensorPins[NUM_SENSORS] = {36, 39, 34, 35, 32, 33};
const int ledPin = 2;  // Built-in LED
unsigned long lastBlink = 0;
bool ledState = false;

const char* ssid = "SensorNetwork";
const char* password = "12345678";
const char* serverIP = "192.168.4.1";
const uint16_t serverPort = 8080;

void setup() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);  // LED on initially (not connected)
    
    Serial.begin(115200);
    
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
}

void blinkLED(bool connected) {
    if (!connected) {
        unsigned long currentMillis = millis();
        if (currentMillis - lastBlink >= 250) {  // Blink every 500ms
            ledState = !ledState;
            digitalWrite(ledPin, ledState);
            lastBlink = currentMillis;
        }
    } else {
        digitalWrite(ledPin, LOW);  // LED off when connected
    }
}

void loop() {
    WiFiClient client;
    bool isConnected = false;
    
    if (client.connect(serverIP, serverPort)) {
        String dataString = "s1,";
        for (int i = 0; i < NUM_SENSORS; i++) {
            dataString += String(analogRead(sensorPins[i]));
            if (i < NUM_SENSORS - 1) {
                dataString += ",";
            }
        }
        dataString += "\n";
        
        client.print(dataString);
        client.stop();
        isConnected = true;
    } else {
        Serial.println("Connection to server failed");
    }
    
    blinkLED(isConnected);
    delay(100);
}