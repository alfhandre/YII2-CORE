#include <stdio.h>
#include "header.h"
#include <windows.h>
#include <conio.h>
#include <unistd.h>

void tampilan(){
	format (9);
	printf("==========================================\n");
	printf("       text editor Yii2 Core (BETA)       \n");
	printf("==========================================\n");
	
}

void panduan(){
	format (6);
	printf("==========================================\n");
	printf("       			PANDUAN				      \n");
	printf("==========================================\n");
	printf("1. Pilih menu 1 untuk memulai text editor\n");
	printf("2. Untuk keluar tekan enter 3 kali");
	printf("\n\n\nTekan Enter Untuk Kembali Ke Menu\n");
	printf("==========================================\n");
}

void bukafile(){
	char buff[255];
	FILE *fptr;
	char namafile[30];
	
	//nama file yang akan di buka  
	format (3);
	printf("=============================================================\n");
	printf(" Nama File yang akan di buka :");
	gets(namafile);
	system("cls");
	
	
	//operasi file 
	if((fptr = fopen(namafile,"r")) == NULL){
		printf("ERORR! Data tidak ditemukan\n");
		printf("\nTekan Enter Untuk Kembali");
	}
	while(fgets(buff, sizeof(buff),fptr)){
		printf("%s", buff);
	}

	fclose(fptr);
}

void buatfile(){
	char buff[255];
	FILE *fptr;
	char namafile[30];
	char c;
	
	//nama file yang akan di buat  
	
	printf("\nNama File yang akan dibuat :");
	gets(namafile);
	system("cls");
	tampilan();
	
	//operasi file 
		fptr = fopen(namafile,"w+"); 
		
        // mengambil input dari user
		while(1)
		{
		c=getchar();
		
       		 if(c==32)
		{ 
		c =' ';
		fputc(c, fptr);
		} 
		else if(c == 19)
		{
			system("cls");
			tampilan();
			printf("\n\tFile Berhasil Di Save");
			printf("\n\n\tTekan Enter untuk keluar");
			fclose(fptr);
			break;
		}
		else{
		fputc(c, fptr);
		}
	
	}
    
}

void format (int i){
	HANDLE j = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (j,i);
}

