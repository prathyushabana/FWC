#!/bin/bash

cd /sdcard/Download/codes
pio run
#pio run -t nobuild -t upload
#
#cd /sdcard/Download/codes/assignment1_assembly/codes
#avra jkflipflop.asm
#avrdude -p atmega328p -c arduino -P /dev/ttyACM0 -b 115200 -U flash:w:jkflipflop.hex
#
#
#cd /sdcard/Download/codes/assignment__Avrgcc/codes
#make


cd /sdcard/Download/codes/assignment_1ide/docs
pdflatex TtoD.tex
termux-open TtoD.pdf


#
#cd /sdcard/Download/codes/assignment1_assembly/docs
#pdflatex TtoD.tex
#termux-open TtoD.pdf



#
#cd /sdcard/Download/codes/assignment_1_Avrgcc/docs
#pdflatex TtoD.tex
#termux-open TtoD.pdf
#

