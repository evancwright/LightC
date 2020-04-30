#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

#define byte unsigned char
//void Test();
//void RageDump();
 
//cpu state
unsigned char a;
unsigned char f;
unsigned char b;
unsigned char c;
unsigned char d;
unsigned char e;
unsigned char h;
unsigned char l;
unsigned short ix;
unsigned short iy;
unsigned short sp;
unsigned short pc;
unsigned char zeroBit;
unsigned char carryBit;
unsigned char signBit;
int quitFlag=0;

unsigned char ir[4]; //instruction register
 
unsigned char *Ram=0;
int RamSize=0;
int cfileexists(const char * filename);

void execute();
void fetch();
void RageDump();

int main(int argc, char **argv)
{ 
	if (argc != 1)
	{
		if (cfileexists(argv[1]))
		{
			//printf("Opening %s\n", argv[1]);
			//how big is the file?
//			struct stat buffer;
//			stat(argv[0],&buffer);	
//			RamSize = buffer.st_size;
			//load the file into "ram"
			
			FILE *fp = fopen(argv[1],"r");
			if (fp!=0)	
			{
				fseek(fp, 0, SEEK_END)+1;
				RamSize = ftell(fp);
				rewind(fp);
		
				Ram = malloc(RamSize);
				
				if (Ram == 0)
				{
					printf("Unable allocate ram");
					exit(0);
				}
				
				
				fread(Ram,1,RamSize,fp);
				fclose(fp);
				
				
				//Test();


				pc=0;
				while (quitFlag == 0)
				{
					fetch();
					execute();
					/*
					if (pc == 0x0B89 || pc == 0x0B8C || pc == 0x0E0C || pc == 0x0E29)
					{
						RageDump();
						getc(stdin);
					}*/
				}
				free(Ram);
			}
			else
			{
				printf("Unable to open file");
			}
		}
		else
		{
			printf("File not found.");
		}
	}
	else
	{
		printf("Usage: light gamefile\n");
	}
}

int cfileexists(const char * filename){
    /* try to open file to read */
    FILE *file;
    if (file = fopen(filename, "r")){
        fclose(file);
        return 1;
    }
    return 0;
}




void RageDump()
{
	printf("\n");
	printf("A:%2x  F:??\n", a);
	printf("B:%2x  C:%2x\n", b, c);
	printf("D:%2x  E:%2x\n", d, e);
	printf("H:%2x  L:%2x\n", h, l);
	printf("PC:%02x\n", pc);
	printf("SP:%02x\n", sp);
	printf("IX:%02x\n", ix);
	printf("IY:%02x\n", iy);
	printf("Zero=%d\n", zeroBit);
	printf("Carry=%d\n", carryBit);
}