#include <WiFi.h>

WiFiServer server(8080);
String sensorValues1 = "";
String sensorValues2 = "";
const int ledPin = 2;  // Built-in LED
unsigned long lastBlink = 0;
bool ledState = false;
bool displayOutput = false;  // Flag to control output display

void setup() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);  // LED on initially (no connections)
    
    Serial.begin(115200);
    
    const char *ssid = "SensorNetwork";
    const char *password = "12345678";
    
    WiFi.softAP(ssid, password);
    //Serial.println("Access Point started");
    //Serial.print("IP Address: ");
    //Serial.println(WiFi.softAPIP());
    
    server.begin();
}

void blinkLED() {
    unsigned long currentMillis = millis();
    
    // Check connection status
    bool slave1Connected = (sensorValues1 != "" && (millis() - lastBlink < 1000));
    bool slave2Connected = (sensorValues2 != "" && (millis() - lastBlink < 1000));
    
    if (!slave1Connected && !slave2Connected) {
        // Fast blink (200ms) when both not connected
        if (currentMillis - lastBlink >= 100) {
            ledState = !ledState;
            digitalWrite(ledPin, ledState);
            lastBlink = currentMillis;
        }
    } else if (!slave1Connected || !slave2Connected) {
        // Slow blink (500ms) when one not connected
        if (currentMillis - lastBlink >= 250) {
            ledState = !ledState;
            digitalWrite(ledPin, ledState);
            lastBlink = currentMillis;
        }
    } else {
        // LED off when both connected
        digitalWrite(ledPin, LOW);
    }
}

void loop() {
    WiFiClient client = server.available();
    
    // Check for Serial input
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();  // Remove any whitespace
        if (command.equalsIgnoreCase("start")) {
            displayOutput = true;
            Serial.println("1,1,1,1,1,1,1,1,1,1,1,1");
        } else if (command.equalsIgnoreCase("nope")) {
            displayOutput = false;
            Serial.println("0,0,0,0,0,0,0,0,0,0,0,0");
        }
    }
    
    if (client) {
        while (client.connected()) {
            if (client.available()) {
                String msg = client.readStringUntil('\n');
                
                if (msg.startsWith("s1,")) {
                    sensorValues1 = msg.substring(3);
                } else if (msg.startsWith("s7,")) {
                    sensorValues2 = msg.substring(3);
                }
                
                // Only display output if displayOutput is true
                if (displayOutput && sensorValues1 != "" && sensorValues2 != "") {
                    Serial.print(sensorValues1);
                    Serial.print(",");
                    Serial.print(sensorValues2);
                    Serial.println();
                }
            }
            blinkLED();
        }
        client.stop();
    }
    blinkLED();
}