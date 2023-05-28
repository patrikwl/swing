#include "UartManager.h"
#include <stdio.h>

UartManager::UartManager(IUartAdapter *theUartAdapter) : uartAdapter(theUartAdapter) {}

void UartManager::transmit16Bits(int16_t const dataToSend)
{
   char buffer[6];
   volatile uint8_t i = 0;
   sprintf(buffer, "%u", dataToSend);
   while (buffer[i] != '\0') {
      uartAdapter->waitForEmptyTransmitBuffer();
      uartAdapter->putChar(buffer[i]);
      i++;
   }
}
void UartManager::transmitString(const char *buffer, uint8_t const bufferSize)
{
   for (volatile uint8_t i = 0; i < bufferSize; i++) {
      uartAdapter->waitForEmptyTransmitBuffer();
      uartAdapter->putChar(buffer[i]);
   }
}
