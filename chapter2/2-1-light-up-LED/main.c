#include <REGX52.H>

// ����һ�� LED
void main() {
	/* 
	����������Keil 5.14.1��SCT-ISP 6.93
	�����壺���� A2
	оƬ�ͺţ�STC89C52RC
	ɨ�贮�ڣ�USB-SERAL CH340��COM3��
	��Ƶ�̳̣�51 ��Ƭ�����Ž̳̣�B վ���ƴ��Ի�Э���ָ�����Э�Ƽ���
	
	P2(P21~P28) 8 λ�Ĵ������� D1~D8 8 �� LED ��
	
	ʮ���� | ������ | ʮ������
	0      | 0000   | 0
	1      | 0001   | 1
	2      | 0010   | 2
	3      | 0011   | 3
	4      | 0100   | 4
	5      | 0101   | 5
	6      | 0110   | 6
	7      | 0111   | 7
	8      | 1000   | 8
	9      | 1001   | 9
	10     | 1010   | A
	11     | 1011   | B
	11     | 1100   | C
	13     | 1101   | D
	14     | 1110   | E
	15     | 1111   | F
	*/
	P2 = 0xFE; // 1111 1110 -> ֻ�� D1 LED ����
 } 