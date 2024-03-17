#include <REGX52.H>

// 延时毫秒
void Delay1ms(unsigned int xms) {	//@12.000MHz
	unsigned char data i, j;
	while (xms) {
		i = 2;
		j = 239;
		
		do {
			while (--j);
		} while (--i);
		
		xms --;
	}
}

void main() {
	// LED 流水灯 plus
	while (1) {
		P2 = 0xFE; // 1111 1110 -> 只有 D1 LED 灯亮
		// 传参数控制间隔时长
		Delay1ms(1000);
		P2 = 0xFD; // 1111 1101 -> 只有 D2 LED 灯亮
		Delay1ms(1000);
		P2 = 0xFB; // 1111 1011 -> 只有 D3 LED 灯亮
		Delay1ms(100);
		P2 = 0xF7; // 1111 0111 -> 只有 D4 LED 灯亮
		Delay1ms(100);
		P2 = 0xEF; // 1110 1111 -> 只有 D5 LED 灯亮
		Delay1ms(100); 
		P2 = 0xDF; // 1101 1111 -> 只有 D6 LED 灯亮
		Delay1ms(100);
		P2 = 0xBF; // 1011 1111 -> 只有 D7 LED 灯亮
		Delay1ms(100); 
		P2 = 0x7F; // 0111 1111 -> 只有 D8 LED 灯亮
		Delay1ms(100);
	}
}
