#include "vm.h"

void and_b()
{
	a = (byte)(a & b);
	SetFlagsA();
}

void and_immediate()
{
	a = (byte)(a & ir[1]);
	SetFlagsA();
}