#include <REGX52.H>

// ��ʱ 1 ���� 
void Delayms(unsigned int xms) {	//@12.000MHz
	unsigned char data i, j;
	while(xms)
	{
		i = 2;
		j = 239;
		do {
			while (--j);
		} while (--i);

		xms --;
	}
}

void main() {
	// ������������ LED ״̬
	while (1) {
		// �ж� D1 ��ť�Ƿ�ס�
		if(P3_1 == 0) {
			// ��������
			Delayms(20);
			// �������
			while(P3_1 == 0);
			// ��������
			Delayms(20);
			// ��λȡ��������
			P2_0 = ~P2_0;
		}
	}
}