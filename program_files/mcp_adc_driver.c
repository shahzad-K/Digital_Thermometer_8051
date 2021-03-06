#include"thermo_header.h"
#include<reg51.h>

sbit clk=P1^0;
sbit din=P1^1;
sbit dout=P1^2;
sbit cs=P1^3;

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

char_u8 * read_LM35(void)
{
	int_s16 temp;
	char_u8 decimal_var;
	f_32 t1,t2;
	static char_u8 arr[]="100.00 C";	
	
	t1=(read_adc(0,0)*5.0/4096.0)*100;		//read channel 0 for +ve temperature equivalent
	t2=(read_adc(0,1)*5.0/4096.0)*100;		//read channel 1 for -ve temp.
	
	temp = t1-t2;
	decimal_var=((t1-t2)-temp)*100;
	if(temp<0)
	{
		temp -= 1;
		temp = ~temp;
		arr[0]= '-';
		decimal_var = ((t2-t1) - (char_u8)(t2-t1))*100;
	}
	else if(temp>99)
		arr[0]= '1';
	else
		arr[0]= ' ';
	
	arr[1]=(temp/10)%10 +48;
	arr[2]=temp%10 +48;
	arr[4]=decimal_var/10 +48;
	arr[5]=decimal_var%10 +48;
	arr[6]=0xDF;
	
	return arr;
}
