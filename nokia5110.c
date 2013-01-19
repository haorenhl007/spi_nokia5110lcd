#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "spi.h"
#include "nokia5110.h"
#include "ascii.h"
/**
 * 写字符串
 * @param string
 */
void nokia5110_write_string(char * string)
{
	while(*string!='\0'){
		nokia5110_write_char(*string++);
	}
}
/**
 * 写一个字符
 * @param c
 */
void nokia5110_write_char(unsigned char c)
{
	unsigned char line;
	c -= 32;
	for (line = 0; line<6; line++){
		nokia5110_send1byte(NOKIA5110_DATA, font6x8[c][line]);
	}
}
/**
 * 发送一个字节
 * @param bdata 数据还是命令
 * @param cData 发送的那个字节
 */
void nokia5110_send1byte(char bdata, char cData)
{
	if (bdata) {     //高为数据操作
		PORT_DC |= _BV(PIN_DC);
	} else {     //command 低为命令操作
		PORT_DC &= ~_BV(PIN_DC);
	}
	SPI_MasterTransmit(cData);
}
/**
 * 初始化
 */
void nokia5110_init(void)
{
	DDR_DC |= _BV(PIN_DC);//设置D/C输出
	SPI_MasterInit();//初始化SPI
	//使用扩展指令集
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5100_EX_instruction);
	nokia5110_send1byte(NOKIA5110_CMD, 0xc8);     //偏置电压
	nokia5110_send1byte(NOKIA5110_CMD, 0b00000111);     //温度矫正
	nokia5110_send1byte(NOKIA5110_CMD, 0x10);     //混合度 1:48
	//使用基本指令集
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5100_BASE_instruction);
	//普通模式
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5110_NOMAL_MODE);
	nokia5110_clear();
}
/**
 * 设置光标位置
 * @param x [0,83] 第几列
 * @param y [0,5] 第几行
 */
void nokia5110_set_pos(unsigned char x, unsigned char y)
{
	//nokia5110_send1byte(NOKIA5110_CMD, NOKIA5110_NOMAL_MODE);
	nokia5110_send1byte(NOKIA5110_CMD, x|NOKIA5110_SET_RAMADDR_X);//X
	nokia5110_send1byte(NOKIA5110_CMD, y|NOKIA5110_SET_RAMADDR_Y);//Y
}
/**
 * 清屏
 */
void nokia5110_clear(void)
{
	int i;
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5110_NOMAL_MODE);
	for (i = 0; i<504; i++) {
		nokia5110_send1byte(NOKIA5110_DATA, 0);
	}
	nokia5110_set_pos(0,0);
}

