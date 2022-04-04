#include "hitungArray.h"

void jumlahChar()
{
	FILE *fp;
	char in,nmFile[40];
	int jml_char = 0;
	fflush(stdin);
	
	printf("Nama File: "); 
    gets(nmFile); 
	fflush(stdin);
	
	printf("\nFile yang dibuka: %s\n\n", nmFile);
	fp=fopen(nmFile,"rt");
	
	while ((in=getc(fp)) !=EOF)
	{
       if (in != ' ')
	   {
			jml_char++;
	   }
    }
    fclose(fp);
       
	printf("Jumlah karakter pada file tersebut sebanyak: %d karakter", jml_char);
}

void jumlahKata()
{
	FILE *fp;
	char in,nmFile[40];
	int jml_kata = 0;
	fflush(stdin);
	
	printf("Nama File: "); 
    gets(nmFile); 
	fflush(stdin);
	
	printf("\nFile yang dibuka: %s\n\n", nmFile);
	fp=fopen(nmFile,"rt");
	
	while ((in=getc(fp)) !=EOF)
	{
       if (in == ' ')
	   {
			jml_kata++;
	   }
    }
    jml_kata++;
    fclose(fp);
       
	printf("Jumlah kata file tersebut sebanyak: %d Kata\n\n", jml_kata);
}
