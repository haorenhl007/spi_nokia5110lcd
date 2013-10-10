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
#if 1
	char str[]=" ";
	int i;
	for(i=' ';i<='z'+1;i++){
		nokia5110_print(str);
		str[0]++;
		_delay_ms(10);
	}
	nokia5110_mvprint(0,0,"hello,world! ");
#endif
#if 0
	nokia5110_drawpix(0,1);
	nokia5110_drawpix(0,2);
	nokia5110_drawpix(0,3);
	nokia5110_drawpix(1,4);
	nokia5110_drawpix(2,5);
	nokia5110_drawpix(2,6);
	nokia5110_drawpix(3,7);
#endif
	while (1) {
		;
	}
}

