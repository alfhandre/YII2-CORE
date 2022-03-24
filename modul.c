#include <stdio.h>
#include "header.h"
#include <windows.h>
#include <conio.h>

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

void menu(){
 int menu; 
  
  while(1){
  		system("cls");
		menu = 0;
		printf("1. Membuat Text   \n");
		printf("2. tampil         \n");
		printf("3. save         \n");
		printf("4. buka        \n");
		printf("5. Hapus File  \n");
		printf("6. Keluar  \n");
	
		printf("\nPilih Menu :");
		scanf("%d",&menu);fflush(stdin);
		
		switch(menu){
			case 1 :
			{
				system("cls");
				input();
				pilihan();
				break;
			}
		
			case 2 :
			{
				system("cls");
				tampil();
				getch();
				break;
			}
				case 3 :
			{
				system("cls");
				savefile();
				getch();
				break;
			}
				case 4 :
			{
				char namafile[30];
				system("cls");
				printf("==============================\n");
				printf("Nama File yang akan dibuat (MAKS 30 KARAKTER):");
				gets(namafile);
				system("cls");
				bukafile(namafile);
				getch();
				break;
			}
			
				case 5 :
			{
				char namafile[30];
				system("cls");
				printf("==============================\n");
				printf("Nama File yang akan dihapus (MAKS 30 KARAKTER):");
				gets(namafile);
				system("cls");
				deletefile(namafile);
				getch();
				break;
			}
			
				default:
			{
				system("cls");
				printf("\t=======================\n");
				printf("\t     Menu tidak ada    \n");
				printf("\t=======================\n");
				
				system("cls");
			
				break;
			}
		}
	}	
}
