#include <REGX52.H>

// ��ʱ 1 ����
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
	// �Ĵ��� 8 λ����
	unsigned char LEDNum = 0;
	
	// ������������ LED ��ʾ������
	while (1) {
		// �ж� K1 ��ť�Ƿ�ס
		if (P3_1 == 0) {
			// ��������
			Delayms(20);
			// �������
			while(P3_1 == 0);
			// ��������
			Delayms(20);
			
			// Ĭ���ϵ�ߵ�ƽ 1111 1111
			// ��� P2 ++; // �����0000 0000
			LEDNum ++;
			// ����ʱ������λȡ����ֵ�� P2��LEDNum ֻ��ȡ����ֵ����
			P2 = ~LEDNum;
		}
	}
}