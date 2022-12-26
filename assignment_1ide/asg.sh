#!/bin/bash

cd /home/student/Desktop
sudo pio run
sudo pio -t upload



cd /home/student/Desktop
pdflatex TtoD.tex
xdg-open TtoD.pdf
 
#cd /home/shashi/Avr-gcc
#make clean
#make





