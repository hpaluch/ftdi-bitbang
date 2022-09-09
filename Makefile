# Makefile for bitbang example

CFLAGS := $(shell libftdi1-config --cflags) -g -Wall
LDLIBS := $(shell libftdi1-config --libs)

all: bitbang

bitbang : bitbang.c

# requires sudo to have R/W access to /dev/bus/usb/BUS/DEVICE
run: bitbang
	sudo ./bitbang

clean:
	rm -f bitbang

.PHONY: all clean run
