/**
 * 
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*func)(void);

typedef struct DataSectionsDescriptorStruct {
  uint32_t *Src;
  uint32_t *Dest;
  uint32_t Len;
} DataSectionsDescriptorStruct;

typedef struct BssSectionsDescriptorStruct {
  uint32_t *Dest;
  uint32_t *Len;
} BssSectionsDescriptorStruct;

extern __attribute__((section(".isr_vector"))) const func vectors[];

extern DataSectionsDescriptorStruct __data_section_table;
extern BssSectionsDescriptorStruct __bss_section_table;

extern uint32_t __base_RAM[], __top_RAM[];
extern uint32_t __base_resetram[], __top_resetram[];

extern const func vectors[];
extern const func __init_array_start[];
extern const func __init_array_end[];
extern void _vStackTop(void);

int main(void);
void SystemInit(void);
void exit(int stat);

#ifdef __cplusplus
}
#endif

