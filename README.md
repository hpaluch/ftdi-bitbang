# Trivial Bit-Bang example with FTDI chip

It is trivial LED blinking example using FTDI chip in so called
BitBang mode (basically GPIO).

This example uses open-source libFTDI from:
- https://www.intra2net.com/en/developer/libftdi/index.php
Please note that its API is different from (mostly) closed source
library provided by FTDI company.

HW Requirements:
- UM232H board with FTDI chip

Here is example output from `lsusb` command:
```
Bus 001 Device 007: ID 0403:6014 Future Technology Devices International, Ltd FT232H Single HS USB-UART/FIFO IC
```

Wiring:
- connect VIO and 3V3
- connect 5V0 and USB
- connect LED with resistor (around 470 Ohm) between pin AD0 and GND

Software setup - tested on openSUSE LEAP 15.4:
```bash
sudo zypper in libftdi1-devel make gcc
```
# Building

Just invoke `make`

# Running

Invoke `make run` - example output:
```
make run
sudo ./bitbang
[sudo] password for root: 
DEBUG: FTDI library ver='1.5' snapshot='unknown'
#01 Setting AD0 LED to 0
#02 Setting AD0 LED to 1
...
#09 Setting AD0 LED to 0
#10 Setting AD0 LED to 1
#11 Setting AD0 LED to 0
Exiting with ret=0
```

# Bugs

When in IDLE mode LED is ON. However I prefer to bind it to GND instead
of Power supply to avoid 3.3V vs. 5V logic issues.

# Resources

Source loosely based on official example:
- https://github.com/legege/libftdi/blob/master/examples/bitbang.c
- possible original(?)
  - http://developer.intra2net.com/git/?p=libftdi;a=blob;f=examples/bitbang.c;h=0a677723a77cd8f7ac2b4f17d8afe0376ea04d86;hb=HEAD


