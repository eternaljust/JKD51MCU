#include <REGX52.H>
#include "delay.h"
#include "nixie.h"

// Ä£¿é»¯±à³Ì
void main() {
	while (1) {
		nixie(1, 1);
		nixie(2, 2);
		nixie(3, 3);
		nixie(4, 4);
		nixie(5, 5);
		nixie(6, 6);
	}
}