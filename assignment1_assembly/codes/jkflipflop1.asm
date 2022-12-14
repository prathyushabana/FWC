.include "/sdcard/Download/codes/assignment1_assembly/codes/m328Pdef.inc"

ldi r16, 0b00100000 ;identifying output pin 5
out DDRD,r16		;declaring pins as output



ldi r16,0b00000001	;initializing j
ldi r17,0b00000001	;initializing k
ldi r18,0b00000001	;initializing q

ldi r23,0b00000001
eor r23,r18        ;q!
AND r23,r16         ;g=j&&!q
ldi r24,0b00000001 
eor r24,r17        ;!k
AND r24,r18        ;l=!k&&q
OR r24,r23         ;a=(g||l)
ldi r25,0b00000001 ;initializing clk
AND r24,r25

;following code is for displaying output
;shifting LSB in r16 to 2nd position
ldi r20, 0b00000010	;counter = 2

rcall loopw		;calling the loopw routine

out PORTD,r24		;writing output to pin 5


Start:
rjmp Start

;loop for bit shifting
loopw:	lsl r24			;left shift
	dec r20			;counter --
	brne loopw	;if counter != 0
	ret
