#include "regs.h"

void jmprel();


/*sets z and s flags */
void dec_r(byte *r)
{
	(*r)--;
	SetZeroAndSign8(*r);
}

void dec_rr(unsigned short *rr)
{
	(*rr)--; /* flags not affected*/
}

void dec_a()
{
	byte temp = a;
	dec_r(&temp);
	a = temp;
}

void dec_b()
{
	byte temp = b;
	dec_r(&temp);
	b = temp;
}

void dec_c()
{
	byte temp = c;
	dec_r(&temp);
	c = temp;
}

void dec_d()
{
	byte temp = d;
	dec_r(&temp);
	d = temp;
}

void dec_e()
{
	byte temp = e;
	dec_r(&temp);
	e = temp;
}

void dec_h()
{
	byte temp = h;
	dec_r(&temp);
	h = temp;
}

void dec_l()
{
	byte temp = l;
	dec_r(&temp);
	l = temp;
}

void dec_bc()
{
	unsigned short temp = getBC();
	dec_rr(&temp);
	setBC(temp);
}

void dec_de()
{
	unsigned short temp = getDE();
	dec_rr(&temp);
	setDE(temp);
}


void dec_hl()
{
	unsigned short temp = getHL();
	dec_rr(&temp);
	setHL(temp);
}

void dec_ix()
{
	dec_rr(&ix);
}

void dec_iy()
{
	dec_rr(&iy);
}

void djnz()
{
	dec_b();

	if (zeroBit == 0)
		jmprel();
}

void dec_rcode(byte rcode)
{
	if (rcode == 7) dec_a();
	else if (rcode == 0) dec_b();
	else if (rcode == 1) dec_c();
	else if (rcode == 2) dec_d();
	else if (rcode == 3) dec_e();
	else if (rcode == 4) dec_h();
	else if (rcode == 5) dec_l();
}

//disable interrupts
void di()
{
}

//enable interrupts
void ei()
{
}
