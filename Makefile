SOURCE=main.c and.c add.c bios.c bit.o call.c \
	dec.c decode.c inc.c jmp.c jr.c mem.c \
	cp.c ld.c ldir.c res.c pop.c shift.c \
	sub.c regops.c execute.o

OBJ= main.o and.o add.o bios.o bit.o call.o \
	dec.o decode.o inc.o jmp.o jr.o mem.o \
	cp.o ld.o ldir.o pop.o res.o shift.o \
	sub.o regops.o execute.o
	
LIBS=-lm
	
light : $(OBJ)
	cc -o light $(OBJ) $(LIBS) 

*.o : *.c $(SOURCE)
	cc -c %.c

.PHONY: clean
clean:
	rm $(OBJ)
	rm light	
