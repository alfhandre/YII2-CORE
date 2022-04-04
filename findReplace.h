#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#ifndef findReplace_H
#define findReplace_H

struct element{
	int slide;
	char ch;
};

int findReplace();
int notSensitive(char* text,char* find,char* replace,struct element* Table);
int getSlide(struct element* Table,char cur,char* find);

#endif
