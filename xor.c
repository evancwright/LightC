#include "vm.h"

void xor(byte r)
{
	byte temp = a;
	temp = (byte)(a ^ r);
	a = temp;
	if (a == 0)
		zeroBit = 1;
	else
		zeroBit = 0;
}