#include <REGX52.H>

// ��ʱ����
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
	// LED ��ˮ�� plus
	while (1) {
		P2 = 0xFE; // 1111 1110 -> ֻ�� D1 LED ����
		// ���������Ƽ��ʱ��
		Delay1ms(1000);
		P2 = 0xFD; // 1111 1101 -> ֻ�� D2 LED ����
		Delay1ms(1000);
		P2 = 0xFB; // 1111 1011 -> ֻ�� D3 LED ����
		Delay1ms(100);
		P2 = 0xF7; // 1111 0111 -> ֻ�� D4 LED ����
		Delay1ms(100);
		P2 = 0xEF; // 1110 1111 -> ֻ�� D5 LED ����
		Delay1ms(100); 
		P2 = 0xDF; // 1101 1111 -> ֻ�� D6 LED ����
		Delay1ms(100);
		P2 = 0xBF; // 1011 1111 -> ֻ�� D7 LED ����
		Delay1ms(100); 
		P2 = 0x7F; // 0111 1111 -> ֻ�� D8 LED ����
		Delay1ms(100);
	}
}
