#include <REGX52.H>

// 延时 1 毫秒
void Delayms(unsigned int xms) {	//@12.000MHz
	unsigned char data i, j;
	while(xms --) {
		i = 2;
		j = 239;
		do {
			while (--j);
		} while (--i);
	}
}

void main() {
	// 寄存器 8 位变量
	unsigned char LEDNum = 0;
	
	// 独立按键控制 LED 显示二进制
	while (1) {
		// 判断 K1 按钮是否按住
		if (P3_1 == 0) {
			// 按键消抖
			Delayms(20);
			// 检测松手
			while(P3_1 == 0);
			// 按键消抖
			Delayms(20);
			
			// 默认上电高电平 1111 1111
			// 如果 P2 ++; // 溢出，0000 0000
			LEDNum ++;
			// 把临时变量按位取反赋值给 P2，LEDNum 只读取反后值不变
			P2 = ~LEDNum;
		}
	}
}