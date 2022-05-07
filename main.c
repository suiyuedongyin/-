#include <stc8.h>
#include "lcd_12864.h"
#include "delay.h"
#include "keyboard.h"
#include "uart.h"
#include "FPM10A.h"

#define uchar unsigned char
#define uint unsigned int
	

uchar key,a;

void main()
{
	Init_ST7920();
	Delay_Ms(500); 
	DisplayUpdata0();//ÏÔÊ¾Ä¬ÈÏ²Ëµ¥  
	Delay_Ms(500); 

	
	for(a=6;a>0;a--)
	{
		key_scan();
		key_disaplay();
		Delay_Ms(60000000000);

	}
	



}