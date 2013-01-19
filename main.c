/**
 * main.c
 * Created: 1/14/2012 6:16:49 PM
 *  Author: Radu Motisan , radu.motisan@gmail.com ,
 * (C) 2012 , All rights reserved.
 * @todo done 4路传输  使用4数据总线时仅连接 4 5 6 7高四根,数据分两次传输
 * @todo 使用任意4跟数据线//检测1换同端口其他PIN 通过,待检测其他
 * @todo done 自定义字符
 */
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "main.h"
#include "led1602.h"
//#include "spi.h"
#include "nokia5110.h"
/**
 * 主函数,显示一些东西
 * @return
 */
int main(void)
{
	//SPI_MasterInit();
	//uint8_t ch;
	//0. 初始化LCD
	//init_lcd();
	nokia5110_init();
	//_delay_ms(10);
	//nokia5110_set_pos(0,0);
	//_delay_ms(10);
	nokia5110_write_string("hello worldsdfs fsd f sd f sd f s");
	while(1)
		nokia5110_set_pos(0,0);
	//_delay_ms(2000);
	//1. 最简单的字符输出测试 (写数据)
	//set_pos(0x00);
	//write_str("hello world ");
	//while(1);
//	SPI_MasterTransmit(0b01000000,0);//Y 3 行
//	SPI_MasterTransmit(0b10000000,0);//X 2 列
//	SPI_MasterTransmit(0b00111110,1);
//	SPI_MasterTransmit(0b00001000,1);
//	SPI_MasterTransmit(0b00111110,1);
//	SPI_MasterTransmit(0b01010101,1);
//	char i=0;
//	while(1){
//		SPI_MasterTransmit(0b00111000,i);
//		i=~i;
//		_delay_ms(2);
//	}
	//set_pos(0x40);
	//write_str("hello world");
	/*
	 _delay_ms(100);
	 //2. 读取数据测试 (读数据)
	 _delay_ms(100);
	 set_pos(0x06);     //设置读取的位置,第1行6列,'w'的位置
	 _delay_ms(1000);
	 ch = get_data();
	 set_pos(0x0D);     //设置光标位置
	 set_data(ch);
	 _delay_ms(1000);
	 //3. 自定义字符测试 (写内存+读内存)
	 init_chardb();     //初始化自定义的字符集
	 set_pos(0x40);     //设置在第2行还是显示
	 for (int i = 0; i<0b111+1; i++) {
	 set_data(i);
	 //_delay_ms(50);
	 }
	 //4. 读取光标位置 (读地址/位置) I处即光标所在地址
	 _delay_ms(1000);
	 char str[5];
	 set_pos(0x4a);
	 ch=get_pos();
	 sprintf(str,"I=%02XH",ch);
	 write_str(str);
	 */
}

