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
	// LED 闪烁（亮灭）
	while (1) {
		P2 = 0xFE; // 1111 1110 -> 只有 D1 亮
		Delay500ms();
		P2 = 0xFF; // 1111 1111 -> D1 ~ D8 全灭
		Delay500ms();
	}
}