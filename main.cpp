#include <stdio.h>
#include <windows.h>
#include "fitur.h"

int main(){
	
int menu;

	while(1){
		
		menu = 0;
		printf("==========================================\n");
		printf("       Text Editor Yii2 Core (BETA)       \n");
		printf("==========================================\n");
		printf("1. Membuat Text   \n");
		printf("2. Buka File      \n");
		printf("3. Panduan        \n");
		printf("4. Duplikasi File \n");
		printf("5. Ganti Nama File\n");
		printf("6. keluar         \n");
		printf("\nPilih Menu :");
		scanf("%d",&menu);fflush(stdin);
		
		switch(menu){
			case 1 :
			{
				system("cls");
				newFile();
//				textEditor();
				getch();
				system("cls");
				break;
			}
				case 2 :
			{
				system("cls");
				openFile();
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
