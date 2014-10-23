#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include "spi.h"
//初始化为主机模式
void spi_MasterInit(void)
{
	/* 设置 MOSI 和 SCK 为输出,其他为输入 */
	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK)|(1<<SS);
	/* 使能 SPI 主机模式,设置时钟速率为 fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPR1);
}
//主机模式发送(写)
void spi_MasterTransmit(char cData)
{
	/* 启动数据传输 */
	SPDR = cData;
	/* 等待传输结束 */
	while (!(SPSR &(1<<SPIF))) {
		;
	}
}
//
void spi_cs(uint8_t csport, uint8_t cspin, uint8_t stat)
{
	if (stat) {
		csport |= _BV(cspin);
	} else {
		csport &= ~_BV(cspin);
	}
}
