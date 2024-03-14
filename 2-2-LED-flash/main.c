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
	// LED ��˸������
	while (1) {
		P2 = 0xFE; // 1111 1110 -> ֻ�� D1 ��
		Delay500ms();
		P2 = 0xFF; // 1111 1111 -> D1 ~ D8 ȫ��
		Delay500ms();
	}
}