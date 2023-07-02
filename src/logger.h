#include "IUartManager.h"

extern IUartManager *uartManager;

#ifdef simu

#define special_output_port (*((volatile char *)0x20))
/* This port corresponds to the "-R 0x22,-" command line option. */
#define special_input_port (*((volatile char *)0x22))
/* Poll the specified string out the debug port. */

void debug_puts(const char *str)
{
   const char *c;

   for (c = str; *c; c++)
      special_output_port = *c;
}

#define LOGGER_DEBUG(message)                                                                                                    \
   do {                                                                                                                          \
      debug_puts("[DEBUG] ");                                                                                                    \
      debug_puts(message);                                                                                                       \
      debug_puts("\n");                                                                                                          \
   } while (0)

#define LOGGER_INFO(message)                                                                                                     \
   do {                                                                                                                          \
      debug_puts("[INFO] ");                                                                                                     \
      debug_puts(message);                                                                                                       \
      debug_puts("\n");                                                                                                          \
   } while (0)

#define LOGGER_ERROR(message)                                                                                                    \
   do {                                                                                                                          \
      debug_puts("[ERROR] ");                                                                                                    \
      debug_puts(message);                                                                                                       \
      debug_puts("\n");                                                                                                          \
   } while (0)

#else

#define LOGGER_DEBUG(message)                                                                                                    \
   do {                                                                                                                          \
      uartManager->transmitString("[DEBUG] ");                                                                                   \
      uartManager->transmitString(message);                                                                                      \
      uartManager->transmitString("\n");                                                                                         \
   } while (0)

#define LOGGER_INFO(message)                                                                                                     \
   do {                                                                                                                          \
      uartManager->transmitString(" [INFO] ");                                                                                   \
      uartManager->transmitString(message);                                                                                      \
      uartManager->transmitString("\n");                                                                                         \
   } while (0)

#define LOGGER_ERROR(message)                                                                                                    \
   do {                                                                                                                          \
      uartManager->transmitString("[ERROR] ");                                                                                   \
      uartManager->transmitString(message);                                                                                      \
      uartManager->transmitString("\n");                                                                                         \
   } while (0)

#endif
