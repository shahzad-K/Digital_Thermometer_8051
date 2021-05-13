#include"thermo_header.h"
	
void set_rtc(void)	//setting RTC
{
	//byte_write(0xD0, 0x3, 0x1);		//set particular day
	byte_write(0xD0, 0x2, 0x69);		//0x2 for hrs
	byte_write(0xD0, 0x1, 0x28);		//0x1 for mins
	byte_write(0xD0, 0x0, 0x0);		//0x0 for sec
}	

char_u8 * read_time(void)
{
	static char_u8 time[12];
	char_u8 hh,mm,ss,hour,minutes,seconds;
	hh=byte_read(0xD0, 0x2);
	mm=byte_read(0xD0, 0x1);
	ss=byte_read(0xD0, 0x0);
	
	hour = ((hh & 0x1F)>>4)*10 + (hh & 0x0F);
	minutes = (((mm & 0xF0)>>4)*10) +  (mm & 0x0F);
	seconds = (((ss & 0xF0)>>4)*10) +  (ss & 0x0F);
	
	time[0] = hour/10+48;
	time[1] = hour%10+48;
	time[2] = ':';
	
	time[3] = minutes/10+48;
	time[4] = minutes%10+48;
	time[5] = ':';
	
	time[6] = seconds/10+48;
	time[7] = seconds%10+48;
	time[8] = ' ';
	if((hh>>5&1)==1)
		time[9] = 'P';
	else
		time[9] = 'A';
	time[10] = 'M';
	time[11] = '\0';
	
	return time;
}

char_u8 * read_date(void)
{
	static char_u8 date[13];
	char_u8 value, week[7][3]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
	
	value=byte_read(0xD0, 0x04);
	value= ((value & 0xF0) >> 4)*10 + (value & 0x0F);
	date[0]= value/10 +48;
	date[1]= value%10 +48;
	date[2]= '-';

	value=byte_read(0xD0, 0x05);
	value= ((value & 0xF0) >> 4)*10 + (value & 0x0F);
	date[3]= value/10 +48;
	date[4]= value%10 +48;
	date[5]= '-';
	
	value=byte_read(0xD0, 0x06);
	value= ((value & 0xF0) >> 4)*10 + (value & 0x0F);
	date[6]= value/10 +48;
	date[7]= value%10 +48;
	date[8]= ' ';

	value=byte_read(0xD0, 0x03);
	date[9]= week[value-1][0];
	date[10]= week[value-1][1];
	date[11]= week[value-1][2];
	date[12]='\0';
	return date;
}

