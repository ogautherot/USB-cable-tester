set architecture armv6-m
target extended-remote localhost:3333
mon adapter speed 1000
mon reset init
#mon halt
# Map flash at 0x00000000
mon mww 0x40048000 2
#mon flash erase_sector 0 0 31
 mon lpc8xx.cpu configure -work-area-size 2048
mon flash write_image erase lpc824-UsbCableTester.elf
#mon fast_load_image lpc824-UsbCableTester.elf
#mon fast_load
mon flash verify_image lpc824-UsbCableTester.elf
mon reset init
b _main
