#include <math.h>
#include "regs.h"

void and_immediate();

void bit_b_ix(byte b, byte d)
{
	byte mask = (byte)pow(2, b);
	byte mem = GetByte( (unsigned short)(ix+d));
	mem = (byte)(mem & mask);

	zeroBit = 0;

	if (mem == 0)
	{
		zeroBit = 1;
	}
}

void bit_b_iy(byte b, byte d)
{
	byte mask = (byte)pow(2, b);
	byte mem = GetByte((unsigned short)(iy+d));
	mem = (byte)(mem & mask);

	zeroBit = 0;
	if (mem == 0)
	{
		zeroBit = 1;
	}
}


void bit_b_hl(byte b)
{
	byte mask = (byte)pow(2, b);
	byte mem = GetByte(getHL());
	mem = (byte)(mem & mask);
	if (mem == 0) zeroBit = 1;
}

void bit_b_r(byte b, byte r)
{
	byte mask = (byte)pow(2, b);
	byte mem = Get8BitReg(r);

	zeroBit = 0;
	
	mem = (byte)(mem & mask);

	if (mem == 0)
	{
		zeroBit = 1;
	}

}

/* test bit 1,(ix+5) */

void bit_ix_iy(unsigned short rr)
{
	byte offset = ir[2];
	unsigned short addr = rr;
	byte bit = ir[3];
	addr += offset;

	/* turn the op code into the bit to test */
	bit = (byte)(bit & 32); /* chop off highest 2 bits */
	bit /= 8; /* right shift it two place */

	ir[1] = GetByte(addr);
	and_immediate();
}

void bit_n_ix()
{
	bit_ix_iy(ix);
}

void bit_n_iy()
{
	bit_ix_iy(iy);
}
