// FUNCTION DECLARATIONS + GLOBAL VARIABLES
#ifndef LORA_RECEIVER_H
#define LORA_RECEIVER_H

#include <SPI.h>
#include <LoRa.h>

extern const int csPin;
extern const int resetPin;
extern const int irqPin;

void setupLoRa();
void sendMessage(String outgoing);
String receiveMessage();

#endif
