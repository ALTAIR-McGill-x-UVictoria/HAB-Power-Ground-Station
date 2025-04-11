#include "LoRaReceiver.h"

const int csPin = 10;
const int resetPin = 20;
const int irqPin = 21;

void setupLoRa() {
    Serial.begin(9600);
    Serial.println("LoRa Receiver Ready");

    LoRa.setPins(csPin, resetPin, irqPin);

    if (!LoRa.begin(433E6)) {
        Serial.println("LoRa init failed!");
        while (true);
    }
    Serial.println("LoRa initialized!");
}

void sendMessage(String outgoing) {
    LoRa.beginPacket();
    LoRa.print(outgoing);
    LoRa.endPacket();
}

String receiveMessage() {
    int packetSize = LoRa.parsePacket();
    if (packetSize == 0) return "";  // No packet received

    String incoming = "";
    while (LoRa.available()) {
        incoming += (char)LoRa.read();
    }
    
    return incoming;
}
