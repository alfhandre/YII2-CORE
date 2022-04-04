#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "hitungArray.h"
#include "findReplace.h"
#define ROWS 40
#define COLS 80


char text[ROWS][COLS];
int hasil = 0;  
void pilihan(); 
int menu(); 
void savefile();
void gotoxy(short x, short y);
void LastCursor(short row, short col);



int input(char text[ROWS][COLS],short baris, short kolom){
 
 char ch;
 
 gotoxy(kolom, baris);
	
    while(1){
		ch = getch();
		if (ch == 19)
        {
            text[baris][kolom] = '\0';
            break;
        }
        // backspace 
        else if (ch == 8 || ch == 127)
        {
			if(baris == 0 && kolom == 0){
				continue;
			}else if(kolom == 0){
                kolom = COLS-1;
                baris--;
                gotoxy(kolom, baris);
                text[baris][kolom] = '\0';
            }else{
                printf("\b \b");
                kolom--;
                text[baris][kolom] = '\0';
        	}
    	}
        // membaca enter
        else if(ch == 13){
        	if(baris == ROWS-1){
        		continue;
			}else{
				for (; kolom < COLS-1; kolom++) {
                	text[baris][kolom] = 32;
            	}
            	text[baris][kolom] = '\n';
            	baris++;
            	kolom = 0;
            	printf("\n");
			}
        }
    
		else{
            // apabila menyentuh margin
            if(kolom == COLS-1){
            	if(baris == ROWS-1){
            		continue;
				}
                text[baris][kolom] = '\n';
                printf("%c", text[baris][kolom]);
                baris++;
                kolom = 0;
                text[baris][kolom] = ch;
                kolom++;
                printf("%c", ch);
            // tidak menyentuh margin
            }else{
                printf("%c", ch);
                text[baris][kolom] = ch;
                kolom++;
            }
            	
    }
}
	hasil = 1;
	pilihan();
 	return hasil;
}

void edit(){
	short baris = 0;
	short kolom = 0;
	
	if(hasil == 1){  // jika hasil = 1 maka akan menjalanka prosedur di bawah
	
	for(baris = 0; baris < ROWS; baris++){
		for(kolom = 0; kolom < COLS; kolom++){
			if(text[baris][kolom] == '\0'){
            	break;
        	}
			printf("%c", text[baris][kolom]);
		}
		if(text[baris][kolom] == '\0'){
            break;
        }
	}
	LastCursor(baris, kolom);
	input(text, baris, kolom--);
	}
	
	else{  // jika tidak maka akan keluar hasil berikut 
		printf("anda belum menginputkan apapun");
	}
}

void LastCursor(short row, short col)
{
	POINT p;
	if (GetCursorPos(&p))
	{
		row = p.x;
		col = p.y;
	}
}

void gotoxy(short x, short y)
{
	COORD pos ={x,y};
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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
        fputs(*text, file);          // char yang tadi di input akan di masukan ke file 
    	
    	printf("\t============================\n\n");
        printf("\tFile dengan nama [%s] berhasil di save\n\n", namafile);
        printf("\t============================\n\n");
		printf("\t  Tekan enter untuk keluar    \n");
		printf("\t============================\n\n");
    	getch();
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
	short baris = 0;
	short kolom = 0;
	text[0][0] = NULL;
	 
	//operasi file 
	if((file = fopen(namafile,"r")) == NULL){
		printf("\t============================\n\n");
        printf("\tFile dengan nama [%s] tidak di temukan\n\n", namafile);
        printf("\t============================\n\n");
		printf("\t  Tekan enter untuk keluar    \n");
		printf("\t============================\n\n");
	}
	else{
		while(fgets(buff, sizeof(buff),file)){
		printf("%s", buff);
	}
	
	for(baris = 0; baris < ROWS; baris++){
		for(kolom = 0; kolom < COLS; kolom++){
			if(text[baris][kolom] == '\0'){
            	break;
        	}
			printf("%c", text[baris][kolom]);
		}
		if(text[baris][kolom] == '\0'){
            break;
        }
	}
	LastCursor(baris, kolom);
	input(text, baris, kolom--);
	

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
 	
	int pilihan;
	
	system("cls");
	printf("Apakah data yang di input akan di save? \n");
	printf("1. save\n");
	printf("2. tidak\n");
	
	scanf("%d", &pilihan); fflush(stdin);
	if(pilihan == 1){
		savefile();
	}
	if(pilihan == 2)
	{
	    menu();
	}
	else{
		menu();
	}
}

//mengecek apakah file sudah ada
bool cekNamaFile(char nama_file[30]) {
	FILE *fp;
	
    if (fp = fopen(nama_file, "r")) {
        fclose(fp);
        return true;
    }

    return false;
}

//mengubah nama file
void renameFile() {
 char nama_file_lama[30], nama_file_baru[30];
 bool ADA;
 
 system("cls");
 printf("||                              Rename File                              ||\n");
 printf("||=======================================================================||\n");
 printf("\nNama file lama :\n");
    scanf("%s", nama_file_lama);
    
    //membandingkan antara var nama_file_lama dengan string 0,
    // ketika kita menginputkan 0, maka program akan balik lagi ke menu
    if (strcmp(nama_file_lama, "0") == 0) { 
     return;
 } else {
  //ketika yg nama file diinputkan ada pada folder tsb
  ADA = cekNamaFile(nama_file_lama);
     if (ADA) {
      printf("File ditemukan \n");
      printf("Nama file baru : \n");
      //menginput nama file baru yg ditampung di var nam_file_baru
      scanf("%s", nama_file_baru);
      
      //mengganti nama file lama dengan inputan nama file yg baru
      if (rename(nama_file_lama, nama_file_baru) == 0) {
       printf("Nama file berhasil diubah.\n");
   } else {
    printf("Nama file gagal diubah.\n");
   }
  } else {
   printf("File tidak ditemukan\n");
  }
 }
    
 printf("\n");
 system("pause");
}



int menu(){
 int menu; 
  
  while(1){
  		system("cls");
		menu = 0;
		printf("1. Membuat Text   \n");
		printf("2. Edit Text        \n");
		printf("3. Save File         \n");
		printf("4. Buka File        \n");
		printf("5. Hitung Jumlah Karakter \n");
		printf("6. Hitung Jumlah Kata \n");
		printf("7. Rename \n");
		printf("8. Hapus \n");
		printf("9. Find and Replace \n");
		printf("0. Keluar  \n");
		printf("\nPilih Menu :");
		scanf("%d",&menu);fflush(stdin);
		
		switch(menu){
			case 1 :
			{
				system("cls");
				input(text,0,0);
				pilihan();
				break;
			}
		
			case 2 :
			{
				system("cls");
				edit();
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
				system("cls");
				jumlahChar();
				getch();
				break;
			}
			
				case 6 :
			{
				system("cls");
				jumlahKata();
				getch();
				break;
			}
			
				case 7 :
			{
				system("cls");
				renameFile();
				getch();
				break;
			}
			
				case 8 :
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
			
				case 9:
			{
				system("cls");
				findReplace();
				getch();
				break;
			}
			
			case 0 :
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

int main()
{
  
  menu();
  
}
