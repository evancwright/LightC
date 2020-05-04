#include "vm.h"
#include <stdio.h>
#include <stdlib.h>

unsigned short getAF()
{
	unsigned short lo = 0;
	unsigned short hi = a;
	hi = hi << 8;
	lo = f;
	lo = lo & 0x00FF;
	return hi | lo;
}

unsigned short getBC()
{
	unsigned short hi = b;
	unsigned short lo = 0;
	hi = hi << 8;
	lo = c;
	lo = lo & 0x00FF;
	return hi | lo;
}

unsigned short getDE()
{
	unsigned short lo = 0;
	unsigned short hi = d;
	hi = hi << 8;
	lo = e;
	lo = lo & 0x00FF;
	return hi | lo;
}

unsigned short getHL()
{
	unsigned short lo = 0;
	unsigned short hi = h;
	hi = hi << 8;
	lo = l;
	lo = lo & 0x00FF;
	return hi | lo;
}

void setAF(unsigned short nn)
{
	a = nn/256;
	f = nn%256;
}

void setBC(unsigned short  nn)
{
	b = nn/256;
	c = nn%256;
}

void setDE(unsigned short nn)
{
	d = nn/256;
	e = nn%256;
}

void setHL(unsigned short nn)
{
	h = nn/256;
	l = nn%256;
}


byte Get8BitReg(byte r)
{
	byte mem = 0;
	if (r == 0) mem = b;
	else if (r == 1) mem = c;
	else if (r == 2) mem = d;
	else if (r == 3) mem = e;
	else if (r == 4) mem = h;
	else if (r == 5) mem = l;
	else if (r == 7) mem = a;
	return mem;
}

void SetReg8(byte rcode, byte data)
{
	if (rcode == 0) b = data;
	else if (rcode == 1) c = data;
	else if (rcode == 2) d = data;
	else if (rcode == 3) e = data;
	else if (rcode == 4) h = data;
	else if (rcode == 5) l = data;
	else if (rcode == 7) a = data;
 
}

unsigned short GetReg16(int rrcode)
{
	if (rrcode == 0) return getBC();
	else if (rrcode == 1) return getDE();
	else if (rrcode == 2) return getHL();
	else if (rrcode == 3) return sp;
	else
	{
		printf("Invalid rr code in GetReg16. pc = %x\n", pc);
		exit(0);
	}
	return 0;
}

void SetReg16(int rrcode, unsigned short data)
{
	if (rrcode == 0) setBC(data);
	else if (rrcode == 1) setDE(data);
	else if (rrcode == 2) setHL(data);
	else if (rrcode == 3) sp=data;
	else
	{
		printf("Invalid rr code in SetReg16\n");
	}
}

void SetCarryBit8(int sum)
{
	carryBit = 0;
	if (sum > 255)
		carryBit = 1;
}

void SetZeroAndSign8(byte c)
{
	zeroBit = 0;
	if (c == 0)
		zeroBit = 1;

	signBit = 0;
	if ((c & 0x80) == 0x80)
		signBit = 1;
}

void SetZeroAndSign16(unsigned short s)
{
	/*set sign and zero*/
	zeroBit = 0;
	if (s == 0)
		zeroBit = 1;

	signBit = 0;
	if ((s & 0x7FFF) != 0)
		signBit = 1;
}

//sets zero and sign flags
void SetFlagsA()
{
	if (a == 0)
		zeroBit = 1;
	else
		zeroBit = 0;

	if ((a & 128) == 1)
		signBit = 1;
	else
		signBit = 0;
}

