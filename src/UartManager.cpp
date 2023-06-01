#include "UartManager.h"
#include <stdio.h>
#include <string.h>

UartManager::UartManager(IUartAdapter *theUartAdapter) : uartAdapter(theUartAdapter) {}

void UartManager::transmit16Bits(int16_t const dataToSend)
{
   char buffer[7];
   volatile uint8_t i = 0;
   sprintf(buffer, "%d", dataToSend);
   while (buffer[i] != '\0') {
      uartAdapter->waitForEmptyTransmitBuffer();
      uartAdapter->putChar(buffer[i]);
      i++;
   }
}
void UartManager::transmitString(const char *buffer)
{
   for (volatile uint8_t i = 0; i < strlen(buffer); i++) {
      uartAdapter->waitForEmptyTransmitBuffer();
      uartAdapter->putChar(buffer[i]);
   }
}
