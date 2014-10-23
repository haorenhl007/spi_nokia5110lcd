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
	n5_init();
#if 0
	char str[]=" ";
	int i;
	for(i=' ';i<='z'+1;i++){
		n5_print(str);
		str[0]++;
		_delay_ms(10);
	}
	n5_mvprint(0,0,"hello,world");
#endif
#if 1
	int i=0;
	_delay_ms(500);
	while(1){
		n5_drawpix(i++,1);
		_delay_ms(500);
	}
	//n5_drawpix(0,2);
	//n5_drawpix(0,3);
	//n5_drawpix(1,4);
	//n5_drawpix(2,5);
	//n5_drawpix(2,6);
	//n5_drawpix(3,7);
#endif
#if 0
	n5_mvprint(0,0,"hello,world");
	_delay_ms(500);
	n5_mvprint(1,0," hello,world");
#endif
	while (1) {
		;
	}
}

