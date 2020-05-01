#include "regs.h"

void ld_r_r(byte rcode1, byte rcode2)
{
	byte b = Get8BitReg(rcode2);
	SetReg8(rcode1, b);
}
 
void ld16(unsigned short *tgt,  unsigned short src)
{
	*tgt = src;
}

void ld_r_n(byte rcode)
{
	SetReg8(rcode, ir[1]);
}

void ld_a_bc()
{
	byte b = GetByte(getBC());
	SetReg8(0x07,b);
}

void ld_a_de()
{
	byte b = GetByte(getDE());
	SetReg8(0x07, b);
}

void ld_a_hl()
{
	byte b = GetByte(getHL());
	SetReg8(0x07, b);
}

void ld_a_mm()
{
	unsigned short hi = ir[2];
	unsigned short lo = ir[1];
	unsigned short addr = 0;
	unsigned char b = 0;
	hi = hi << 8;
	lo = lo & 0x00FF;

	addr = hi | lo;
	b = GetByte(addr);
	SetReg8(0x07, b);
}


void ld_mm_a()
{
	unsigned short hi = ir[2];
	unsigned short lo = ir[1];
	unsigned short addr = 0;
	hi = hi << 8;
	lo = lo & 0x00FF;
	addr = hi | lo;
	WriteByte(addr, a);
}

void ld_r_ix(byte rcode)
{
	byte b = 0;
	unsigned short addr = ix;
	addr += ir[2];
	b = GetByte(addr);
	SetReg8(rcode, b);
}

void ld_r_iy(byte rcode)
{
	unsigned short addr = iy;
	byte b = 0;
	addr += ir[2];
	b = GetByte(addr);
	SetReg8(rcode, b);
}

void ld_bc_a()
{
	WriteByte(getBC(), a);            //no flags
}

void ld_de_a()
{
	WriteByte(getDE(), a);            //no flags
}

void ld_hl_r(byte rcode)
{
	byte b = Get8BitReg(rcode);
	WriteByte(getHL(), b);            //no flags
}

void ld_bc_nn()
{
	b = ir[1];
	c = ir[2];
}

void ld_r_hl(byte rcode)
{
	byte data= GetByte(getHL());
	SetReg8(rcode, data);

}

/*de instructions*/
void ld_de_nn()
{
	d = ir[2];
	e = ir[1];
}

void ld_de_mm()
{
	unsigned short hi = ir[2];
	unsigned short lo = ir[1];
	unsigned short data = 0;
	unsigned short temp = 0;
	unsigned short addr = 0;
	
	hi = hi << 8;
	lo = lo & 0x00FF;
	addr = hi | lo;

	data = GetWord(addr);
	temp = getDE();
	ld16(&temp, data);
	setDE(temp);
}

void ld_mm_rr(int rrcode)
{
	unsigned short data = GetReg16(rrcode);
	unsigned short hi = ir[3];
	unsigned short lo = ir[2];
	unsigned short addr = 0;
	hi = hi << 8;
	lo = lo & 0x00FF;
	addr = hi | lo;
	WriteWord(addr, data);
}

void ld_mm_ix()
{
	unsigned short hi = ir[3];
	unsigned short lo = ir[2]; 
	unsigned short addr = 0;
	
	hi = hi << 8;
	lo = lo & 0x00FF;
	addr = hi | lo;
	WriteWord(addr,ix);
}

void ld_mm_iy()
{
	unsigned short hi = ir[3];
	unsigned short lo = ir[2];
	unsigned short addr = 0;
	hi = hi << 8;
	lo = lo & 0x00FF;
	addr = hi | lo;
	WriteWord(addr,iy);
}


/* hl instructions */
void ld_hl_nn()
{
	h = ir[2];
	l = ir[1];
}

/*(hl),0*/
void ld_hl_n()
{
	WriteByte(getHL(), ir[1]);
}


/// <summary>
/// ld (ix+d),n
/// </summary>
void ld_ix_n()
{
	unsigned short addr = ix;
	addr += ir[2];
	WriteByte(addr, ir[3]);
}


/* ix instructions */
/// <summary>
/// ld ix,nn
/// </summary>
void ld_ix_nn()
{
	unsigned short hi = ir[3];
	unsigned short lo = ir[2];
	hi = hi << 8; 
	lo = lo & 0x00FF;
		//unsigned short val = (unsigned short)(ir[3] * 256 + ir[2]);
	ix = hi | lo;
}

void ld_ix_mm()
{
	unsigned short hi = ir[3];
	unsigned short lo = ir[2];
	unsigned short addr = 0;
	hi = hi << 8;
	lo = lo & 0x00FF;
//	unsigned short addr = (unsigned short)(ir[2]  + ir[3] * 256);
	addr = hi | lo;
	ix = GetWord(addr);
}

void ld_iy_mm()
{
	unsigned short hi = ir[3];
	unsigned short lo = ir[2];
	unsigned short addr = 0;
	hi = hi << 8;
	lo = lo & 0x00FF;
	addr = hi | lo;
	iy = GetWord(addr);
}

/* ld (ix+3),a */
void ld_ix_r(byte rcode)
{
	byte r = Get8BitReg(rcode);
	unsigned short addr = ix;
	addr += ir[2];
	WriteByte(addr, r);
}

void ld_iy_r(byte rcode)
{
	byte r = Get8BitReg(rcode);
	unsigned short addr = iy;
	addr += ir[2];
	WriteByte(addr, r);
}


/* iy instructions */
void ld_iy_nn()
{
	unsigned short hi = ir[3];
	unsigned short lo = ir[2];
	hi = hi << 8;
	lo = lo & 0x00FF;
	//unsigned short val = (unsigned short)(ir[3] * 256 + ir[2]);
	iy = hi | lo;
}



void ld_sp_memory()
{
	unsigned short hi = ir[3];
	unsigned short lo = ir[2];
	unsigned short addr = 0;
	hi = hi << 8;
	lo = lo & 0x00FF;
	addr = hi | lo;
	sp = GetWord(addr);
}


void ld_iy_n()
{
	unsigned short addr = ix;
	addr += ir[2];
	WriteByte(addr, ir[3]);
}

void ld_mm_de()
{
	unsigned short hi = ir[2];
	unsigned short lo = ir[1];
	unsigned short addr = 0;
	hi = hi << 8;
	lo = lo & 0x00FF;
	addr = hi | lo;
	WriteWord(addr, getDE());
}

void ld_rr_nn(int rrcode)
{
	unsigned short hi = ir[2];
	unsigned short lo = ir[1];
	unsigned short data = 0;
	hi = hi << 8;
	lo = lo & 0x00FF;
	data = hi | lo;
	SetReg16(rrcode, data);
}

void ld_rr_mm(int rrcode)
{
	unsigned short hi = ir[3];
	unsigned short lo = ir[2];
	unsigned short addr = 0;
	hi = hi << 8;
	lo = lo & 0x00FF;
	addr = hi | lo;
	SetReg16(rrcode, GetWord(addr));
}
