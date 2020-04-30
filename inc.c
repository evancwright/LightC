#include "vm.h"
/* inc instruction */

void inc_rcode(byte code)
{
	if (code == 7) inc_a();
	else if (code == 0) inc_b();
	else if (code == 1) inc_c();
	else if (code == 2) inc_d();
	else if (code == 3) inc_e();
	else if (code == 4) inc_h();
	else if (code == 5) inc_l();
}

void inc_r(byte *r)
{
	/*set sign and zero*/
	(*r)++;

	SetZeroAndSign8(*r);
}

void inc_rr(unsigned short *rr)
{
	(*rr)++;
}

void inc_a()
{
	inc_r(&a);
}

void inc_b()
{
	inc_r(&b);
}

void inc_c()
{
	inc_r(&c);
}

void inc_d()
{
	inc_r(&d);
}

void inc_e()
{
	inc_r(&e);
}

void inc_h()
{
	inc_r(&h);
}

void inc_l()
{
	inc_r(&l);
}


void inc_bc()
{
	unsigned short temp = getBC();
	inc_rr(&temp);
	setBC(temp);
}

void inc_de()
{
	unsigned short temp = getDE();
	inc_rr(&temp);
	setDE(temp);
}

void inc_hl()
{ 
	unsigned short temp = getHL();
	inc_rr(&temp);
	setHL(temp);
}

void inc_ix()
{
	inc_rr(&ix);
}

void inc_ix_plus_d()
{
	byte d = ir[2];
	byte b = GetByte(ix + d);
	b++;
	WriteByte(ix + d, b);
	SetZeroAndSign8(b);
}

void inc_iy_plus_d()
{
	byte d = ir[2];
	byte b = GetByte((unsigned short)(iy + d));
	b++;
	WriteByte((unsigned short)(iy + d), b);
	SetZeroAndSign8(b);
}


void inc_iy()
{
	inc_rr(&iy);
}

void inc_sp()
{
	sp++;
}

void inc_hl_indexed()
{
	unsigned short addr = getHL();
	byte b = GetByte(addr);
	b++;
	SetZeroAndSign8(b);
	WriteByte(addr, b);
}
