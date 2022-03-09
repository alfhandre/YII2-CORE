#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#define MAX 100
#define LEN 80

void texteditor() 
{
	char text[MAX][LEN];
	int t, x, j;
  	for(t = 0; t < MAX; t++) {
    gets(text[t]);
    if(!*text[t]) 
    break; 
  }


//    for(x = 0; x < t; x++) {
//    for(j = 0; text[ x ][ j ]; j++) 
//    putchar(text[ x ][ j ]);
//    putchar('\n');
//  }

//  return 0;
}

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
		 for(int i = 0; i < 5; i++){

        // mengambil input dari user
        
        fgets(text, sizeof(text), stdin);

        // menulis ke text ke file
        fputs(text, fptr);
    }
	
	fclose(fptr);
}

int main(void){
	
int menu;

	while(1){
		
		tampilan();
		menu = 0;
		printf("1. Membuat Text   \n");
		printf("2. Buka File      \n");
		printf("3. Panduan        \n");
		printf("4. keluar         \n");
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


