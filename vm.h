#ifndef DEFS_H
#define DEFS_H

#define byte unsigned char

void add8(byte val);
void add16(unsigned short *tgt, unsigned short src);
void add_immediate();
void add_r(byte rcode);
void add_a_n();
void add_hl_bc();
void add_hl_de();
void add_ix_bc();
void add_ix_de();
void add_iy_bc();
void add_iy_de();
void and_b();
void and_immediate();
void cls();
void save();
void restore();
void quit();
void status_line();
void charout();
void printcr();
void readkb();
void anykey();
void setp();
void bit_b_ix(byte b, byte d);
void bit_b_iy(byte b, byte d);
void bit_b_hl(byte b);
void bit_b_r(byte b, byte r);
void bit_ix_iy(unsigned short rr);
void bit_n_ix();
void bit_n_iy();
void call();
void call_zero();
void call_not_zero();
void call_carry();
void call_no_carry();
void call_plus();
void call_minus();
void call_cc(byte cc);
void ret();
void cp_immediate8(byte val);
void cp_r(byte regcode);
void dec_sp();
void cp_n();
void cp_hl();
void cp_a_memory(unsigned short nn);
void cp_ix();
void cp_iy();
void cpl();
void dec_rcode(byte rcode);
void dec_r(byte *r);
void dec_rr(unsigned short *rr);
void dec_a();
void dec_b();
void dec_c();
void dec_d();
void dec_e();
void dec_h();
void dec_l();
void dec_bc();
void dec_de();
void dec_hl();
void dec_ix();
void dec_iy();
void djnz();
void di();
void ei();
void Fetch();
void inc_rcode(byte code);
void inc_r(byte *r);
void inc_rr(unsigned short *rr);
void inc_a();
void inc_b();
void inc_c();
void inc_d();
void inc_e();
void inc_h();
void inc_l();
void inc_bc();
void inc_de();
void inc_hl();
void inc_ix();
void inc_ix_plus_d();
void inc_iy_plus_d();
void inc_iy();
void inc_sp();
void inc_hl_indexed();
void jmp();
void jmpcc(int cc);
void jmp_hl();
void jmp_z();
void jmp_nz();
void jmp_c();
void jmp_nc();
void jmp_p();
void jmp_m();
void jmprel();
void jmprelcc(int flag);
void jr();
void jrc();
void jrnc();
void jrz();
void jrnz();
void SetReg8(byte rcode, byte data);
void SetReg16(int rrcode, unsigned short data);
void ld_r_r(byte rcode1, byte rcode2);
void ld16(unsigned short *tgt,  unsigned short src);
void ld_r_n(byte rcode);
void ld_a_bc();
void ld_a_de();
void ld_a_hl();
void ld_a_mm();
void ld_mm_a();
void ld_r_ix(byte rcode);
void ld_r_iy(byte rcode);
void ld_bc_a();
void ld_de_a();
void ld_hl_r(byte rcode);
void ld_bc_nn();
void ld_r_hl(byte rcode);
void ld_de_nn();
void ld_de_mm();
void ld_mm_rr(int rrcode);
void ld_mm_ix();
void ld_mm_iy();
void ld_hl_nn();
void ld_hl_n();
void ld_ix_n();
void ld_ix_nn();
void ld_ix_mm();
void ld_iy_mm();
void ld_ix_r(byte rcode);
void ld_iy_r(byte rcode);
void ld_iy_nn();
void ld_sp_memory();
void ld_iy_n();
void ld_mm_de();
void ld_rr_nn(int rrcode);
void ld_rr_mm(int rrcode);
void ldir();
void neg();
void nop();
void or_r(byte rcode);
void or_n();
void or_a(byte rcode);
void or_hl();
void or_ix();
void or_iy();
 
void pop_rr(int rrcode);
void pop_ix();
void pop_iy();
void push_rr(int rrcode);
void push_ix();
void push_iy();
 
void res_b_r(int bit, int rcode);
void set_b_r(int bit, int rcode);
void res_b_ix(byte bit, byte disp);
void set_b_ix(byte bit, byte disp);
void res_b_iy(byte bit, byte disp);
void sla_c();
void sra_a();
void srl_a();
void sub8(byte op);
void sub_n();
void sub_r(byte rcode);
void xor(byte b);

void setAF(unsigned short);
void setBC(unsigned short);
void setDE(unsigned short);
void setHL(unsigned short);

void AdvancePC();
void WriteByte(unsigned short addr, byte b);
void WriteWord(unsigned short addr, unsigned short w);
unsigned short GetWord(unsigned short addr);
byte GetByte(unsigned short addr);

void SetCarryBit8(int sum);
void SetZeroAndSign8(byte c);
void SetZeroAndSign16(unsigned short s);
void SetFlagsA();
void SetReg8(byte rcode, byte data);
unsigned short GetReg16(int rrcode);
void SetReg16(int rrcode, unsigned short data);
byte Get8BitReg(byte r); 

unsigned short getAF();
unsigned short getBC();
unsigned short getDE();
unsigned short getHL();

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
extern byte ir[4]; //instruction register

extern unsigned char *Ram;
extern int RamSize;
#endif

