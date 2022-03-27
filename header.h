#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#ifndef header_h
#define header_h
#define MAX 100
#define LEN 80


char huruf[100][100];    // variabel global
int i=0,j=0; 			// deklarasi variabel global 
int hasil = 0;   
void pilihan(); 
int input(void);
void tampil();
void savefile();
void bukafile(char namafile[30]);
void deletefile(char namafile[30]);


#endif


