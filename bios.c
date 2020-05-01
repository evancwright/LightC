#include "regs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

extern char *Ram; 
extern int quitFlag;
char buffer[80];

int min(int x, int y)
{
	return (x < y) ? x : y;
}

void cls()
{
	printf("\x1b[2J"); //cls
	printf("\x1b[2;0H"); //position cursor
}

/// <summary>
/// hl contains start of data,
/// de contains end of data
/// </summary>
char buffer[80];

void save()
{
	FILE *fp = 0;
	int len = 0;
	unsigned short hl = getHL();
	unsigned short de = getDE();
	int size = de - hl;
	printf("Enter save file name (without extension)\n");
	
	memset(buffer, 0, sizeof(char));
	
	//gets_s(buffer, 80);
	//gets(buffer);
	fgets(buffer, 80,stdin);
	len = strlen(buffer);

	buffer[len - 1] = 0;
	strcat(buffer,".sav");
	fp = fopen(buffer, "wb");
	fwrite(&Ram[hl], 1, size, fp);
	fclose(fp);
	
	printf("Game saved.\n");
	
}

/// <summary>
/// hl contains start of data,
/// de contains end of data
/// </summary>
void restore()
{
	FILE *fp = 0;
	unsigned short hl = getHL();
	unsigned short de = getDE();
	int size = de - hl;
	int len;

	printf("Enter save file name (without extension)\n");
	memset(buffer, 0, sizeof(char));
	//gets(buffer);
	fgets(buffer, 80, stdin);
	len = strlen(buffer);
	buffer[len - 1] = 0;
	strcat(buffer,".sav");
	
	fp = fopen(buffer, "rb");
	if (fp != 0)
	{
		fread(&Ram[hl], 1, size, fp);
		fclose(fp);
	}
	else
	{
		printf("File not found.\n");
	}
}

void quit()
{
	quitFlag = 1;
}

void status_line()
{
}

//hl contains string
void charout()
{
	printf("%c",a);
}

void printcr()
{
	printf("\n");
}

void anykey()
{
	fgetc(stdin);
}

//reads chars into address stored in HL
void readkb()
{   

	int len = 0;
	int i = 0;
	
	unsigned short hl = getHL();
	
	memset(buffer, 0, sizeof(char));
	//gets(buffer);
	fgets(buffer, 80, stdin);
	len = strlen(buffer);
	buffer[len - 1] = 0;

	len = strlen(buffer);
	 
	for (;  i < min(len,80); i++)
	{
		WriteByte((unsigned short)(hl+i), (unsigned char)buffer[i]);
	}
	
	//null terminate buffer
	WriteByte((unsigned short)(hl + i) ,0);

}

/// <summary>
/// 
/// a contains param number
/// hl contains where to put value
/// a=0 screen width
/// a=1 screen height
/// </summary>
void setp()
{
	unsigned short hl = getHL();
	if (a == 0)
	{//width
		WriteByte(hl, 80);
	}
	else if (a == 1)
	{//height (for scrolling)
		WriteByte(hl, 20);
	}
}
