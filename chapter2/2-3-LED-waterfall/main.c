#include <REGX52.H>
#include <INTRINS.H>

/*
* ��ʱ 500 ����
* STC-ISP �����ʱ����������
* ϵͳƵ�� 12 MHz����ʱ���� 1 ���룬8051 ָ� STC-Y1
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
	// LED ��ˮ������
	while (1) {
		P2 = 0xFE; // 1111 1110 -> ֻ�� D1 LED ����
		Delay500ms();
		P2 = 0xFD; // 1111 1101 -> ֻ�� D2 LED ����
		Delay500ms();
		P2 = 0xFB; // 1111 1011 -> ֻ�� D3 LED ����
		Delay500ms(); 
		P2 = 0xF7; // 1111 0111 -> ֻ�� D4 LED ����
		Delay500ms();
		P2 = 0xEF; // 1110 1111 -> ֻ�� D5 LED ����
		Delay500ms(); 
		P2 = 0xDF; // 1101 1111 -> ֻ�� D6 LED ����
		Delay500ms();
		P2 = 0xBF; // 1011 1111 -> ֻ�� D7 LED ����
		Delay500ms(); 
		P2 = 0x7F; // 0111 1111 -> ֻ�� D8 LED ����
		Delay500ms();
	}
}