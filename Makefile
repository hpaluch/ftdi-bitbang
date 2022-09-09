# Makefile for bitbang example

CFLAGS := $(shell libftdi1-config --cflags) -g -Wall
LDLIBS := $(shell libftdi1-config --libs)

all: bitbang

bitbang : bitbang.c

run: bitbang
	./bitbang

clean:
	rm -f bitbang

.PHONY: all clean run
