/**
 *
 */

#include "probe.h"

#define RELOAD (1000)

ProbeDriver Probe;

ProbeDriver::ProbeDriver() {
  // Constructor
  state.mask = 0;
  delays[0] = 0;
  delays[1] = 0;
  delays[2] = 0;
  delays[3] = 0;
  GPIO0->dirclr = USBA_GND | USBA_DPLUS | USBA_DMINUS | USBA_VBUS | USBB_GND |
                  USBB_DPLUS | USBB_DMINUS | USBB_VBUS;
}

void ProbeDriver::AssertPort(uint32_t val) {
  // Build mask and set port
  uint32_t sample = ((val & 1) ? USBA_GND : 0) | ((val & 2) ? USBA_DPLUS : 0) |
                    ((val & 4) ? USBA_DMINUS : 0) | ((val & 8) ? USBA_VBUS : 0);
  GPIO0->clrmask = USBA_GND | USBA_DPLUS | USBA_DMINUS | USBA_VBUS;
  GPIO0->dirclr = USBA_GND | USBA_DPLUS | USBA_DMINUS | USBA_VBUS;
  GPIO0->setmask = sample;
  GPIO0->dirset = sample;
}

uint32_t ProbeDriver::SamplePort(void) {
  // Read port and compact pattern
  uint32_t sample = GPIO0->pin;
  uint32_t ret = ((sample & USBB_GND) >> (USBB_GND_BIT)) |
                 ((sample & USBB_DPLUS) >> (USBB_DPLUS_BIT - 1)) |
                 ((sample & USBB_DMINUS) >> (USBB_DMINUS_BIT - 2)) |
                 ((sample & USBB_VBUS) >> (USBB_VBUS_BIT - 3));
  return ret;
}

/** Check the sample according to the pattern applied.
 *
 * @param ref Pattern applied
 * @param val Value read back on other end of the cable
 * @return 1 if patterns match, 0 if no bit is read, -1 if a short is detected.
 */
int ProbeDriver::Check(int ref, int val) {
  int idx = 3;
  int mask = 0x08;
  int ret = 1;

  // Compute bit index
  while (mask) {
    if (ref == mask) {
      break;
    }
    idx--;
    mask >>= 1;
  }

  for (int i = 0; i < 4; i++) {
    if (delays[i] > 0) {
      --delays[i];
    }
  }
  if (idx >= 0) {
    state.fields[idx] = val;
    if ((val & ~ref) && (state.mask != 0)) {
      delays[idx] = RELOAD;
    }
  }
  if (0 != state.mask) {
    ret = 0;
  } else if (0x08040201 != state.mask) {
    ret = -1;
  }
  return ret;
}