/**
 * LPC824 registers mapping
 */

#include <stdint.h>

#define MTB_BASE (0x14000000)          // Micro Trace Buffer
#define WWDT_BASE (0x40000000)         //
#define MRT_BASE (0x40004000)          //
#define SWUT_BASE (0x40008000)         // Self Wake Up Timer
#define SW_MATRIX_BASE (0x4000c000)    // Switch Matrix
#define ADC_BASE (0x4001c000)          // 12-bit ADC
#define PMU_BASE (0x40020000)          //
#define AN_COMP_BASE (0x40024000)      // Analog Comparator
#define DMA_TRIG_MUX_BASE (0x40028000) // DMA Trigger Mux
#define INPUT_MUX_BASE (0x4002c000)    // Inout Mux
#define FLASH_CTRL_BASE (0x40040000)   // Flash controller
#define IOCON_BASE (0x40044000)        // IOCON
#define SYSCON_BASE (0x40048000)       // SYSCON
#define I2C0_BASE (0x40050000)         // I2C 0
#define I2C1_BASE (0x40054000)         // I2C 1
#define SPI0_BASE (0x40058000)         // SPI 0
#define SPI1_BASE (0x4005c000)         // SPI 1
#define USART0_BASE (0x40064000)       // USART 0
#define USART1_BASE (0x40068000)       // USART 1
#define USART2_BASE (0x4006c000)       // USART 2
#define I2C2_BASE (0x40070000)         // I2C 2
#define I2C3_BASE (0x40074000)         // I2C 3
#define CRC_BASE (0x50000000)          // CRC
#define SCT_BASE (0x50004000)          // SCTimer / PWM
#define DMA_BASE (0x50008000)          // DMA controller
#define GPIO_BASE (0xa0000000)         // GPIO
#define GPIO_PINT_BASE (0xa0004000)    // GPIO PINT

#define NVIC_BASE (0xe000e000)

// MTB

// WWDT

// MRT

// SWUT

// SW Matrix

// ADC

// PMU

// Analog Comparator

// DMA Trigger Mux

// Input Mux

// Flash controller

// IOCON

// SYSCON
typedef struct SysConStruct {
  uint32_t SysMemRemap; // 0x000
  uint32_t PResetCtrl;  // 0x004
  uint32_t SysPllCtrl;  // 0x008
  uint32_t SysPllStat;  // 0x00c
  uint32_t : 32;        // 0x010
  uint32_t : 32;        // 0x014
  uint32_t : 32;        // 0x018
  uint32_t : 32;        // 0x01c

  uint32_t SysOscCtrl; // 0x020
  uint32_t WdtOscCtrl; // 0x024
  uint32_t IrcCtrl;    // 0x028
  uint32_t Reserved2;  // 0x02c
  uint32_t SysRstStat; // 0x030
  uint32_t : 32;       // 0x034
  uint32_t : 32;       // 0x038
  uint32_t : 32;       // 0x03c

  uint32_t SysPllClkSel; // 0x040
  uint32_t SysPllClkUEn; // 0x044
  uint32_t : 32;         // 0x048
  uint32_t : 32;         // 0x04c
  uint32_t : 32;         // 0x050
  uint32_t : 32;         // 0x054
  uint32_t : 32;         // 0x058
  uint32_t : 32;         // 0x05c

  uint32_t : 32;         // 0x060
  uint32_t : 32;         // 0x064
  uint32_t : 32;         // 0x068
  uint32_t : 32;         // 0x06c
  uint32_t MainClkSel;   // 0x070
  uint32_t MainClkUEn;   // 0x074
  uint32_t SysShbClkDiv; // 0x078
  uint32_t : 32;         // 0x07c

  uint32_t SysAhbClkCtrl; // 0x080
  uint32_t : 32;          // 0x084
  uint32_t : 32;          // 0x088
  uint32_t : 32;          // 0x08c
  uint32_t : 32;          // 0x90
  uint32_t UartClkDiv;    // 0x094
  uint32_t : 32;          // 0x098
  uint32_t : 32;          // 0x09c

  uint32_t : 32; // 0x0a0
  uint32_t : 32; // 0x0a4
  uint32_t : 32; // 0x0a8
  uint32_t : 32; // 0x0ac
  uint32_t : 32; // 0x0b0
  uint32_t : 32; // 0x0b4
  uint32_t : 32; // 0x0b8
  uint32_t : 32; // 0x0bc

  uint32_t : 32; // 0x0c0
  uint32_t : 32; // 0x0c4
  uint32_t : 32; // 0x0c8
  uint32_t : 32; // 0x0cc
  uint32_t : 32; // 0x0d0
  uint32_t : 32; // 0x0d4
  uint32_t : 32; // 0x0d8
  uint32_t : 32; // 0x0dc

  uint32_t ClkOutSel;   // 0x0e0
  uint32_t ClkOutUEn;   // 0x0e4
  uint32_t ClkOutDiv;   // 0x0e8
  uint32_t Reserved8;   // 0x0ec
  uint32_t UartFrgDiv;  // 0x0f0
  uint32_t UartFrgMult; // 0x0f4
  uint32_t Reserved9;   // 0x0f8
  uint32_t ExtTraceCmd; // 0x0fc

  uint32_t PioPorCap0; // 0x100
  uint32_t : 32;       // 0x104
  uint32_t : 32;       // 0x108
  uint32_t : 32;       // 0x10c
  uint32_t : 32;       // 0x110
  uint32_t : 32;       // 0x114
  uint32_t : 32;       // 0x118
  uint32_t : 32;       // 0x11c

  uint32_t : 32;         // 0x120
  uint32_t : 32;         // 0x124
  uint32_t : 32;         // 0x128
  uint32_t : 32;         // 0x12c
  uint32_t : 32;         // 0x130
  uint32_t IoConClkDiv6; // 0x134
  uint32_t IoConClkDiv5; // 0x138
  uint32_t IoConClkDiv4; // 0x13c

  uint32_t IoConClkDiv3; // 0x140
  uint32_t IoConClkDiv2; // 0x144
  uint32_t IoConClkDiv1; // 0x148
  uint32_t IoConClkDiv0; // 0x14c
  uint32_t BodCtrl;      // 0x150
  uint32_t SysTckCal;    // 0x154
  uint32_t : 32;         // 0x158
  uint32_t : 32;         // 0x15c

  uint32_t : 32;       // 0x160
  uint32_t : 32;       // 0x164
  uint32_t : 32;       // 0x168
  uint32_t : 32;       // 0x16c
  uint32_t IrqLatency; // 0x170
  uint32_t NmiSrc;     // 0x174
  uint32_t PintSel0;   // 0x178
  uint32_t PintSel1;   // 0x17c

  uint32_t PintSel2; // 0x180
  uint32_t PintSel3; // 0x184
  uint32_t PintSel4; // 0x188
  uint32_t PintSel5; // 0x18c
  uint32_t PintSel6; // 0x190
  uint32_t PintSel7; // 0x194
  uint32_t : 32;     // 0x198
  uint32_t : 32;     // 0x19c

  uint32_t : 32; // 0x1a0
  uint32_t : 32; // 0x1a4
  uint32_t : 32; // 0x1a8
  uint32_t : 32; // 0x1ac
  uint32_t : 32; // 0x1b0
  uint32_t : 32; // 0x1b4
  uint32_t : 32; // 0x1b8
  uint32_t : 32; // 0x1bc

  uint32_t : 32; // 0x1c0
  uint32_t : 32; // 0x1c4
  uint32_t : 32; // 0x1c8
  uint32_t : 32; // 0x1cc
  uint32_t : 32; // 0x1d0
  uint32_t : 32; // 0x1d4
  uint32_t : 32; // 0x1d8
  uint32_t : 32; // 0x1dc

  uint32_t : 32; // 0x1e0
  uint32_t : 32; // 0x1e4
  uint32_t : 32; // 0x1e8
  uint32_t : 32; // 0x1ec
  uint32_t : 32; // 0x1f0
  uint32_t : 32; // 0x1f4
  uint32_t : 32; // 0x1f8
  uint32_t : 32; // 0x1fc

  uint32_t : 32;      // 0x200
  uint32_t StarterP0; // 0x204
  uint32_t : 32;      // 0x208
  uint32_t : 32;      // 0x20c
  uint32_t : 32;      // 0x210
  uint32_t StarterP1; // 0x214
  uint32_t : 32;      // 0x218
  uint32_t : 32;      // 0x21c

  uint32_t : 32;       // 0x220
  uint32_t : 32;       // 0x224
  uint32_t : 32;       // 0x228
  uint32_t : 32;       // 0x22c
  uint32_t PdSleepCfg; // 0x230
  uint32_t PdAwakeCfg; // 0x234
  uint32_t PdRunCfg;   // 0x238
  uint32_t Reserved15[222];
  uint32_t DeviceId; // 0x3f8
} SysConStruct;

#define SYSCON ((volatile SysConStruct *)SYSCON_BASE)

// I2C 0/1/2/3

// SPI 0/1

// USART 0/1/2

// CRC

// SCT

// DMA

// GPIO

// GPIO PINT

// NVIC

// SysTick
