/**
 *
 */

#include "bootstrap.h"
#include "lpc824.h"

/* __attribute__((noreturn)) */ void ResetISR(void);
__attribute__((noreturn)) void _main(void);

__attribute__((noreturn)) void JmpResetISR(void);
__attribute__((noreturn)) void JmpNmi(void);
__attribute__((noreturn)) void JmpHardFaultISR(void);

void Nmi(void) __attribute__((weak, alias("DummyISR")));
void HardFaultISR(void) __attribute__((weak, alias("DummyISR")));
void SvcISR(void) __attribute__((weak, alias("DummyISR")));
void PendsvISR(void) __attribute__((weak, alias("DummyISR")));
void SystickISR(void) __attribute__((weak, alias("DummyISR")));

void Spi0IRQ(void) __attribute__((weak, alias("DummyISR")));
void Spi1IRQ(void) __attribute__((weak, alias("DummyISR")));
void Uart0IRQ(void) __attribute__((weak, alias("DummyISR")));
void Uart1IRQ(void) __attribute__((weak, alias("DummyISR")));
void Uart2IRQ(void) __attribute__((weak, alias("DummyISR")));
void I2c1IRQ(void) __attribute__((weak, alias("DummyISR")));
void I2c0IRQ(void) __attribute__((weak, alias("DummyISR")));
void SctIRQ(void) __attribute__((weak, alias("DummyISR")));
void MrtIRQ(void) __attribute__((weak, alias("DummyISR")));
void CmpIRQ(void) __attribute__((weak, alias("DummyISR")));
void WdtIRQ(void) __attribute__((weak, alias("DummyISR")));
void BodIRQ(void) __attribute__((weak, alias("DummyISR")));
void FlashIRQ(void) __attribute__((weak, alias("DummyISR")));
void WktIRQ(void) __attribute__((weak, alias("DummyISR")));
void AdcSeqaIRQ(void) __attribute__((weak, alias("DummyISR")));
void AdcSeqbIRQ(void) __attribute__((weak, alias("DummyISR")));
void AdcThcmpIRQ(void) __attribute__((weak, alias("DummyISR")));
void AdcOvrIRQ(void) __attribute__((weak, alias("DummyISR")));
void DmaIRQ(void) __attribute__((weak, alias("DummyISR")));
void I2c2IRQ(void) __attribute__((weak, alias("DummyISR")));
void I2c3IRQ(void) __attribute__((weak, alias("DummyISR")));
void Pinint0IRQ(void) __attribute__((weak, alias("DummyISR")));
void Pinint1IRQ(void) __attribute__((weak, alias("DummyISR")));
void Pinint2IRQ(void) __attribute__((weak, alias("DummyISR")));
void Pinint3IRQ(void) __attribute__((weak, alias("DummyISR")));
void Pinint4IRQ(void) __attribute__((weak, alias("DummyISR")));
void Pinint5IRQ(void) __attribute__((weak, alias("DummyISR")));
void Pinint6IRQ(void) __attribute__((weak, alias("DummyISR")));
void Pinint7IRQ(void) __attribute__((weak, alias("DummyISR")));

/**
 *
 */
__attribute__((section(".isr_vector"))) const func vectors[] = {
    (func)_vStackTop, // 0x00
    JmpResetISR,      // 0x04
    JmpNmi,           // 0x08
    JmpHardFaultISR,  // 0x0c
    0,                // 0x10
    0,                // 0x14
    0,                // 0x18
    (func)0xefffdd6f, // 0x1c, checksum

    0,          // 0x20
    0,          // 0x24
    0,          // 0x28
    SvcISR,     // 0x2c
    0,          // 0x30
    0,          // 0x34
    PendsvISR,  // 0x38
    SystickISR, // 0x3c

    Spi0IRQ,     // 0x40 (0)
    Spi1IRQ,     // 0x44 (1)
    0,           // 0x48 (2)
    Uart0IRQ,    // 0x4c (3)
    Uart1IRQ,    // 0x50 (4)
    Uart2IRQ,    // 0x54 (5)
    0,           // 0x58 (6)
    I2c1IRQ,     // 0x5c (7)
    I2c0IRQ,     // 0x60 (8)
    SctIRQ,      // 0x64 (9)
    MrtIRQ,      // 0x68 (10)
    CmpIRQ,      // 0x6c (11)
    WdtIRQ,      // 0x70 (12)
    BodIRQ,      // 0x74 (13)
    FlashIRQ,    // 0x78 (14)
    WktIRQ,      // 0x7c (15)
    AdcSeqaIRQ,  // 0x80 (16)
    AdcSeqbIRQ,  // 0x84 (17)
    AdcThcmpIRQ, // 0x88 (18)
    AdcOvrIRQ,   // 0x8c (19)
    DmaIRQ,      // 0x90 (20)
    I2c2IRQ,     // 0x94 (21)
    I2c3IRQ,     // 0x98 (22)
    0,           // 0x9c (23)
    Pinint0IRQ,  // 0xa0 (24)
    Pinint1IRQ,  // 0xa4 (25)
    Pinint2IRQ,  // 0xa8 (26)
    Pinint3IRQ,  // 0xac (27)
    Pinint4IRQ,  // 0xb0 (28)
    Pinint5IRQ,  // 0xb4 (29)
    Pinint6IRQ,  // 0xb8 (30)
    Pinint7IRQ   // 0xbc (31)
};

__attribute__((noreturn, section(".after_vectors"))) void JmpResetISR(void) {
  asm("b ResetISR");
}

__attribute__((noreturn, section(".after_vectors"))) void JmpNmi(void) {
  asm("b Nmi");
}

__attribute__((noreturn, section(".after_vectors"))) void
JmpHardFaultISR(void) {
  asm("b HardFaultISR");
}

/**
 */
__attribute__((section(".after_vectors"))) void DummyISR(void) {
  while (1) {
  }
}

/** Reset vector
 * - Initialize memory
 */
#pragma GCC push_options
#pragma GCC optimize("optimize-sibling-calls")
__attribute__((section(".after_vectors"))) void ResetISR(void) {
  /* Data section */
  uint32_t *dest = __data_section_table.Dest;
  uint32_t *src = __data_section_table.Src;
  uint32_t *end = (uint32_t *)((uint32_t)dest + __data_section_table.Len);

  while (dest < end) {
    *dest++ = *src++;
  }

  /* BSS section */
  dest = __bss_section_table.Dest;
  end = (uint32_t *)((uint32_t)dest + __data_section_table.Len);
  while (dest < end) {
    *dest++ = 0;
  }

  while (dest < __top_RAM) {
    *dest++ = 0xdeadbeef;
  }

  // asm(".global _main\n  b _main");
  return _main();
}
#pragma GCC pop_options

__attribute__((section(".after_vectors"))) void _cold_reset(void) {
  uint32_t *dest = __base_resetram;
  uint32_t *end = __top_resetram;

  while (dest < end) {
    *dest++ = 0;
  }
}

__attribute__((section(".resetram"))) struct {
  uint16_t extrst;
  uint16_t wdt;
  uint16_t bod;
  uint16_t sysrst;
} ResetInstances = {0, 0, 0, 0};

__attribute__((section(".after_vectors"))) void _main(void) {
  uint32_t stat = SYSCON->SysRstStat;

  if (1 & stat) {
    _cold_reset();
  } else if (2 & stat) {
    ++ResetInstances.extrst;
  } else if (4 & stat) {
    ++ResetInstances.wdt;
  } else if (2 & stat) {
    ++ResetInstances.bod;
  } else if (2 & stat) {
    ++ResetInstances.sysrst;
  }
  SYSCON->SysRstStat = 0x1f;

  // Run constructors
  do {
    const func *constructor = __init_array_start;
    const func *end = __init_array_end;

    while (constructor < end) {
      (*constructor)();
      constructor++;
    }
  } while (0);

  SystemInit();

  int status = main();
  exit(status);
}

__attribute__((section(".after_vectors"))) void exit(int status) {
  (void)status;

  // freeze CPU
  while (1) {
    asm("wfi");
  }
}