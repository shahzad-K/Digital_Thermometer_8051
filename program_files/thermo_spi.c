#include"thermo_header.h"
#include<reg51.h>

sbit clk = P1^0;
sbit din = P1^1;
sbit dout = P1^2;
sbit cs = P1^3;

int_u16 read_adc(bit d1, bit d0)
{
	int_u16 temp=0;
	char_s8 i;
	
	cs=0;
	clk=0, din=1, clk=1;	//start
	clk=0, din=1, clk=1;	//single-ended
	clk=0, din=1, clk=1;	//D2 dont care
	clk=0, din=d1, clk=1;	//D1
	clk=0, din=d0, clk=1;	//D0
	
	clk=0, clk=1;	//sample
	clk=0, clk=1;	//null bit
	
	for(i=11; i>=0; --i)
	{
		clk=0;
		if(dout==1)
			temp = temp | (1<<i);
		clk=1;
	}
	cs=1;
	return temp;
}
