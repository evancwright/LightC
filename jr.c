#include "vm.h"

void jmprel()
{

	byte offset = ir[1];

	if (offset > 127)
	{//negative offset
		offset = (byte)((255 - offset) + 1); /* two's complement */
		pc = (unsigned short)(pc - offset);
	}
	else
	{
		pc = (unsigned short)(pc + offset);
	}
}

void jmprelcc(int flag)
{
	if (flag)
		jmprel();
}

void jr()
{
	jmprel();
}

void jrc()
{
	jmprelcc(carryBit == 1);
}

void jrnc()
{
	jmprelcc(carryBit == 0);
}

void jrz()
{
	jmprelcc(zeroBit == 1);
}
void jrnz()
{
	jmprelcc(zeroBit == 0);
}

