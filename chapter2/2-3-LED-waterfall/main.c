#include <REGX52.H>
#include <INTRINS.H>

/*
* 延时 500 毫秒
* STC-ISP 软件延时计算器生成
* 系统频率 12 MHz，点时长度 1 毫秒，8051 指令集 STC-Y1
*/
void Delay500ms(void) {	//@12.000MHz
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do {
		do {
			while (--k);
		} while (--j);
	} while (--i);
}

void main() {
	// LED 流水灯亮灭
	while (1) {
		P2 = 0xFE; // 1111 1110 -> 只有 D1 LED 灯亮
		Delay500ms();
		P2 = 0xFD; // 1111 1101 -> 只有 D2 LED 灯亮
		Delay500ms();
		P2 = 0xFB; // 1111 1011 -> 只有 D3 LED 灯亮
		Delay500ms(); 
		P2 = 0xF7; // 1111 0111 -> 只有 D4 LED 灯亮
		Delay500ms();
		P2 = 0xEF; // 1110 1111 -> 只有 D5 LED 灯亮
		Delay500ms(); 
		P2 = 0xDF; // 1101 1111 -> 只有 D6 LED 灯亮
		Delay500ms();
		P2 = 0xBF; // 1011 1111 -> 只有 D7 LED 灯亮
		Delay500ms(); 
		P2 = 0x7F; // 0111 1111 -> 只有 D8 LED 灯亮
		Delay500ms();
	}
}