#ifndef IACCELEROMETERMANAGER_H
#define IACCELEROMETERMANAGER_H

#include <stdint.h>
class IAccelerometerManager {
 public:
   struct measurements {
      int16_t xAxis;
      int16_t yAxis;
      int16_t zAxis;
   };

   virtual measurements getMeasurements() = 0;

 private:
};

#endif
