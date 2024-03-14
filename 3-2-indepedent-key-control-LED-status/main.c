#include <REGX52.H>

// ÑÓÊ± 1 ºÁÃë 
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
	// ¶ÀÁ¢°´¼ü¿ØÖÆ LED ×´Ì¬
	while (1) {
		// ÅĞ¶Ï D1 °´Å¥ÊÇ·ñ°´×¡¡
		if(P3_1 == 0) {
			// °´¼üÏû¶¶
			Delayms(20);
			// ¼ì²âËÉÊÖ
			while(P3_1 == 0);
			// °´¼üÏû¶¶
			Delayms(20);
			// °´Î»È¡·´£¨ÁÁÃğ£©
			P2_0 = ~P2_0;
		}
	}
}