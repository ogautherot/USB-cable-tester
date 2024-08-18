/**
 *
 */
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
  while (1) {
    // test.inc();
    asm("wfi");
  }
}
