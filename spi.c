#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "spi.h"
void SPI_MasterInit(void)
{
	/* 设置 MOSI 和 SCK 为输出,其他为输入 */
	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK)|(1<<SS);
	/* 使能 SPI 主机模式,设置时钟速率为 fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPR1);
}
void SPI_MasterTransmit(char cData)
{
	/* 启动数据传输 */
	SPDR = cData;
	/* 等待传输结束 */
	while (!(SPSR &(1<<SPIF))) {
		;
	}
}
