#include <REGX52.H>
#include "LCD1602.h"
#include "delay.h"

int result = 0;

// LCD1602 µ÷ÊÔ¹¤¾ß
void main() {
	LCD_Init();
	LCD_ShowChar(1, 1, 'A');
	LCD_ShowString(1, 3, "Hello");
	LCD_ShowNum(1,9, 23, 2);
	LCD_ShowSignedNum(1, 12, -6, 1);
	LCD_ShowHexNum(1, 15, 0xA8, 2);
	LCD_ShowBinNum(2, 1, 0xAA, 8);
	
	while(1) {
		result ++;
		Delayms(1000);
		LCD_ShowNum(2,10, result, 4);
	}
}