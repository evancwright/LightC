#include "regs.h"


void cp_immediate8(unsigned char val)
{
	unsigned char tempA;
	unsigned char operand;
	unsigned char result;

	zeroBit = 0;
	if (a == val)
		zeroBit = 1;

	carryBit = 0;
	if (val > a)
		carryBit = 1;

	//sign bit
	tempA = a;
	operand = val;
	operand = ~operand; //two's complement 
	operand++;
	result = tempA + operand;
	signBit = 0;
	if ( (result & 0x80) != 0)
		signBit = 1;
}

void cp_r(unsigned char regcode)
{
	unsigned char data = Get8BitReg(regcode);
	cp_immediate8(data);
}

void dec_sp()
{
	sp--;
}

void cp_n()
{
	cp_immediate8(ir[1]);
}



void cp_hl()
{
	unsigned char b = GetByte(getHL());              
	cp_immediate8(b);
}

/* compare a to memory address */

void cp_a_memory(unsigned short nn)
{
	unsigned char b = GetByte(nn);
	cp_immediate8(b);
}

void cp_ix()
{
	unsigned short addr = ix;
	addr += ir[2]; //add offfset
	cp_a_memory(addr);
}

void cp_iy()
{
	unsigned short addr = iy;
	addr += ir[2]; //add offfset
	cp_a_memory(addr);
}

void cpl()
{
	a = (unsigned char)(~a);
}
