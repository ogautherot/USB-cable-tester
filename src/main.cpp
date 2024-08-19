/**
 *
 */

#include "lpc824.h"

#include "bootstrap.h"

// #include "testclass.h"

static void SetClock(void) {
  // Do nothing for now: PLL not used
}

/**
 *
 */
void SystemInit(void) {
  // Set PLL if needed
  SetClock();
}

/**
 *
 */
int main(void) {
  GPIO0->dir0 = (1 << 14) | (1 << 15) | (1 << 17) | (1 << 23);
  GPIO0->set0 = (1 << 14) | (1 << 15) | (1 << 17) | (1 << 23);
  while (1) {
    // test.inc();
    asm("wfi");
  }
}

int not_used(int increment) {
  static int calls = 0;

  calls += increment;
  return calls;
}
