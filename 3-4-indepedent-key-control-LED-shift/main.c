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

// �Ĵ��� 8 λ����
unsigned char LEDNum;

void main() {
	/* ������������ LED ��λ
	0000 0001 -> 0x01<<0
	0000 0010 -> 0x01<<1
	0000 0100 -> 0x01<<2
	0001 0000 -> 0x01<<3
	0010 0000 -> 0x01<<4
	0100 0000 -> 0x01<<5
	1000 0000 -> 0x01<<6 
	*/
	P2 = ~0x01; // �ϵ� D1 ����
	while (1) {
		// �ж� K1 ��ť�Ƿ�ס
		if (P3_1 == 0) {
			// ��������
			Delayms(20);
			// �������
			while(P3_1 == 0);
			// ��������
			Delayms(20);
			
			// +1 ��λһ��
			LEDNum ++;
			// ���»ص���ʼ״̬
			if (LEDNum >= 8) LEDNum = 0;
			
			// �����߼����� 1 �𣬸� 0 ��
			P2 = ~(0x01<<LEDNum);
		}
		
		// �ж� K2 ��ť�Ƿ�ס
		if (P3_0 == 0) {
			// ��������
			Delayms(20);
			// �������
			while(P3_0 == 0);
			// ��������
			Delayms(20);
			
			// Խ���ж�
			if (LEDNum == 0) {
				LEDNum = 7;
			} else {
				// -1 ��λһ��
				LEDNum --;
			}
			
			// �����߼����� 1 �𣬸� 0 ��
			P2 = ~(0x01<<LEDNum);
		}
	}
}