#include "vm.h"

	/// <summary>
	/// Add value to accumulator
	/// </summary>
	/// <param name="val"></param>
void add8(byte val)
{
	unsigned short temp = (unsigned short)(a + val);
	SetCarryBit8(temp);

	a = temp % 256;
	SetFlagsA();
}

void add16(unsigned short *tgt, unsigned short src)
{
	unsigned long temp = (unsigned int)(*tgt + src);

	carryBit = 0;
	if (temp > 65535)
	{
		carryBit = 1;
	}

	*tgt = (unsigned short)temp;
}

void add_immediate()
{
	add8(ir[1]);
}

void add_r(byte rcode)
{
	byte b = Get8BitReg(rcode);
	add8(b);
}

void add_a_n()
{
	add_immediate();
}

void add_hl_bc()
{
	unsigned short rr = getHL();
	add16(&rr, getBC());
	setHL(rr);
}


void add_hl_de()
{
	unsigned short rr = getHL();
	add16(&rr, getDE());
	setHL(rr);
}

void add_ix_bc()
{
	add16(&ix, getBC());
}

void add_ix_de()
{
	add16(&ix, getDE());
}

void add_iy_bc()
{
	add16(&iy, getBC());
}

void add_iy_de()
{
	add16(&iy, getDE());
}
