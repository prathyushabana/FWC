#include<avr/io.h>
#include<stdbool.h>
#include <util/delay.h> 

void clk1(){
PORTB=((1<<PB5));
_delay_ms(1000);
PORTB=((0<<PB5));
_delay_ms(1000);
}
int main(){
bool D,Q,J,K,X;
Q = (PIND & (1<<PIND3)) == (1<<PIND3);
DDRD = 0b00011100;
PORTD = 0b11100011;
DDRD = 0b00100000;
//DDRD |= (1<<DDD3);
//DDRD |=~(1<<DDD6)
//DDRD |=(1<<DDD0),,,,,,,,,,,
while(1)
   {
	  J = (PIND & (1<<PIND0)) == (1<<PIND2);	
	  K =(PIND & (1<<PIND1)) == (1<<PIND3);
          X =(PINB & (1<<PINB5)) ==(1<<PINB4);
	   
	  D = ((!Q)&&J) ||((Q)&&(!K));

	  P =D && X;
	PORTD = (D<<PD6);
        PORTD = (D<<PD4);
	
    clk1();

   }


}

