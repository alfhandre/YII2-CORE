#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void){
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
//				pilihan();
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
			
				case 6 :
			{
				return 0;
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
