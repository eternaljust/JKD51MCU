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

// 寄存器 8 位变量
unsigned char LEDNum;

void main() {
	/* 独立按键控制 LED 移位
	0000 0001 -> 0x01<<0
	0000 0010 -> 0x01<<1
	0000 0100 -> 0x01<<2
	0001 0000 -> 0x01<<3
	0010 0000 -> 0x01<<4
	0100 0000 -> 0x01<<5
	1000 0000 -> 0x01<<6 
	*/
	P2 = ~0x01; // 上电 D1 灯亮
	while (1) {
		// 判断 K1 按钮是否按住
		if (P3_1 == 0) {
			// 按键消抖
			Delayms(20);
			// 检测松手
			while(P3_1 == 0);
			// 按键消抖
			Delayms(20);
			
			// +1 移位一次
			LEDNum ++;
			// 重新回到初始状态
			if (LEDNum >= 8) LEDNum = 0;
			
			// 反向逻辑，给 1 灭，给 0 亮
			P2 = ~(0x01<<LEDNum);
		}
		
		// 判断 K2 按钮是否按住
		if (P3_0 == 0) {
			// 按键消抖
			Delayms(20);
			// 检测松手
			while(P3_0 == 0);
			// 按键消抖
			Delayms(20);
			
			// 越界判断
			if (LEDNum == 0) {
				LEDNum = 7;
			} else {
				// -1 移位一次
				LEDNum --;
			}
			
			// 反向逻辑，给 1 灭，给 0 亮
			P2 = ~(0x01<<LEDNum);
		}
	}
}