#include "vm.h"
int HasImmediateWord(byte p, byte q, byte x, byte y, byte z);
int HasImmediateByte(byte x, byte y, byte z);
int PrefixedWith1Immediate();
int IsPrefix();
int PrefixedWith2Immediates();
int PrefixedWithImmediateWord();

extern unsigned short opcode;

//Gets the instructions and operands
void fetch()
{
	//clear ir
	for (int i = 0; i < 4; i++)
		ir[i] = 0;

	
	ir[0] = GetByte(pc);
	AdvancePC();

	byte x, y, z, p, q;
	//x is 2 highest bits
	x = (byte)(ir[0] & (byte)0xC0);

	x = (byte)(x >> 6);

	//y = bits 5,4,3
	y = (byte)(ir[0] & 0x38); /* 00111000 */
	y = (byte)(y >> 3);

	//z = lowest three bits
	z = (byte)(ir[0] & 0x07);

	/*p is bits 4,5*/
	p = (byte)(ir[0] & 0x30);
	p = (byte)(p >> 4);

	/*q = bit 3*/
	q = (byte)(ir[0] & 0x08);
	q = (byte)(q >> 3);

	if (IsPrefix() == 0)
	{//1 byte op code
		opcode = ir[0];
		if (HasImmediateByte(x, y, z))
		{
			ir[1] = GetByte(pc);
			AdvancePC();
		}
		else if (HasImmediateWord(p, q, x, y, z) != 0)
		{
			ir[1] = GetByte(pc);
			AdvancePC();
			ir[2] = GetByte(pc);
			AdvancePC();
		}
	}
	else
	{//is a prefix

		ir[1] = GetByte(pc);
		opcode = (unsigned short)(ir[0] * 256 + ir[1]);

		AdvancePC();

		//how do we figure out if there's 0,1,or 2 immediates?
		if (PrefixedWith1Immediate() != 0)
		{
			ir[2] = GetByte(pc);
			AdvancePC();
		}
		else if (PrefixedWith2Immediates() !=0 )
		{
			ir[2] = GetByte(pc);
			AdvancePC();

			ir[3] = GetByte(pc);
			AdvancePC();
		}
		else if (PrefixedWithImmediateWord() !=0 )
		{
			ir[2] = GetByte(pc);
			AdvancePC();

			ir[3] = GetByte(pc);
			AdvancePC();
		}
	}

}

//for 1 byte op codes
int HasImmediateByte(byte x, byte y, byte z)
{
	if (x == 0)
	{
		if (z == 0 && y >= 2 && y <= 7)
			return 1; //rel jump
		if (z == 6) //8 bit ld immmediate
			return 1;
	}
	else if (x == 3 && z == 6)
		return 1; //add 6

	return 0;
}

//this is for 1 byte opcodes
int HasImmediateWord(byte p, byte q, byte x, byte y, byte z)
{
	if (x == 0)
	{
		if (z == 1 && q == 0)
		{
			return 1; // ld rr,nn
		}
		if (z == 2)
		{/* ld rr,nn or (nn)*/
			if (p == 2 || p == 3)
				return 1; // ld rr,nn
		}
	}
	else if (x == 3)
	{
		if (z == 2)
			return 1; //jp cc,nn

		if (z == 3 && y == 0)
			return 1; //jp nn
		if (z == 4)
			return 1; //call cc,nn
		if (z == 5 && q == 1 && p == 00)
			return 1;
	}
	return 0;
}

/* return 1 if ir[0] is a prefix for a 2 byte op code */
int IsPrefix()
{
	byte b = ir[0];
	if (b == 0xCB ||
		b == 0xDD ||
		b == 0xED ||
		b == 0xFD)
		return 1;
	else
		return 0;
}

int PrefixedWith1Immediate()
{
	if (ir[0] == 0xDD || ir[0] == 0xfd)
	{
		if (ir[1] == 0xBE ||
		ir[1] == 0x7E ||
		ir[1] == 0x46 ||
		ir[1] == 0x53 ||
		ir[1] == 0x5e ||
		ir[1] == 0x66 ||
		ir[1] == 0x6e ||
		ir[1] == 0x77 ||
		ir[1] == 0x70)
			return 1;
	}
	return 0;
}


int PrefixedWith2Immediates()
{
	//	DDCB006E  03676         bit OPEN_BIT,(ix) ; test open prop bit
	// DDCB00FE  03726                 set LOCKED_BIT,(ix)
	//  DDCB00AE  03678         res OPEN_BIT,(ix)
	//  FD360300  01467         ld (iy+3),0  ; null terminate buffer
	//  FD21BC48  01462                 ld iy,itoabuffer
	if (ir[0] == 0xFD || ir[0] == 0xDD)
	{
		if (ir[1] == 0xCB || ir[1] == 0x36)
			return 1;
	}
	else if (ir[0] == 0xED)
	{
		if (ir[1] == 0x53 )
			return 1;
	}
	return 0;
}

int PrefixedWithImmediateWord()
{
	if (ir[0] == 0xFD || ir[0] == 0xDD)
	{
		if (ir[1] == 0x22 || 
			ir[1] == 0x36 || 
			ir[1] == 0x21 || 
			ir[1] == 0x2A)
			return 1;
	}
	else if (ir[0] == 0xED)
	{
		if (ir[1] == 0x43 || 
			ir[1] == 0x53 || 
			ir[1] == 0x73 ||
			ir[1] == 0x4b ||
			ir[1] == 0x5b ||
			ir[1] == 0x7b)
			return 1;
	}
	return 0;
}
