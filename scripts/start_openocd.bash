#!/usr/bin/env bash

openocd -f /usr/share/openocd/scripts/interface/ftdi/olimex-arm-usb-ocd.cfg -f /usr/share/openocd/scripts/interface/ftdi/olimex-arm-jtag-swd.cfg -f /usr/share/openocd/scripts/target/lpc8xx.cfg

