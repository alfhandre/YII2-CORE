#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main(void){
	int menu;

	while(1){
		
		tampilan();
		menu = 0;
		format (11);
		printf("1. Membuat Text   \n");
		printf("2. Buka File      \n");
		printf("3. Panduan        \n");
		printf("4. duplicate file \n");
		printf("5. rename file    \n");
		printf("6. Hitung char    \n");
		printf("7. Hitung kata    \n");
		printf("8. Keluar	      \n");
		
		format (10);
		printf("\nPilih Menu :");
		scanf("%d",&menu);fflush(stdin);
		
		switch(menu){
			case 1 :
			{
				system("cls");
				buatfile();
				getch();
				system("cls");
				break;
			}
				case 2 :
			{
				system("cls");
				bukafile();
				getch();
				system("cls");
				break;
			}
			
			case 3 :
			{
				system("cls");
				panduan();
				getch();
				system("cls");
				break;
			}
			case 4 :
			{
				system("cls");
				duplicateFile();
				getch();
				system("cls");
				break;
			}
			case 5 :
			{
				system("cls");
				renameFile();
				getch();
				system("cls");
				break;
			}
			case 6 :
			{
				system("cls");
				jum_char();
;				getch();
				system("cls");
				break;
			}
			case 7 :
			{
				system("cls");
				jum_kata();
;				getch();
				system("cls");
				break;
			}
			case 8 :
			{
				return(0); 
				break;
			}
				default:
			{
				system("cls");
				printf("\t=======================\n");
				printf("\t     Menu tidak ada    \n");
				printf("\t=======================\n");
				sleep(2);
				system("cls");
			
				break;
			}
		}
	}	
}
