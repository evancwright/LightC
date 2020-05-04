#include "regs.h"
/* ldir */
/* load data increment repeating */


void dec_bc();
void or_a(byte rcode);

/*de<-hl until bc==0*/
void ldir()
{
	while (getBC() != 0)
	{
		byte data= GetByte(getDE());
		WriteByte(getHL(), data);        
		dec_bc();
	}
}

void neg()
{
	a = (byte)(0-a);
	SetZeroAndSign8(a);
}

void nop()
{
}

void or_r(byte rcode)
{
	or_a(rcode);
}

void or_n()
{
	or_a(ir[1]);
}

void or_a(byte rcode)
{
	int r = Get8BitReg(rcode);
	a = (byte)(a | r);
	SetZeroAndSign8(a);
}

void or_hl()
{
	byte b = GetByte(getHL());
	or_a(b);
}

/// <summary>
/// or (ix+d)
/// </summary>
void or_ix()
{
	unsigned short addr = ix;
	addr += ir[2];
	or_a(GetByte(addr));
}

/// <summary>
/// or (ix+d)
/// </summary>
void or_iy()
{
	unsigned short addr = iy;
	addr += ir[2];
	or_a(GetByte(addr));
}

