#include<Arduino.h>
int J,K,Q,D,p,clk;
void setup()
{
	pinMode(13,clk);
	pinMode(7,OUTPUT);
	pinMode(2,INPUT);
	pinMode(3,INPUT);
	pinMode(4,INPUT);
	
}
void loop()
{
	digitalWrite(13,HIGH);
	delay(1000);
	Q=digitalRead(4);
	J=digitalRead(2);
	K=digitalRead(3);
	D=J&&!Q || !K&&Q;
	digitalWrite(7,D);
	digitalWrite(13,LOW);
	delay(1000);
        p=D&&clk;
}
