/**
 *
 */

#include "lpc824.h"

#include "bootstrap.h"
#include "led.h"
#include "probe.h"

// #include "testclass.h"

uint32_t systick_count = 0;

__attribute__((__used__, section(".after_vectors"))) void Nmi(void) {
  // Systick, automatic wake up
}

__attribute__((section(".after_vectors"))) void SystickISR(void) {
  // Systick, automatic wake up
  systick_count++;
}

__attribute__((__used__, section(".after_vectors"))) void HardFaultISR(void) {
  while (1) {
  }
}

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
  int cnt = 1;
  int reading;
  Led.Enable();

  while (1) {
    int stat;

    Probe.AssertPort(cnt);
    reading = Probe.SamplePort();
    stat = Probe.Check(cnt, reading);

    if (Probe.IsDisconnected()) {
      Led.Disable();
    } else {
      Led.Enable();
      Led.SetLedState(stat);
    }
    // Increment
    cnt = (cnt < 0x08) ? (cnt << 1) : 1;
    asm("wfi");
  }
}

int not_used(int increment) {
  static int calls = 0;

  calls += increment;
  return calls;
}
