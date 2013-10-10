/**
 * main.c
 * Created: 1/14/2012 6:16:49 PM
 *  Author: Radu Motisan , radu.motisan@gmail.com ,
 * (C) 2012 , All rights reserved.
 * 最简化nokia5110操作库
 */
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "main.h"

/**
 * 主函数,显示一些东西
 * @return
 */
int main(void)
{
	nokia5110_init();
	//_delay_ms(100);
	char str[]=" ";
	int i;
	for(i=' ';i<=128;i++){
		nokia5110_print(str);
		str[0]++;
		_delay_ms(10);
	}
	nokia5110_print("123abc ");
	while (1) {
		;
	}
}

