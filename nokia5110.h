/**
 * nokia5110库
 * datasheet http://pan.baidu.com/share/link?shareid=180788&uk=621573270
 * @todo 了解Vop 和混合率这类东西
 */
#ifndef _NOKIA_5110_H_
#define _NOKIA_5110_H_
#include "ascii.h" //需要的字符集
#include "spi.h" //需要的spi操作
#define NOKIA5110_DATA (1) //操作的是数据
#define NOKIA5110_CMD (0) //还是命令
#define NOKIA5110_SET_RAMADDR_Y (0b01000000)
#define NOKIA5110_SET_RAMADDR_X (0b10000000)
#define NOKIA5100_SET_Vop 	(0b10000000)
#define FUNC_SET (0b00100000) //功能设置
#define PD (1<<2)
#define V (1<<1)
#define H (1<<0)
#define DISPLAY_CONF (0b00001000) //显示模式配置
#define D (1<<2)
#define E (1<<0)
#define NOKIA5100_BASE_instruction 	(0x20) //基础指令集
#define NOKIA5100_EX_instruction 	(0x21) //扩展指令级
#define NOKIA5110_NOMAL_MODE 	(0b00001100) //普通模式
// *****  端口设定 ******
// D/-C date/command 数据还是命令选择端口 高电平=Data 低电平=Commamd
#define DDR_DC DDRB
#define PORT_DC PORTB
#define PIN_DC PB1
// /RST 复位位 低电平有效,一个低电平的脉冲用于开始的复位
#define DDR_RST DDRB
#define PORT_RST PORTB
#define PIN_RST PB2
// /CS 片选引脚  低电平有效,本例最简单方法直接接地
// LCD				ATmage8
// -RST:复位,低脉冲即可  <--->  	PB2
// CE:片选,低电平有效	<--->	这里直接接地了
// Din:LCD的数据输入 	<---> 	PB3 (MOSI/OC2)
// Clk:同步信号 		<---> 	PB5 (SCK)
// Vcc: 电源
// Gnd:地
// BL:背光 高电瓶亮,低电平瓶没,就这样
#define DDR_CS DDRB
#define PORT_CS PORTB
#define PIN_CS PB0
extern void n5_init(void);
extern void n5_clear(void);
extern void n5_mvprint(unsigned char y, unsigned char x, char *str);
extern void n5_mv(unsigned char y, unsigned char x);
extern void n5_print(char * string);
extern void n5_drawpix(unsigned char y,unsigned char x);//待完善
#endif
