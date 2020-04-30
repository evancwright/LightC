#include "vm.h"
#include <stdlib.h>
#include <stdio.h>

void RageDump();
byte GetByte(unsigned short addr)
{
	if (addr < RamSize)
	{
		return Ram[addr];
	}
	else
	{
		printf("OOB memory access (%x). PC=%x", addr, pc);
		RageDump();
		exit(0);
	}
   
}

unsigned short GetWord(unsigned short addr)
{
	byte lo = GetByte( (unsigned short)(addr) );
	byte hi = GetByte((unsigned short)(addr+1));
	unsigned short word = (unsigned short)( hi * 256 + lo );
	return word;
}

void WriteByte(unsigned short addr, byte b)
{
	Ram[addr] = b;
}

void WriteWord(unsigned short addr, unsigned short w)
{
	Ram[addr] = (byte)(w % 256); //lo byte 1st
	addr++;
	Ram[addr] = (byte)(w / 256);
}

void AdvancePC()
{
	pc++;
}