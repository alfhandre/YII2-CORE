#ifndef teksEditor_H
#define teksEditor_H

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define Nil NULL

#define Info(P) (P)->info
#define Next(P) (P)->next
#define Down(P) (P)->down
#define Up(P) (P)->up
#define Prev(P) (P)->prev
#define First(L) (L).First

//ARRAY OF LIST ANGGOTA
typedef char infotype;
typedef struct tnode *address;

typedef struct tnode {
	 infotype info;
	 address next;
	 address down;
	 address up;
	 address prev;
} node;

typedef struct {
	  address First;
} text;

bool IsEmpty (text L);

void createText (text * L);

address Alocation (infotype X);

void deAloc (address *P);

void InsNewRow (text * L, address P);

void InsNewLine(text * L,int CurLine);

void InsChar (text * L, address New, int CurCol, int CurLine);

void InsVChar (text * L, infotype X, int CurLine, int CurCol);

void textProses();

void ScrRef(text L, int line, int collumns);

void DelChar(text * L, int CurCol, int CurLine);

int infoLenght(text L, int CurLine);

void help();

void welcome();

int infoRow(text L);

void saveFile(char *fname, text L);

void gotoxy(int x, int y);

void Menu();

void help();
#endif


