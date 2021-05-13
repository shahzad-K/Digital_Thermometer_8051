#include"thermo_header.h"

main()
{
	set_rtc();
	lcd_init();
	print_str("Digital Thermometer");
	while(1)
	{
		lcd_cmd(0xC0);
		print_str("Date : ");
		print_str(read_date());
		
		lcd_cmd(0x94);
		print_str("Time : ");
		print_str(read_time());
		
		lcd_cmd(0xD4);
		print_str("Temp : ");
		print_str(read_LM35());
		
	}
	
}