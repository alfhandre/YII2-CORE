#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "duplicatefile.h"

void DuplicateFile()
{
   char ch, sumber_file[20], target_file[20]; 
   FILE *sumber, *target;
   system ("cls");

	back:
	system ("cls");
	printf("||                              Duplicate File                           ||\n");
	printf("||=======================================================================||\n");
	printf("\t Masukan nama file yang akan dicopy : \n \t ---> ");
	scanf("%s", sumber_file);

	sumber = fopen(sumber_file, "r");

	if (sumber == NULL){
		system ("cls");
		printf("\t\t\t\t\tFILE TIDAK DITEMUKAN ! \n");
//		getch(); 
		goto back;
	} else{
		printf("\t Masukan nama file baru yang sudah dicopy : \n \t ---> ");
		scanf("%s", target_file);
		target = fopen(target_file, "w");
	
		//fgets ngebaca string yg mana tidak sama dengan eof
		while ((ch = fgetc(sumber)) != EOF){ 
		fputc(ch, target);
	}
}    
	printf("\n\t\t\t\t\tFILE BERHASIL DI COPY ! \n");
//	getch(); //kok error ygy
	fclose(sumber);
	fclose(target);

   system("cls");
}


int main()
{
	DuplicateFile();
}