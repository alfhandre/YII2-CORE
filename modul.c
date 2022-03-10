#include <stdio.h>
#include "header.h"
#include <windows.h>
#include <conio.h>
#include <unistd.h>

void tampilan(){
	printf("==========================================\n");
	printf("       text editor Yii2 Core (BETA)       \n");
	printf("==========================================\n");
	
}

void panduan(){
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
	printf("=============================================================\n");
	printf(" Nama File yang akan di buka (MAKS 30 KARAKTER):");
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
	char text[100];
	
	//nama file yang akan di buat  
	printf("==============================\n");
	printf("Nama File yang akan dibuat (MAKS 30 KARAKTER):");
	gets(namafile);
	system("cls");
	
	//operasi file 
		fptr = fopen(namafile,"w+"); 
		int i;
		for(i = 0; i < 5; i++){

        // mengambil input dari user
        
        fgets(text, sizeof(text), stdin);

        // menulis ke text ke file
        fputs(text, fptr);
    }
	
	fclose(fptr);
}



