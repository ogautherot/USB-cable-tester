/**
 *
 */

#ifndef __PROBE_H_INCLUDED__
#define __PROBE_H_INCLUDED__

#include <stdint.h>

#include "lpc824.h"

#define USBA_GND_BIT (0)
#define USBA_GND (1 << USBA_GND_BIT)
#define USBA_DPLUS_BIT (1)
#define USBA_DPLUS (1 << USBA_DPLUS_BIT)
#define USBA_DMINUS_BIT (4)
#define USBA_DMINUS (1 << USBA_DMINUS_BIT)
#define USBA_VBUS_BIT (8)
#define USBA_VBUS (1 << USBA_VBUS_BIT)
#define USBB_GND_BIT (9)
#define USBB_GND (1 << USBB_GND_BIT)
#define USBB_DPLUS_BIT (11)
#define USBB_DPLUS (1 << USBB_DPLUS_BIT)
#define USBB_DMINUS_BIT (12)
#define USBB_DMINUS (1 << USBB_DMINUS_BIT)
#define USBB_VBUS_BIT (13)
#define USBB_VBUS (1 << USBB_VBUS_BIT)

class ProbeDriver {
public:
  ProbeDriver();

  /* Assert */
  void AssertPort(uint32_t val);

  uint32_t SamplePort(void);

  int Check(int ref, int val);

  bool IsDisconnected() {
    return (state.mask == 0) & (0 == delays[0]) & (0 == delays[1]) &
           (0 == delays[2]) & (0 == delays[3]);
  }

  uint32_t GetState(void) {
    return ((0 == delays[0]) ? 1 : 0) | ((0 == delays[1]) ? 2 : 0) |
           ((0 == delays[2]) ? 4 : 0) | ((0 == delays[1]) ? 8 : 0);
  }

private:
  union {
    uint32_t mask;
    uint8_t fields[4];
  } state;
  uint16_t delays[4];
};

extern ProbeDriver Probe;

#ifdef __cplusplus__
extern #C #{
#endif

#ifdef __cplusplus__
}
#endif

#endif // __PROBE_H_INCLUDED__