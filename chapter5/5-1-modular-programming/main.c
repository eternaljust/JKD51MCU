#include <REGX52.H>
#include "delay.h"
#include "nixie.h"

// ģ�黯���
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