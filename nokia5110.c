// 5110lcd操作库
#include <avr/io.h>
#include <util/delay.h>
#include "nokia5110.h"
static void nokia5110_send1byte(char cData, char data);
static void nokia5110_write_char(unsigned char c);
/**
 * 移动光标,并在此开始打印字符串,会自动换行的
 * @param y 起始行
 * @param x 起始列
 * @param str 字符串指针
 */
void nokia5110_mvprint(unsigned char y, unsigned char x, char *str)
{
	nokia5110_mv(y, x*6);     //以一个字符为单位
	nokia5110_print(str);
}
/**
 * 写字符串
 * @param string
 */
void nokia5110_print(char * string)
{
	while (*string!='\0') {
		nokia5110_write_char(*string++);
	}
}
/**
 * 写一个字符,从ascii32开始是可显示的字符,
 * @param c
 */
static void nokia5110_write_char(unsigned char c)
{
	unsigned char line;
	c -= 32;
	for (line = 0; line<6; line++) {
		nokia5110_send1byte(NOKIA5110_DATA, font6x8[c][line]);
	}

}
/**
 * 发送一个字节
 * @param bdata 数据还是命令
 * @param cData 发送的那个字节
 */
static void nokia5110_send1byte(char bdata, char cData)
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
	//初始化SPI
	SPI_MasterInit();
	DDR_DC |= _BV(PIN_DC);     //设置D/C输出
	DDR_RST |= _BV(PIN_RST);     //设置rst输出
	//复位脉冲
	PORT_RST &= ~_BV(PIN_RST);
	_delay_ms(2);
	PORT_RST |= _BV(PIN_RST);
	//使用扩展指令集
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5100_EX_instruction);
	/// 三个扩展操作 @todo 弄清楚下面3个指令到底是什么意识.
	// 1: 设置VOP b8=1,b[7-0]=>Vop[7-0]
	//nokia5110_send1byte(NOKIA5110_CMD, 0xc8);     //偏置电压
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5100_SET_Vop|0x48);     //偏置电压
	// 2: 温度
	nokia5110_send1byte(NOKIA5110_CMD, 0b00000111);     //温度矫正
	// 3: 混合度
	nokia5110_send1byte(NOKIA5110_CMD, 0x10);     //混合度 1:48
	//设置使用基本指令集
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5100_BASE_instruction);
	//设置为普通模式
	nokia5110_send1byte(NOKIA5110_CMD, NOKIA5110_NOMAL_MODE);
	nokia5110_clear();
}

/**
 * 将光标移动至指定位置
 * @param x [0,83] 第几列
 * @param y [0,5] 第几行
 */
void nokia5110_mv(unsigned char y, unsigned char x)
{
	nokia5110_send1byte(NOKIA5110_CMD, x|NOKIA5110_SET_RAMADDR_X);     //X
	nokia5110_send1byte(NOKIA5110_CMD, y|NOKIA5110_SET_RAMADDR_Y);     //Y
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
	nokia5110_mv(0, 0);
}
/**
 * 简单画点
 * @param y y还是以8个像素为一行的行
 * @param x x则是1个像素一列
 */
void nokia5110_drawpix(unsigned char y,unsigned char x)
{
	nokia5110_send1byte(NOKIA5110_CMD, x|NOKIA5110_SET_RAMADDR_X);     //X
	nokia5110_send1byte(NOKIA5110_CMD, y|NOKIA5110_SET_RAMADDR_Y);     //Y
	nokia5110_send1byte(NOKIA5110_DATA, 0b00000001);
}
