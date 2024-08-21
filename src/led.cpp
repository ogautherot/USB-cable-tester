/**
 * Led driver
 */

#include "led.h"

LedDriver::LedDriver(void) {
  // Disable LEDs at boot
  Disable();
}

LedDriver Led;