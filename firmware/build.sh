#!/bin/bash

##
## Installed in MacOS
## AVR Dude
## brew install avrdude
## 
## AVR GCC
## brew tap osx-cross/avr
## brew install avr-gcc

# First time needs to be setup fuses

# echo  "Read fuses"
# avrdude -c usbasp -p attiny84a -U lfuse:r:-:i -v -C "/usr/local/etc/avrdude.conf"

# echo  "Set fuses"
# avrdude -c usbasp -p attiny84a -U lfuse:w:0xce:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m -v -C "/usr/local/etc/avrdude.conf"

echo "Compiling files"
avr-gcc -Wall -g -Os -mmcu=attiny84a -c main.c
avr-gcc -Wall -g -Os -mmcu=attiny84a -c nfcemulator.c

echo "Linking"
avr-gcc -g -mmcu=attiny84a -o firmware.elf main.o nfcemulator.o

echo "Firmware.hex"
avr-objcopy -j .text -j .data -O ihex firmware.elf firmware.hex

echo "Burn hex"
avrdude -c usbasp -p attiny84a -U flash:w:firmware.hex:a

echo  "Clean"
rm main.o
rm nfcemulator.o
rm firmware.elf
rm firmware.hex