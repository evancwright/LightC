#include "vm.h"

void jmp()
{
	pc = (unsigned short)(ir[1] + ir[2] * 256);
}

void jmpcc(int cc)
{
	if (cc)
	{
		jmp();
	}
}
 
void jmp_hl()
{
	pc = getHL();
}

void jmp_z()
{
	jmpcc(zeroBit == 1);
}

void jmp_nz()
{
	jmpcc(zeroBit == 0);
}

void jmp_c()
{
	jmpcc(carryBit == 1);
}

void jmp_nc()
{
	jmpcc(carryBit == 0);
}

void jmp_p()
{
	jmpcc(signBit == 0);
}

void jmp_m()
{
	jmpcc(signBit == 1);
}
