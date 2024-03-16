#include <REGX52.H>

// 点亮一个 LED
void main() {
	/* 
	软件环境：Keil 5.14.1，SCT-ISP 6.93
	单片机：普中 A2
	芯片型号：STC89C52RC
	扫描串口：USB-SERAL CH340（COM3）
	视频教程：51 单片机入门教程（B 站江科大自化协，现改名江协科技）
	
	P2(P21~P28) 8 位寄存器对于 D1~D8 8 个 LED 灯
	
	十进制 | 二进制 | 十六进制
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
	P2 = 0xFE; // 1111 1110 -> 只有 D1 LED 灯亮
 } 