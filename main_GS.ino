#include "LoRaReceiver.h"

void setup() {
    Serial.begin(9600);
    setupLoRa();
}

void loop() {
    // Check for incoming serial commands
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();

        if (command == "ping") {
            Serial.println("Sent: ping");
            sendMessage("ping\n");
        } 
        else if (command == "SD_log") {
            Serial.println("Sent: SD_log");
            sendMessage("START LOGGING\n");
        }

        else if (command == "SD_stop"){
          Serial.println("Sent: SD_stop");
          sendMessage("STOP LOGGING\n");
        }
    }

    // Check for incoming LoRa messages
    String incoming = receiveMessage();
    if (incoming.length() > 0) {
        Serial.println("Received: " + incoming);

        float RSSI = LoRa.packetRssi();
        float SNR = LoRa.packetSnr();
        Serial.print("RSSI: ");
        Serial.print(RSSI);
        Serial.print(" dBm, SNR: ");
        Serial.print(SNR);
        Serial.println(" dB");
    }
}
