#include <stdio.h>
#include <windows.h>

int main(){
	for (int i=0; i<256; ++i){
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),i);
		printf ("Warna teks yang digunakan =%d\n",i);
	}
	return 0;
}