#ifndef _NOKIA_5110_H_
#define _NOKIA_5110_H_
#define NOKIA5110_DATA (1)
#define NOKIA5110_CMD (0)
#define NOKIA5110_SET_RAMADDR_X (0b10000000)
#define NOKIA5110_SET_RAMADDR_Y (0b01000000)
#define NOKIA5100_BASE_instruction (0x20)
#define NOKIA5100_EX_instruction (0x21)
#define NOKIA5110_NOMAL_MODE (0x0c)
#define DDR_DC DDRB
#define PORT_DC PORTB
#define PIN_DC PB1
void nokia5110_write_string(char * string);
void nokia5110_init(void);
void nokia5110_set_pos(unsigned char x,unsigned char y);
void nokia5110_clear(void);
void nokia5110_send1byte(char cData, char data);
void nokia5110_write_char(unsigned char c);
#endif
