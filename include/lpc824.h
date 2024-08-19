/**
 * LPC824 registers mapping
 */

#include <stdint.h>

#define	__I	volatile
#define	__IO	volatile
#define	__O	volatile const

/* Base address of the various peripherals
 * */

#define MTB_BASE (0x14000000)          // Micro Trace Buffer
#define WWDT_BASE (0x40000000)         //
#define MRT_BASE (0x40004000)          //
#define WKT_BASE (0x40008000)          // Self Wake Up Timer
#define SWM_BASE (0x4000c000)          // Switch Matrix
#define ADC_BASE (0x4001c000)          // 12-bit ADC
#define PMU_BASE (0x40020000)          //
#define ACOMP_BASE (0x40024000)        // Analog Comparator
#define DMA_ITRIG_BASE (0x40028000)    // DMA Trigger Mux
#define INMUX_BASE (0x4002c000)        // Inout Mux
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
#define GPIO0_BASE (0xa0000000)        // GPIO
#define GPIO0_PINT_BASE (0xa0004000)   // GPIO PINT

#define NVIC_BASE (0xe000e000)

// MTB - Micro-Trace Buffer

// WWDT - Windowed Watch Dog Timer
typedef struct WwdtStruct	{
  __IO	uint32_t mod;		// 0x00
  __IO	uint32_t tc;		// 0x04
  __I	uint32_t feed;	// 0x08
  __O	uint32_t tv;		// 0x0c
  uint32_t :32;		// 0x10
  __IO	uint32_t warnint;	// 0x14
  __IO	uint32_t window;	// 0x18
} WwdtStruct;

#define WWDT	((WwdtStruct *) WWDT_BASE)

// MRT - Multi-Rate Timer
typedef struct MrtStruct	{
  __IO	uint32_t intval0;	// 0x00
  __O	uint32_t timer0;	// 0x04
  __IO	uint32_t ctrl0;	// 0x08
  __IO	uint32_t stat0;	// 0x0c
  __IO	uint32_t intval1;	// 0x10
  __O	uint32_t timer1;	// 0x14
  __IO	uint32_t ctrl1;	// 0x18
  __IO	uint32_t stat1;	// 0x1c
  __IO	uint32_t intval2;	// 0x20
  __O	uint32_t timer2;	// 0x24
  __IO	uint32_t ctrl2;	// 0x28
  __IO	uint32_t stat2;	// 0x2c
  __IO	uint32_t intval3;	// 0x30
  __O	uint32_t timer3;	// 0x34
  __IO	uint32_t ctrl3;	// 0x38
  __IO	uint32_t stat3;	// 0x3c
  __O	uint32_t reserved[44];
  __IO	uint32_t modcfg;	// 0xf0
  __O	uint32_t idle_ch;	// 0xf4
  __IO	uint32_t irq_flag;	// 0xf8
} MrtStruct;

#define	MRT	((MrtStruct *) MRT_BASE)

// WKT - Self Wake-Up Timer
//
typedef struct WktStruct {
  __IO	uint32_t	ctrl;
  __IO	uint32_t	count;
} WktStruct;

#define WKT	((WktStruct *) WKT_BASE)

// SW Matrix

typedef	struct	SwmStruct	{
  __IO	uint32_t pinassign0;	// 0x00
  __IO	uint32_t pinassign1;	// 0x04
  __IO	uint32_t pinassign2;	// 0x08
  __IO	uint32_t pinassign3;	// 0x0C
  __IO	uint32_t pinassign4;	// 0x10
  __IO	uint32_t pinassign5;	// 0x14
  __IO	uint32_t pinassign6;	// 0x18
  __IO	uint32_t pinassign7;	// 0x1c
  __IO	uint32_t pinassign8;	// 0x20
  __IO	uint32_t pinassign9;	// 0x24
  __IO	uint32_t pinassign10;	// 0x28
  __IO	uint32_t pinassign11;	// 0x2c
  uint32_t reserved[100];
  __IO	uint32_t pinenable0;	// 0x1c0
} SwmStruct;

#define SWM	((SwmStruct *) SWM_BASE)

// ADC

typedef struct AdcStruct {
  __IO	uint32_t ctrl;		// 0x00
  uint32_t :32;		// 0x04
  __IO	uint32_t seqa_ctrl;	// 0x08
  __IO	uint32_t seqb_ctrl;	// 0x0c
  __IO	uint32_t seqa_gdat;	// 0x10
  __IO	uint32_t seqb_gdat;	// 0x14
  uint32_t :32;		// 0x18
  uint32_t :32;		// 0x1c
  __O	uint32_t dat0;		// 0x20
  __O	uint32_t dat1;		// 0x24
  __O	uint32_t dat2;		// 0x28
  __O	uint32_t dat3;		// 0x2c
  __O	uint32_t dat4;		// 0x30
  __O	uint32_t dat5;		// 0x34
  __O	uint32_t dat6;		// 0x38
  __O	uint32_t dat7;		// 0x3c
  __O	uint32_t dat8;		// 0x40
  __O	uint32_t dat9;		// 0x44
  __O	uint32_t dat10;		// 0x48
  __O	uint32_t dat11;		// 0x4c
  __IO	uint32_t thr0_low;	// 0x50
  __IO	uint32_t thr1_low;	// 0x54
  __IO	uint32_t thr0_high;	// 0x58
  __IO	uint32_t thr1_high; 	// 0x5c
  __IO	uint32_t chan_thrsel;	// 0x60
  __IO	uint32_t inten;		// 0x64
  __IO	uint32_t flags;		// 0x68
  __IO	uint32_t trm;		// 0x6c

} AdcStruct;

#define ADC	((AdcStruct *) ADC_BASE)

// PMU

typedef struct PmuStruct	{
  __IO uint32_t	pcon;		// 0x00
  __IO uint32_t	gpreg0;		// 0x04
  __IO uint32_t	gpreg1;		// 0x08
  __IO uint32_t	gpreg2;		// 0x0c
  __IO uint32_t	gpreg3;		// 0x10
  __IO uint32_t	dpdctrl;	// 0x14
} PmuStruct;

#define	PMU	((PmuStruc *) PMU_BASE)

// Analog Comparator

typedef struct	AcompStruct	{
  __IO uint32_t	ctrl;		// 0x00
  __IO uint32_t lad;		// 0x04
} AcompStruct;

#define	ACOMP	((AcompStruct *) ACOMP_BASE)


// DMA Trigger Mux

typedef struct	DmaItrigStruct	{
  __IO uint32_t inmux0;		// 0x00
  __IO uint32_t inmux1;		// 0x04
  __IO uint32_t inmux2;		// 0x08
  __IO uint32_t inmux3;		// 0x0c
  __IO uint32_t inmux4;		// 0x10
  __IO uint32_t inmux5;		// 0x14
  __IO uint32_t inmux6;		// 0x18
  __IO uint32_t inmux7;		// 0x1c
  __IO uint32_t inmux8;		// 0x20
  __IO uint32_t inmux9;		// 0x24
  __IO uint32_t inmux10;	// 0x28
  __IO uint32_t inmux11;	// 0x2c
  __IO uint32_t inmux12;	// 0x30
  __IO uint32_t inmux13;	// 0x34
  __IO uint32_t inmux14;	// 0x38
  __IO uint32_t inmux15;	// 0x3c
  __IO uint32_t inmux16;	// 0x40
  __IO uint32_t inmux17;	// 0x44
} DmaItrigStruct;

#define DMA_ITRIG	((DmaItrigStruct *) DMA_ITRIG_BASE)


// Input Mux

typedef struct	InmuxStruct	{
  __IO uint32_t	dma_inmux0;	// 0x00
  __IO uint32_t	dma_inmux1;	// 0x04
  uint32_t :32;		// 0x08
  uint32_t :32;		// 0x0c
  uint32_t :32;		// 0x10
  uint32_t :32;		// 0x14
  uint32_t :32;		// 0x18
  uint32_t :32;		// 0x1c
  __IO uint32_t	sct0_inmux0;	// 0x20
  __IO uint32_t	sct0_inmux1;	// 0x24
  __IO uint32_t	sct0_inmux2;	// 0x28
  __IO uint32_t	sct0_inmux3;	// 0x2c

} InmuxStruct;

#define	INMUX	((InmuxStruct *) INMUX_BASE)

// Flash controller

typedef	struct FlashCtlStruct	{
  uint32_t :32;		// 0x00
  uint32_t :32;		// 0x04
  uint32_t :32;		// 0x08
  __IO uint32_t flashcfg;	// 0x0c
  uint32_t :32;		// 0x10
  uint32_t :32;		// 0x14
  uint32_t :32;		// 0x18
  uint32_t :32;		// 0x1c
  __IO uint32_t fmsstart;	// 0x20
  __IO uint32_t fmsstop;	// 0x24
  uint32_t :32;		// 0x28
  __O uint32_t fmsw0;		// 0x2c
} FlashCtrlStruct;

#define	FLASH_CTRL	((FlashCtrlStruct *) FLASH_CTRL_BASE)

// IOCON

typedef	struct IoconStruct	{
  __IO uint32_t pio0_17;	// 0x00
  __IO uint32_t pio0_13;	// 0x04
  __IO uint32_t pio0_12;	// 0x08
  __IO uint32_t pio0_05;	// 0x0c
  __IO uint32_t pio0_04;	// 0x10
  __IO uint32_t pio0_03;	// 0x14
  __IO uint32_t pio0_02;	// 0x18
  __IO uint32_t pio0_11;	// 0x1c
  __IO uint32_t pio0_10;	// 0x20
  __IO uint32_t pio0_16;	// 0x24
  __IO uint32_t pio0_15;	// 0x28
  __IO uint32_t pio0_01;	// 0x2c
  __IO uint32_t :32;
  __IO uint32_t pio0_09;	// 0x34
  __IO uint32_t pio0_08;	// 0x38
  __IO uint32_t pio0_07;	// 0x3c
  __IO uint32_t pio0_06;	// 0x40
  __IO uint32_t pio0_00;	// 0x44
  __IO uint32_t pio0_14;	// 0x48
  __IO uint32_t :32;
  __IO uint32_t pio0_28;	// 0x50
  __IO uint32_t pio0_27;	// 0x54
  __IO uint32_t pio0_26;	// 0x58
  __IO uint32_t pio0_25;	// 0x5c
  __IO uint32_t pio0_24;	// 0x60
  __IO uint32_t pio0_23;	// 0x64
  __IO uint32_t pio0_22;	// 0x68
  __IO uint32_t pio0_21;	// 0x6c
  __IO uint32_t pio0_20;	// 0x70
  __IO uint32_t pio0_19;	// 0x74
  __IO uint32_t pio0_18;	// 0x78
} IoconStruct;

#define	IOCON	((IoconStruct *) IOCON_BASE)


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

typedef struct I2cStruct	{
  __IO	uint32_t cfg;		// 0x00
  __IO	uint32_t stat;		// 0x04
  __IO	uint32_t intenset;	// 0x08
  __I	uint32_t intenclr;	// 0x0c
  __IO	uint32_t timeout;	// 0x10
  __IO	uint32_t clkdiv;	// 0x14
  __O	uint32_t intstat;	// 0x18
  uint32_t :32;		// 0x1c

  __IO	uint32_t mstctl;	// 0x20
  __IO	uint32_t msttime;	// 0x24
  __IO	uint32_t mstdat;	// 0x28
  uint32_t :32;	// 0x2c
  uint32_t :32;	// 0x30
  uint32_t :32;	// 0x34
  uint32_t :32;	// 0x38
  uint32_t :32;	// 0x3c

  __IO	uint32_t slvctl;	// 0x40
  __IO	uint32_t slvdat;	// 0x44
  __IO	uint32_t slvadr0;	// 0x48
  __IO	uint32_t slvadr1;	// 0x4c
  __IO  uint32_t slvadr2;	// 0x50
  __IO  uint32_t slvadr3;	// 0x54
  __IO  uint32_t slvqual0;	// 0x58
  uint32_t :32;		// 0x5c

  uint32_t :32;		// 0x60
  uint32_t :32;		// 0x64
  uint32_t :32;		// 0x68
  uint32_t :32;		// 0x6c
  uint32_t :32;		// 0x70
  uint32_t :32;		// 0x74
  uint32_t :32;		// 0x78
  uint32_t :32;		// 0x7c

  __O   uint32_t monrxdat;	// 0x80
} I2cStruct;

#define	I2C0	((I2cStruct *) I2C0_BASE)
#define	I2C1	((I2cStruct *) I2C1_BASE)
#define	I2C2	((I2cStruct *) I2C2_BASE)
#define	I2C3	((I2cStruct *) I2C3_BASE)


// SPI 0/1

typedef struct SpiStruct	{
  __IO	uint32_t cfg;		// 0x00
  __IO	uint32_t dly;		// 0x04
  __IO	uint32_t stat;		// 0x08
  __IO	uint32_t intenset;	// 0x0c
  __I	uint32_t intenclr;	// 0x10
  __O	uint32_t rxdat;		// 0x14
  __IO	uint32_t txdatctl;	// 0x18
  __IO	uint32_t txdat;		// 0x1c

  __IO	uint32_t txctl;		// 0x20
  __IO	uint32_t div;		// 0x24
  __O	uint32_t intstat;	// 0x28
} SpiStruct;

#define	SPI0	((SpiStruct *) SPI0_BASE)
#define	SPI1	((SpiStruct *) SPI1_BASE)


// USART 0/1/2

typedef struct	UsartStruct	{
  __IO uint32_t	cfg;		// 0x00
  __IO uint32_t	ctl;		// 0x04
  __IO uint32_t	stat;		// 0x08
  __IO uint32_t	intenset;	// 0x0c
  __I  uint32_t intenclr;	// 0x10
  __O  uint32_t rxdat;		// 0x14
  __O  uint32_t rxdatstat;	// 0x18
  __IO uint32_t	txdat;		// 0x1c

  __IO uint32_t brg;		// 0x20
  __O  uint32_t intstat;	// 0x24
  __IO uint32_t osr;		// 0x28
  __IO uint32_t addr;		// 0x2c
} UsartStruct;

#define	UART0	((UsartStruct *) USART0_BASE)
#define	UART1	((UsartStruct *) USART1_BASE)
#define	UART2	((UsartStruct *) USART2_BASE)

// CRC

typedef	struct	CrcStruct	{
  __IO uint32_t	mode;		// 0x00
  __IO uint32_t seed;		// 0x04
  __IO uint32_t sum_data;	// 0x08
} CrcStruct;

#define	CRC	((CrcStruct *) CRC_BASE)


// SCT

typedef	struct	SctStruct	{
  __IO uint32_t	config;		// 0x00
  union {			// 0x04
    __IO uint32_t ctrl;
    struct {
      __IO uint16_t ctrl_l;
      __IO uint16_t ctrl_h;
    };
  };
  union {			// 0x08
    __IO uint32_t limit;
    struct {
      __IO uint32_t limit_l;
      __IO uint32_t limit_h;
    };
  };
  union {
    __IO uint32_t halt;
    struct {
      __IO uint32_t halt_l;
      __IO uint32_t halt_h;
    };
  };
  union {
    __IO uint32_t stop;
    struct {
      __IO uint32_t stop_l;
      __IO uint32_t stop_h;
    };
  };
  union {
    __IO uint32_t start;
    struct {
      __IO uint32_t start_l;
      __IO uint32_t start_h;
    };
  };

  union {			// 0x40
    __IO uint32_t count;
    struct {
      __IO uint32_t count_l;
      __IO uint32_t count_h;
    };
  };
  union {
    __IO uint32_t state;
    struct {
      __IO uint32_t state_l;
      __IO uint32_t state_h;
    };
  };
  __O  uint32_t	input;
  union {
    __IO uint32_t regmode;
    struct {
      __IO uint32_t regmode_l;
      __IO uint32_t regmode_h;
    };
  };
  __IO uint32_t output;
  __IO uint32_t outputdirctrl;
  __IO uint32_t res;
  __IO uint32_t dmareq0;

  __IO uint32_t dmareq1;
  uint32_t reserved[35];

  __IO uint32_t even;
  __IO uint32_t evflag;
  __IO uint32_t conen;
  __IO uint32_t conflag;

  union {
    __IO uint32_t match[8];
    __IO uint32_t cap[8];
  };

  uint32_t reserved1[56];

  __IO uint32_t matchrel[8];

  uint32_t reserved2[56];

  struct {
    __IO uint32_t state;
    __IO uint32_t ctrl;
  } ev[8];

  uint32_t reserved3[48];

  struct {
    __IO uint32_t set;
    __IO uint32_t clr;
  } out[6];
} SctStruct;

#define	SCT	((SctStruct *) SCT_BASE)


// DMA

typedef struct	DmaStruct	{
  __IO uint32_t	ctrl;
  __O  uint32_t intstat;
  __IO uint32_t srambase;
  uint32_t :32;
  uint32_t :32;
  uint32_t :32;
  uint32_t :32;
  uint32_t :32;

  __IO uint32_t enableset0;
  uint32_t :32;
  __I  uint32_t enableclr0;
  uint32_t :32;
  __O  uint32_t active0;
  uint32_t :32;
  __O uint32_t busy0;
  uint32_t :32;
  
  __IO uint32_t errint0;
  uint32_t :32;
  __IO uint32_t intenset0;
  uint32_t :32;
  __IO uint32_t intenclr0;
  uint32_t :32;
  __IO uint32_t inta0;
  uint32_t :32;

  __IO uint32_t intb0;
  uint32_t :32;
  __I  uint32_t setvalid0;
  uint32_t :32;
  __I  uint32_t settrig0;
  uint32_t :32;
  __I  uint32_t abort0;
  uint32_t :32;

  uint32_t reserved[224];

  struct {
    __IO uint32_t cfg;
    __O  uint32_t ctlstat;
    __IO uint32_t xfercfg;
    uint32_t :32;
  } ch[17];
} DmaStruct;

#define	DMA	((DmaStruct *) DMA_BASE)


// GPIO

typedef struct GpioStruct {
  __IO uint8_t byte_pin0[32];
  uint32_t reserved1[1016];

  __IO uint32_t word_pin0[32];
  uint32_t reserved2[992];

  __IO uint32_t dir0;
  uint32_t reserved3[31];

  __IO uint32_t mask0;
  uint32_t reserved4[31];

  __IO uint32_t pin0;
  uint32_t reserved5[31];

  __IO uint32_t mpin0;
  uint32_t reserved6[31];

  __IO uint32_t set0;
  uint32_t reserved7[31];

  __I  uint32_t clr0;
  uint32_t reserved8[31];

  __I  uint32_t not0;
  uint32_t reserved9[31];

  __IO uint32_t dirset0;
  uint32_t reserved10[31];

  __IO uint32_t dirclr0;
  uint32_t reserved11[31];

  __I  uint32_t dirnot0;
} GpioStruct;

#define	GPIO0	((GpioStruct *) GPIO0_BASE)


// GPIO PINT

typedef	struct GpioPintStruct {
  __IO uint32_t isel;	// 0x00
  __IO uint32_t ienr;	// 0x04
  __IO uint32_t sienr;	// 0x08
  __IO uint32_t cienr;	// 0x0c
  __IO uint32_t ienf;	// 0x10
  __IO uint32_t sienf;	// 0x14
  __IO uint32_t cienf;	// 0x18
  __IO uint32_t rise;	// 0x1c
  __IO uint32_t fall;	// 0x20
  __IO uint32_t ist;	// 0x24
  __IO uint32_t pmctrl;	// 0x28
  __IO uint32_t pmsrc;	// 0x2c
  __IO uint32_t pmcfg;	// 0x30
} GpioPintStruct;

#define	GPIO0_PINT	((GpioPintStruct *) GPIO0_PINT_BASE)


// NVIC

typedef struct	NvicStruct	{
  uint32_t reserved1[64];

  __IO uint32_t iser0;
  uint32_t reserved2[31];

  __IO uint32_t icer0;
  uint32_t reserved3[31];

  __IO uint32_t ispr0;
  uint32_t reserved4[31];

  __IO uint32_t icpr0;
  uint32_t reserved5[31+64];

  __IO uint32_t ipr[8];
} NvicStruct;

#define NVIC	((NvicStruct *) NVIC_BASE)


// SysTick

typedef	struct SystickStruct	{
  __IO uint32_t csr;
  __IO uint32_t rvr;
  __IO uint32_t cvr;
  __IO uint32_t calib;
} SystickStruct;

#define	SYSTICK	((SystickStruct *) SYSTICK_BASE)


