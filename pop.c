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
	sp++;
	unsigned short lo = GetByte(sp);
	sp++;
	unsigned short hi = GetByte(sp);
	hi = hi << 8;
	lo = 0x00FF & lo;
	unsigned short temp = hi | lo;

	if (rrcode == 0b00) setBC(temp);
	else if (rrcode == 0b01) setDE(temp);
	else if (rrcode == 0b10) setHL(temp);
	else if (rrcode == 0b11) setAF(temp);
	 
}

void pop_ix()
{
	sp++;
	unsigned char loc = GetByte(sp);
	sp++;
	unsigned char hic = GetByte(sp);

	unsigned short hi = hic;
	unsigned short lo = loc;

	hi = hi << 8;
	lo = 0x00FF & lo;
	unsigned short temp = hi | lo;
	
	ix = temp;
//	printf("pop ix. ix=%x  (%2x,%2x)\n", ix, hic, loc);
}

void pop_iy()
{
	sp++;
	unsigned short lo = GetByte(sp);
	sp++;
	unsigned short hi = GetByte(sp);
	hi = hi << 8;
	lo = 0x00FF & lo;
	unsigned short temp = hi | lo;

	iy = temp;
}

void push_rr(int rrcode)
{
	unsigned short reg = 0;

	if (rrcode == 0b00) reg = getBC();
	else if (rrcode == 0b01) reg = getDE();
	else if (rrcode == 0b10) reg = getHL();
	else if (rrcode == 0b11) reg = getAF();
	
	byte lo = (byte)(reg % 256);
	byte hi = (byte)(reg / 256);

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