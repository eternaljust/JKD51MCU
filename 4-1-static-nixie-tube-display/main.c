#include <REGX52.H>

/*
* 数码管数字：0 1 2 3 4 5 6 7 8 9
* COM 显示顺序：dp g f e d c b a
* 0：a1 b1 c1 d1 e1 f1 g0 dp0 -> 0011 1111 -> 0x3F
* 1: a0 b1 c1 d0 e0 f0 g0 dp0 -> 0000 0110 -> 0x06
* 2: a1 b1 c0 d1 e1 f0 g1 dp0 -> 0101 1011 -> 0x5B
* 3: a1 b1 c1 d1 e0 f0 g1 dp0 -> 0100 1111 -> 0x4F
* 4: a0 b1 c1 d0 e0 f1 g1 dp0 -> 0110 0110 -> 0x66
* 5: a1 b0 c1 d1 e0 f1 g1 dp0 -> 0110 1101 -> 0x6D
* 6: a1 b0 c1 d1 e1 f1 g1 dp0 -> 0111 1101 -> 0x7D
* 7: a1 b1 c1 d0 e0 f0 g0 dp0 -> 0000 0111 -> 0x07
* 8: a1 b1 c1 d1 e1 f1 g1 dp0 -> 0111 1111 -> 0x7F
* 9: a1 b1 c1 d1 e0 f1 g1 dp0 -> 0110 1111 -> 0x6F
*/
unsigned char nixieTable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

/* 
* 数码管从左往右位置 1~8 显示数字 0~9
* 实际管位：LED8 LED7 LED6 LED5 LED4 LED3 LED2 LED1
*/
void nixie(unsigned char location, number) {
	switch (location) {
		case 1: P2_4 =1; P2_3 = 1; P2_2 = 1; break;
		case 2: P2_4 =1; P2_3 = 1; P2_2 = 0; break;
		case 3: P2_4 =1; P2_3 = 0; P2_2 = 1; break;
		case 4: P2_4 =1; P2_3 = 0; P2_2 = 0; break;
		case 5: P2_4 =0; P2_3 = 1; P2_2 = 1; break;
		case 6: P2_4 =0; P2_3 = 1; P2_2 = 0; break;
		case 7: P2_4 =0; P2_3 = 0; P2_2 = 1; break;
		case 8: P2_4 =0; P2_3 = 0; P2_2 = 0; break;
	}
	
	P0 = nixieTable[number];
}

void main() {
	// 静态数码管显示
	while (1) {
		/*
		74HC138 译码器：
		输入:   P24(C)P23(B)P22(A) (000~111 -> 0~7) ↓ 
		输出：  Y0   Y1   Y2   Y3   Y4   Y5   Y6   Y7 (1~8) ↓
		数码管: LED1 LED2 LED3 LED4 LED5 LED6 LED7 LED8
		*/
		
		/*
		74HC245 模块：
		P0 寄存器 (P00~P07) -> (dp g f e d c b a)
		COM:
		  __a__
		 |     |
		f|     |b
		 |__g__|
		 |     |
		e|     |c
		 |__d__|.dp
		_
		*/
		
		// 1.控制哪个数码管显示
		// 101 -> Y5 -> LED6
		// P2_4 = 1;
		// P2_3 = 0;
		// P2_2 = 1;
		
		/*
		  __a__
		 |     
		f|     
		 |__g__
		 |     |
		e|     |c
		 |__d__|.dp
		 
		显示数字 6:
		二进制:(dp g f e d c b a) -> (0 1 1 1 1 1 0 1)
    十六进制：0111 1101 -> 7D
		*/
		// 2.数码管显示具体的数字
		// P0 = 0x7D;
		
		// 从左到右第 8 个数码管显示数字 9
		nixie(8, 9);
		while (1) {
		}
	}
}