#
#
#

#arm-none-eabi-gcc -nostdlib
#-L"/home/olivier/workspace/MCUXpresso_11.9.0_2144/lpc_board_nxp_lpcxpresso_824/Debug"
#-L"/home/olivier/workspace/MCUXpresso_11.9.0_2144/lpc_chip_82x/Debug"
#-Xlinker -Map="tt824.map" -Xlinker --cref 
#-Xlinker --gc-sections -Xlinker -print-memory-usage 
#-mcpu=cortex-m0 -mthumb -T tt824_Debug.ld -o "tt824.axf"
#./src/aeabi_romdiv_patch.o ./src/cr_startup_lpc82x.o ./src/crp.o 
#./src/mtb.o ./src/sysinit.o ./src/tt824.o    
#-llpc_board_nxp_lpcxpresso_824 -llpc_chip_82x


CC=arm-none-eabi-gcc
CXX=arm-none-eabi-g++

TARGET=lpc824-UsbCableTester
XTARGET=${TARGET}.elf
OBJS=obj/bootstrap.o obj/main.o obj/crp.o 
OOCDCFG=/usr/share/openocd/scripts

CFLAGS=-Og -g -mthumb -mcpu=cortex-m0 -Wall -Wextra -Iinclude
CXXFLAGS=${CFLAGS} -fno-exceptions
LDFLAGS=-nostdlib -g -Wl,-Map=${TARGET}.map -Wl,--cref -Wl,--gc-sections \
	-Wl,-print-memory-usage -mcpu=cortex-m0 -mthumb \
	-T ld/lpc824.ld
LIBS=-lgcc -lc

.PHONY: all debug openocd-server clean

all: ${XTARGET}

${XTARGET}: ${OBJS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} -o $@ ${OBJS} ${LIBS} 

obj/%.o: src/%.c
	${CC} ${CFLAGS} -c $< -o $@

obj/%.o: src/%.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

debug: openocd-server


openocd-server:
	( netstat -an | grep '^tcp' | grep  ':4444 ' || openocd -f ${OOCDCFG}/interface/ftdi/olimex-arm-usb-ocd.cfg -f ${OOCDCFG}/interface/ftdi/olimex-arm-jtag-swd.cfg -f ${OOCDCFG}/target/lpc8xx.cfg ) &

clean:
	rm -f obj/* ${TARGET}.map ${XTARGET}
