# Trivial Bit-Bang example with FTDI chip

It is trivial LED blinking example using FTDI chip in so called
BitBang mode (basically GPIO).

HW Requirements:
- UM232H board with FTDI chip

Wiring:
- connect VIO and 3V3
- connect 5V0 and USB
- connect LED with resistor (around 470 Ohm) between pin AD0 and GND

Setup:
```bash
sudo zypper in libftdi1-devel make gcc
```

Found example at:
https://github.com/legege/libftdi/blob/master/examples/bitbang.c

