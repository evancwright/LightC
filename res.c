#include <math.h>
#include "vm.h"

/* reset bit */
void res_b_r(int bit, int rcode)
{
	byte data = 0;
	byte mask = (byte)(pow(2, bit));
	mask = (byte)(~mask);
	data = Get8BitReg((byte)rcode);
	data = (byte)(data & mask);
	SetReg8((byte)rcode, data);
}

/* reset bit */
void set_b_r(int bit, int rcode)
{
	byte data = 0;
	byte mask = (byte)(pow(2, bit));
	mask = (byte)(~mask);
	data = Get8BitReg((byte)rcode);
	data = (byte)(data | mask);
	SetReg8((byte)rcode, data);
}

void res_b_ix(byte bit, byte disp)
{
	byte mask = (byte)(pow(2, bit));
	byte data= 0;
	byte offset = ir[2];
	unsigned short addr = (unsigned short)(ix + disp);

	addr += offset;
	data = GetByte(addr);


	mask = (byte)(~mask);
	data = (byte)(data & mask); 
	WriteByte(addr, data);
}

void set_b_ix(byte bit, byte disp)
{
	byte mask = (byte)(pow(2, bit));
	byte data = 0;
	byte offset = ir[2];
	unsigned short addr = (unsigned short)(ix+disp);

	addr += offset;
	data = GetByte(addr);

	data = (byte)(data | mask);
	WriteByte(addr, data);
}


void res_b_iy(byte bit, byte disp)
{
	byte mask = (byte)(pow(2, bit));
	byte data = 0;
	byte offset = ir[2];
	unsigned short addr = (unsigned short)(iy + disp);

	addr += offset;
	data = GetByte(addr);

	mask = (byte)(~mask);
	data = (byte)(data & mask);
	WriteByte(addr, data);
}

