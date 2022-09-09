# Trivial Bit-Bang example with FTDI chip

It is trivial LED blinking example using FTDI chip in so called
BitBang mode (basically GPIO).

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

# Resources

Source losely based on official example:
- https://github.com/legege/libftdi/blob/master/examples/bitbang.c


