#ifndef __thermo_header_h__
#define __thermo_header_h__

typedef unsigned char char_u8;
typedef char char_s8;
typedef unsigned int int_u16;
typedef int int_s16;
typedef unsigned long int int_u32;
typedef long int int_s32;
typedef float f_32;

extern void delay_ms(int_u16 delay);

extern void lcd_init(void);
extern void lcd_cmd(char_u8 cmd);
extern void print_str(char_u8 *p);

extern void byte_write(char_u8 SA, char_u8 MR, char_u8 Data);
extern char_u8 byte_read(char_u8 SA, char_u8 MR);
extern void start(void);
extern void stop(void);
extern void write(char_u8 ch);
extern char_u8 read(void);
extern bit ack(void);
extern bit no_ack(void);

extern char_u8 * read_LM35(void);
extern int_u16 read_adc(bit d1, bit d0);
extern char_u8 * read_time(void);
extern char_u8 * read_date(void);
extern void set_rtc();


#endif
