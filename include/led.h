/**
 * LED driver
 */

#ifndef __LED_H_INCLUDED__
#define __LED_H_INCLUDED__

#include "lpc824.h"

#define LED_GND 14
#define LED_DPLUS 15
#define LED_DMINUS 17
#define LED_VBUS 23

#define LED_MASK(x) (1 << (x))
#define LED_GND_MASK LED_MASK(LED_GND)
#define LED_DPLUS_MASK LED_MASK(LED_DPLUS)
#define LED_DMINUS_MASK LED_MASK(LED_DMINUS)
#define LED_VBUS_MASK LED_MASK(LED_VBUS)

#define LED_ALL_MASK                                                           \
  (LED_GND_MASK | LED_DPLUS_MASK | LED_DMINUS_MASK | LED_VBUS_MASK)

class LedDriver {
public:
  // Constructor
  LedDriver();

  void Disable(void) {
    // Disable GPIO
    GPIO0->dirclr = LED_ALL_MASK;
  }

  void Enable(void) {
    // Enable GPIO
    if (LED_ALL_MASK != (GPIO0->dir & LED_ALL_MASK)) {
      GPIO0->pin = LED_ALL_MASK;
      GPIO0->dirset = LED_ALL_MASK;
    }
  }

  void SetLedState(uint8_t pattern) {
    uint32_t mask = ((pattern & 1) ? LED_GND_MASK : 0) |
                    ((pattern & 2) ? LED_DPLUS_MASK : 0) |
                    ((pattern & 4) ? LED_DMINUS_MASK : 0) |
                    ((pattern & 8) ? LED_VBUS_MASK : 0);
    GPIO0->clrmask =
        LED_GND_MASK | LED_DPLUS_MASK | LED_DMINUS_MASK | LED_VBUS_MASK;
    GPIO0->setmask = mask;
  }
};

extern LedDriver Led;

#endif // __LED_H_INCLUDED__
