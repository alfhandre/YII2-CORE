#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#define BARIS 100
#define KOLOM 80

void texteditor() 
{
	char text[BARIS][KOLOM];
	int t;
	//, x, j;
  	for(t = 0; t < BARIS; t++) {
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
	printf("1. Ketik 1 untuk membuat file baru\n");
	printf("2. ketik 2 untuk masuk ke dalam menu open file\n");
	printf("\t membuka file cukup ketikkan nama file yang ingin dibuka\n\n");
	printf("==========================================\n");
	printf("       			FITUR				      \n");
	printf("==========================================\n");
	printf(" Copy : Untuk menyalin teks yang dipilih ke clipboard gunakan perintah ctrl+c \n");
	printf(" Paste : Untuk mempaste teks. gunakan perintah ctrl+v \n");
	printf(" Save file : untuk menyimpan perubahan yang telah dibuat pada file, gunakan perintah ctrl+s \n");
	printf("\n\n\nTekan Enter Untuk Kembali Ke Menu\n");
	printf("==========================================\n");
}


void bukafile(){
	char buff[255];
	FILE *fptr;
	char namafile[30];
	
	//nama file yang akan di buka  
	printf("\nNama File yang akan di buka :");
	gets(namafile);
	system("cls");
	tampilan();
	
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

int main(){
	
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
				tampilan();
				buatfile();
				//texteditor();
				getch();
				system("cls");
				break;
			}
				case 2 :
			{
				system("cls");
				tampilan();
				bukafile();
				getch();
				system("cls");
				break;
			}
			
			case 3 :
			{
				system("cls");
				tampilan();
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


