#include<reg51.h>
#include"thermo_header.h"

#define LCD_OUT P0
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

void lcd_init(void)
{
	delay_ms(2);
	lcd_cmd(0x38);		//8-bit mode
	lcd_cmd(0x01);		//clear lcd
	lcd_cmd(0x0C);		//cursor off
}

void lcd_cmd(char_u8 cmd)
{
	LCD_OUT = cmd;
	RS = 0;		//0 - cmd ; 1 - data
	RW = 0;		//0 - wr ; 1 - rd
	EN = 1;		// high to low pulse
	delay_ms(2);
	EN = 0;
}

void print_str(char_u8 *p)
{
	RS = 1;		//0 - cmd ; 1 - data
	RW = 0;		//0 - wr ; 1 - rd
	while(*p != '\0')
	{
		LCD_OUT = *p;
		EN = 1;		// high to low pulse
		delay_ms(2);
		EN = 0;
		++p;
	}
}
void print_ch(char_u8 ch)
{
	LCD_OUT = ch;
	RS = 1;
	RW = 0;
	EN = 1;
	delay_ms(2);
	EN = 0;
}
char_u8 digit_count(int_u16 n)
{
	char_u8 i=0;
	if(n==0)
		return 1;
	for( ; n; n/=10)
		++i;
	return i;
}

void print_int(int_u16 n)
{
	char_u8 i,c = digit_count(n);
	static char_u8 arr[5]={0};
	for(i=0; i<c; ++i,n/=10)
		arr[c-i-1] = n%10 + '0';
	print_str(arr);
}

void print_float(f_32 n)
{
	int_u32 t1=n, t2=(n-t1)*100;
	print_int(t1);
	print_ch('.');
	print_int(t2);
}

