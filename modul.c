#include <stdio.h>
#include "header.h"
#include <windows.h>
#include <conio.h>
#include <unistd.h>

int input(void){
 
  for(i=0;i<100;i++){
   for(j=0;j<100;j++){
    scanf("%c", &huruf[i][j]);  //scan ini bakal nyimpen semua karakter ke array, termasuk spasi sama enter
    if(huruf[i][j] == 19){  //jika input kan ctrl+s maka akan menyimpan semua character kedalam array
	 j = 100;
     i = 100;
  			}				// fungsi ini akan mengembalikan hasil = 1 bila di jalankan
 		}					// dan itu berfungi untuk mengecek apakah ada array yang di input atau tidak
 	 }
		hasil = 1;
 	return hasil;
}

void tampil(){
	if(hasil == 1){  // jika hasil = 1 maka akan menjalanka prosedur di bawah
		for(i=0;i<100;i++){
   					for(j=0;j<100;j++){
    					printf("%c", huruf[i][j]);
    			if(huruf[i][j] == 0){  //cek ini kalo isi arraynya masih kosong bakal keluar dari perulangan print elemen array
				j = 100;
				i = 100;
				}
			}
		}
	}
	else{  // jika tidak maka akan keluar hasil berikut 
		printf("anda belum menginputkan apapun");
	}
}

void savefile(){
	if(hasil == 1){
	char buff[255];
	FILE *file;
	char namafile[30];
	
	
	//nama file yang akan di buat  
	printf("==============================\n");
	printf("Nama File yang akan dibuat (MAKS 30 KARAKTER):");     
	gets(namafile);
	system("cls");
	
	//operasi file 
		file = fopen(namafile,"w");
        // menulis ke text ke file
        fputs(*huruf, file);          // char yang tadi di input akan di masukan ke file 
    	printf("\t============================\n\n");
        printf("\tFile dengan nama [%s] berhasil di save\n\n", namafile);
        printf("\t============================\n\n");
		printf("\t  Tekan enter untuk keluar    \n");
		printf("\t============================\n\n");
    	
	fclose(file);
	}
	else{  // jika tidak maka akan keluar hasil berikut 
		printf("anda belum menginputkan apapun");
	}
}

void bukafile(char namafile[30]){   // ini akan membuka file yang sudah di save namun belum bisa di edit 
	char buff[255];
	FILE *file;
	system("cls");
	
	
	//operasi file 
	if((file = fopen(namafile,"r")) == NULL){
		printf("\t============================\n\n");
        printf("\tFile dengan nama [%s] tidak di temukan\n\n", namafile);
        printf("\t============================\n\n");
		printf("\t  Tekan enter untuk keluar    \n");
		printf("\t============================\n\n");
	}
	while(fgets(buff, sizeof(buff),file)){
		printf("%s", buff);
	}
	fclose(file);
}



void deletefile(char namafile[30]){
	
	if (remove(namafile) == 0) {
		printf("\t============================\n\n");
        printf("\tFile dengan nama [%s] berhasil di hapus\n\n", namafile);
        printf("\t============================\n\n");
		printf("\t  Tekan enter untuk keluar    \n");
		printf("\t============================\n\n");		
    } else {
        printf("\t============================\n\n");
        printf("\tFile dengan nama [%s] tidak di temukan\n\n", namafile);
        printf("\t============================\n\n");
		printf("\t  Tekan enter untuk keluar    \n");
		printf("\t============================\n\n");
    }	
	
}

void pilihan(){
 	
	char pilihan;
	
	system("cls");
	printf("Apakah data yang di input akan di save? ");
	scanf("%c", &pilihan);
	if((pilihan == 'Y') && (pilihan =='y')){
		savefile();
	}
	else{
	    menu();
	}

}

void format (int i){
	HANDLE j = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (j,i);
}




