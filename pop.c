#include "regs.h"
#include <stdio.h>

void pop_rr(int rrcode);
void pop_ix();
void pop_iy();
void push_rr(int rrcode);
void push_ix();
void push_iy();

void pop_rr(int rrcode)
{
	unsigned short lo = 0;
	unsigned short hi = 0;
	unsigned short temp = 0;
	sp++;
	lo = GetByte(sp);
	sp++;
	hi = GetByte(sp);
	hi = hi << 8;
	lo = 0x00FF & lo;
	temp = hi | lo;

	if (rrcode == 0) setBC(temp);
	else if (rrcode == 1) setDE(temp);
	else if (rrcode == 2) setHL(temp);
	else if (rrcode == 3) setAF(temp);
	 
}

void pop_ix()
{
	unsigned short lo = 0;
	unsigned short hi = 0;
	sp++;
	lo = GetByte(sp);
	sp++;
	hi = GetByte(sp);

	hi = hi << 8;
	
	ix = hi | lo;
//	printf("pop ix. ix=%x  (%2x,%2x)\n", ix, hic, loc);
}

void pop_iy()
{
	unsigned short lo = 0;
	unsigned short hi = 0;
	
	sp++;
	lo = GetByte(sp);
	sp++;
	hi = GetByte(sp);
	
	hi = hi << 8;
	
	iy = hi | lo;
}

void push_rr(int rrcode)
{
	byte lo = 0;
	byte hi = 0;
	unsigned short reg = 0;

	if (rrcode == 0) reg = getBC();
	else if (rrcode == 1) reg = getDE();
	else if (rrcode == 2) reg = getHL();
	else if (rrcode == 3) reg = getAF();
	
	lo = (byte)(reg % 256);
	hi = (byte)(reg / 256);

	WriteByte(sp,hi);
	sp--;
	
	WriteByte(sp, lo);
	sp--;

}

void push_ix()
{
	unsigned char lo = (unsigned char)(ix % 256);
	unsigned char hi = (unsigned char)(ix / 256);
//	printf("push ix. ix=%x  (%2x,%2x)\n", ix, hi, lo);

	WriteByte(sp, hi);
	sp--;

	WriteByte(sp, lo);
	sp--;            
}

void push_iy()
{
	byte lo = (byte)(iy %256);
	byte hi = (byte)(iy / 256);

	WriteByte(sp, hi);
	sp--;
	
	WriteByte(sp, lo);
	sp--;
}
