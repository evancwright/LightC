#ifndef REGS_H
#define REGS_H

#define byte unsigned char

extern unsigned char a;
extern unsigned char f;
extern unsigned char b;
extern unsigned char c;
extern unsigned char d;
extern unsigned char e;
extern unsigned char h;
extern unsigned char l;
extern unsigned short ix;
extern unsigned short iy;
extern unsigned short sp;
extern unsigned short pc;
extern unsigned char zeroBit;
extern unsigned char carryBit;
extern unsigned char signBit;

void setAF(unsigned short);
void setBC(unsigned short);
void setDE(unsigned short);
void setHL(unsigned short);
unsigned short getAF();
unsigned short getBC();
unsigned short getDE();
unsigned short getHL();

void SetCarryBit8(int sum);
void SetZeroAndSign8(byte c);
void SetZeroAndSign16(unsigned short s);
void SetFlagsA();
void SetReg8(byte rcode, byte data);
unsigned short GetReg16(int rrcode);
void SetReg16(int rrcode, unsigned short data);
byte Get8BitReg(byte r); 

void WriteByte(unsigned short addr, byte b);
void WriteWord(unsigned short addr, unsigned short w);
unsigned short GetWord(unsigned short addr);
byte GetByte(unsigned short addr);

extern unsigned char ir[4];

#endif

