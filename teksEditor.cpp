#include <stdio.h>
#include <stdlib.h>
#include "teksEditor.H"

address Alocation (infotype X)
{
	address P;
	P = (address)malloc(sizeof(node));
	if(P != Nil){
		Info(P) = X;
		Next(P) = Nil;
		Prev(P) = Nil;
		Up(P) = Nil;
		Down(P) = Nil;
	}
	return P;
}

void deAloc (address *P)
{
	Next(*P) = Nil;
	Prev(*P) = Nil;
	Up(*P) = Nil;
	Down(*P) = Nil;
	free(*P);
}

bool IsEmpty (text L)
{
	return (First(L)==Nil);	
}

void createText (text * L)
{
	First(*L) = Nil;
}

void InsNewRow (text * L, address P)
{
	if(First(*L) == Nil)
		First(*L) = P;
	else
	{
		Down(P) = First(*L);
		Up(First(*L)) = P;
		First(*L) = P;
	}
}

void InsNewLine(text * L, int CurLine, int CurCol)
{
	address above, below, rec_up, rec_down, rec_pos, move;
	
	address pos = First(*L);
	address P = Alocation('\0');
	
	above = Nil;
	below = Nil;
	
	if(P != Nil)
	{
		for(int i=1; i<CurLine;i++)
			pos = Down(pos);
		
		rec_up = Up(pos);
		rec_down = Down(pos);
		rec_pos = pos;
		
		for(int i=1; i<CurCol-1;i++)
			pos = Next(pos);
		
		move = pos;
		
		above = Up(pos);
		below = Down(pos);
		
		if(CurCol == 1) //kondisi ketika berada di awal
		{
			if(CurLine == 1) //kondisi ketika insert new line di first list
			{
				Up(pos) = P;
				Down(P) = pos;
				First(*L) = P;
			}
			else
			{
				Down(rec_up) = P;
				Up(P) = rec_up;
				Up(rec_pos) = P;
				Down(P) = rec_pos;
				
				rec_pos = Next(rec_pos);
				rec_up = Next(rec_up);
				
				while(rec_up != Nil)
				{
					Down(rec_up) = Nil;
					rec_up = Next(rec_up);
				}
				while(rec_pos != Nil)
				{
					Up(rec_pos) = Nil;
					rec_pos = Next(rec_pos);
				}
			}
		}
		else //kondisi berada di tengah atau akhir
		{
			if(Next(pos) != Nil) //kondisi di tengah 
			{	
				pos = Next(pos);
				above = Up(pos);
				below = Down(pos);
				move = pos;
				 
				while(above != Nil)
				{
					Down(above) = Nil;
					above = Next(above);
				}
				
				Next(Prev(pos)) = Nil;
				Prev(pos) = Nil;
				
				Up(move) = rec_pos;
				Down(rec_pos) = move;
				
				while(move != Nil || rec_pos != Nil)
				{
					if(rec_pos != Nil && move == Nil)
					{
						Down(rec_pos) = Nil;
						rec_pos = Next(rec_pos);
					}
					else if (rec_pos == Nil && move != Nil)
					{
						Up(move) = Nil;
						move = Next(move);
					}
					else
					{
						Down(rec_pos) = move;
						Up(move) = rec_pos;
						
						rec_pos = Next(rec_pos);
						move = Next(move);
					}
				}
				move = pos;
				
				while(move != Nil || rec_down != Nil)
				{
					if(rec_down != Nil && move == Nil)
					{
						Up(rec_down) = Nil;
						rec_down = Next(rec_down);
					}
					else if (rec_down == Nil && move != Nil)
					{
						Down(move) = Nil;
						move = Next(move);
					}
					else
					{
						Up(rec_down) = move;
						Down(move) = rec_down;
						
						rec_down = Next(rec_down);
						move = Next(move);
					}
				}
				deAloc(&P);
			}
			else
			{
				if(rec_down == Nil) // akhir baris
				{
					Down(rec_pos) = P;
					Up(P) = rec_pos;
				}
				else
				{
					Down(rec_pos) = P;
					Up(P) = rec_pos;
					Up(rec_down) = P;
					Down(P) = rec_down;
					
					rec_down = Next(rec_down);
					rec_pos = Next(rec_pos);
					
					while(rec_down != Nil)
					{
						Up(rec_down) = Nil;
						rec_down = Next(rec_down);
					}
					
					while(rec_pos != Nil)
					{
						Down(rec_pos) = Nil;
						rec_pos = Next(rec_pos);
					}
				}
			}
		}
	}
}

void InsChar (text *L, address New, int CurCol, int CurLine)
{
	address pos;
	address move;
	address above = Nil;
	address below = Nil;
	
	pos = First(*L);
	move = New;
	
	if(pos == Nil)
		InsNewRow(&(*L), New);
	else
	{
		for(int i=1; i<CurLine;i++)
			pos = Down(pos);
		for(int i=1; i<CurCol-1;i++)
			pos = Next(pos);
		
		if(Up(pos) != Nil) 
			above = Up(pos);
		if(Down(pos) != Nil)
			below = Down(pos);
		                       
		if(Info(pos) == '\0') //kondisi ketika insert new line
		{
			Info(pos) = Info(New);
			deAloc(&New);
		}
		
		else if(Next(pos) == Nil && CurCol != 1) //ketika posisi berada di akhir
		{
			Next(pos) = New;
			Prev(New) = pos;
			
			while(above != Nil || move!=Nil)
			{
				if(above != Nil)
				{
					above = Next(above);
					if(above != Nil)
						Down(above) = move;
					if(move != Nil)
						Up(move) = above;
				}
				if(move != Nil)	
					move = Next(move);
			}
			move = New;
			
			while(below != Nil || move!=Nil)
			{
				if(below != Nil)
				{
					below = Next(below);
					if(below != Nil)
						Up(below) = move;
					if(move != Nil)
						Down(move) = below;	
				}
				
				if(move != Nil)
					move = Next(move);
			}
		}
		else if (Next(pos) != Nil && CurCol != 1) //ketika karakter di insert diantara
		{
			Next(New) = Next(pos);
			Prev(New) = pos;
			Prev(Next(pos)) = New;
			Next(pos) = New;
			
			while(above != Nil || move!=Nil)
			{
				if(above != Nil)
				{
					above = Next(above);
					if(above != Nil)
						Down(above) = move;	
				}else
					above = Nil;
				if(move != Nil)
				{
					Up(move) = above;
					move = Next(move);
				}	
			}
			move = New;
			while(below != Nil || move!=Nil)
			{
				if(below != Nil)
				{
					below = Next(below);
					if(below != Nil)
						Up(below) = move;	
				}else
					below = Nil;
				if(move != Nil)
				{
					Down(move) = below;
					move = Next(move);
				}
			}
		}		
		else // karakter di insert di awal ketika berada di kolom 1 // 
		{
			Next(New) = pos;
			Prev(pos) = New;
			
			while(above != Nil || move!=Nil)
			{
				if(above != Nil)
				{
					Down(above) = move;
					if(move != Nil)
						Up(move) = above;
					above = Next(above);	
				}
				if(move != Nil)
				{
					move = Next(move);
				}
			}
			move = New;
			while(below != Nil || move!=Nil)
			{
				if(below != Nil)
				{
					Up(below) = move;
					if(move != Nil)
						Down(move) = below;
					below = Next(below);	
				}
				if(move != Nil)
				{
					move = Next(move);
				}
			}
			
			if(pos == First(*L))
				First(*L) = New;
		}
	}
}

void InsVChar (text * L, infotype X, int CurCol, int CurLine)
{
	address P = Alocation(X);
	if(P != Nil)
	{
		InsChar(&(*L), P, CurCol, CurLine);
	}
}

void DelChar(text * L, int CurCol, int CurLine)
{
	address pos = First(*L);
	address below, above, move, rec_up, rec_down, rec_pos;
	
	for(int i=1; i<CurLine;i++)
			pos = Down(pos);
	
	rec_down = Down(pos);
	rec_pos = pos;
	rec_up = Up(pos);
	
	for(int i=1; i<CurCol-1;i++)
		pos = Next(pos);
	
	above = Up(pos);
	below = Down(pos); 
	
	
	if(CurCol == 1 && CurLine != 1) // kondisi ketika deletion berada di awal
	{
		if(Info(pos) != Nil) // ketika baris ada isi
		{	
			move = rec_up;
			
			while(Next(move) != Nil && Info(move) != Nil)
				move = Next(move);	
	
			Next(move) = pos;
			Prev(pos) = move;
						
			while(rec_up != Nil || rec_down != Nil)
			{
				if(rec_up != Nil && rec_down == Nil)
				{
					Down(rec_up) = Nil;
					rec_up = Next(rec_up);
				}
				else if(rec_up == Nil  && rec_down != Nil)
				{
					Up(rec_down) = Nil;
					rec_down = Next(rec_down);
				}
				else
				{
					Down(rec_up) = rec_down;
					Up(rec_down) = rec_up;
					
					rec_up = Next(rec_up);
					rec_down = Next(rec_down);
				}
			}
		}
		else // ketika baris yang dihapus baru insert line saja
		{
			while(above != Nil || below != Nil)
			{
				if(above != Nil && below == Nil)
				{
					Down(above) = Nil;
					above = Next(above);
				}else if(above == Nil && below != Nil)
				{
					Up(below) = Nil;
					below = Next(below);
				}else
				{
					Down(above) = below;
					Up(below) = above;
					
					above = Next(above);
					below = Next(below);
				}
			}
			deAloc(&pos);
		}
	}
	else if(CurCol != 1) // deletion berada di tengah atau akhir
	{
		if(Next(pos) == Nil && Prev(pos) == Nil) // menjadi hanya line kosong
			Info(pos) = '\0';
		
		else if(Next(pos) == Nil && Prev(pos) != Nil ) // node yang dihapus berada di akhir
		{
			if(above != Nil)
				Down(above) = Nil;
			if(below != Nil)
				Up(below) = Nil;
			
			Next(Prev(pos)) = Nil;
			
			deAloc(&pos); 
		}
		
		else if(Next(pos) != Nil) //node yang dihapus diantara
		{
			move = Next(pos);
			
			if(CurCol != 2)
				Next(Prev(pos)) = move;
			
			while(above != Nil || move != Nil)
			{
				if(above != Nil && move == Nil)
				{
					Down(above) = Nil;
					above = Next(above);
				}
				else if(above == Nil || move != Nil)
				{
					Up(move) = Nil;
					move = Next(move);
				}
				else
				{
					Down(above) = move;
					Up(move) = above;
					
					above = Next(above);
					move = Next(move);
				}
			}
			move = Next(pos);
			
			while(below != Nil || move != Nil)
			{
				if(below != Nil && move == Nil)
				{
					Up(below) = Nil;
					below = Next(below);
				}
				else if(below == Nil || move != Nil)
				{
					Down(move) = Nil;
					move = Next(move);
				}
				else
				{
					Up(below) = move;
					Down(move) = below;
					
					below = Next(below);
					move = Next(move);
				}	
			}
		deAloc(&pos);
		}
	}
}

void textProses()
{
	text teksEditor;
	createText(&teksEditor);
	
	int CurLine = 1;
	int CurColl = 1;
	int temp_int;
	
	char temp;
	int key;
	
	while(1)
	{
		ScrRef(teksEditor, CurLine, CurColl);
		gotoxy(CurColl-1, CurLine+1);
		temp=getch();
		key = temp;
		
		if(key == -32) // cursor interact
		{
			key=getch();
			switch(key){
				case 72:{
					//up
					//program untuk memindahkan posisi cursor kearah atas
							CurLine--;
							if(CurLine == 0)
								CurLine = 1;
							else{
								temp_int = infoLenght(teksEditor, CurLine)+1;
								if(CurColl > temp_int)
									CurColl = temp_int;
								
							}
							break; 
						}
					case 75:
						{//left
							//program untuk memindahkan posisi cursor kearah kiri
							CurColl--;
							if(CurColl == 0)
							{
								if(CurLine-1 != 0) //kondisi ketika bukan berada di baris 1
								{
									CurLine--;
									CurColl = infoLenght(teksEditor, CurLine)+1;
								}else //kondisi ketika berada di baris 1
								{
									CurColl = 1;
								}
							}
							break;
						}
					case 77:
						{//right
							//program untuk memindahkan posisi cursor kearah kanan
							CurColl++;
							temp_int = infoLenght(teksEditor, CurLine)+1;
							if(CurColl > infoLenght(teksEditor, CurLine)+1)
							{
								CurLine++;
								if(CurLine > infoRow(teksEditor))
								{
									CurLine--;
									CurColl = infoLenght(teksEditor, CurLine)+1;
								}
								else
									CurColl = 1;
							}
							break;
						}
					case 80:
						{//down
							//program untuk memindahkan posisi cursor kearah bawah
							if(CurLine+1 > infoRow(teksEditor))
								CurColl = infoLenght(teksEditor, CurLine)+1;
							else
							{
								CurLine++;
								temp_int = infoLenght(teksEditor, CurLine);
								if(CurColl > temp_int)
									CurColl = temp_int+1;
							}
						}
				}
		} 
		
		else if(key <=31) //non printing character
		{
			/*Handle Backspace*/
			if(key == 8)
			{
				DelChar(&teksEditor, CurColl, CurLine);
				CurColl--;
				if(CurColl == 0)
				{
					CurLine--;
					if(CurLine == 0)
					{
						CurLine = 1;
						CurColl = 1;
					}else
					{
						CurColl = infoLenght(teksEditor, CurLine)+1;
					}
				}
			}
			/***Handle Enter***/                     
			else if(key == 13)
			{
				InsNewLine(&teksEditor, CurLine, CurColl);
				CurLine++;
				CurColl = 1;
			}
			/*** Shortcut key ***/
			/*Ctrl + S (untuk save file)*/
			else if(key == 19)
			{
				char fname[20];
				
				system("cls");
				printf("Masukkan nama file : ");
				gets(fname);
				if(fname == '\0'){
					printf("Anda Belum Menginputkan Nama File");
					getch();
				}
				else{
					saveFile(fname, teksEditor);
					printf("\n tekan apapun untuk kembali");
				}
				
				getch();
			}
			// untuk shortcut keluar 
			// CTRL + E
			else if(key == 5){
				system("cls");
				char pil;
				printf("Apa Anda Yakin Ingin Keluar ?\n");
				printf("Y/N :");
				scanf("%c", &pil);
				if(pil == 'Y'){
					exit(0);
				}
				else{
					continue;
				}
			}
			// UNTUK MEMBUKA HELP
			// CTRL +A
			else if (key == 1){
				system("cls");
				help();
				getch();
			}
			// UNTUK KEMBALI KE MENU 
			// CTRL +B
			else if (key == 2){
				system("cls");
				char pil;
				printf("Apa Anda Yakin Ingin Kembali Ke Menu ?\n");
				printf("Y/N :");
				scanf("%c", &pil);
				if(pil == 'Y'){
					system("cls");
					Menu();
				}
				else{
					continue;
				}
				
			}
		}
		else if (key <= 126)// printing character
		{
			InsVChar(&teksEditor, temp, CurColl, CurLine);
			CurColl++;
		}
	}
}

void ScrRef(text L, int line, int collumns)
{	
	int col;
	col = 29;
	if (line>=26){
		col = line+2;
	}
	system("cls");
	address pos, move;
	
	pos = First(L);
	move = pos;
	
	printf("Panduan (Ctrl+A)\n");
	
	gotoxy(0, col);
	printf("Baris : %d | Kolom : %d\n\n", line, collumns);
	
	gotoxy(0,0);
	gotoxy(0,2);
	while(pos != Nil)
	{
		printf("%c", Info(pos));
		while(Next(move) != Nil)
		{
			move = Next(move);
			if(move != Nil)
				fflush(stdout);
				printf("%c", Info(move));
		}
		pos = Down(pos);
		move = pos;
			if(pos != Nil)
				printf("\n");
	}	
}


int infoLenght(text L, int CurLine)
{
	address pos = First(L);
	int count = 1;
	for(int i=1; i<CurLine;i++)
	{
		if(Down(pos) != Nil)
			pos = Down(pos);
	}
			
	while(Next(pos) != Nil)
	{
		pos = Next(pos);
		count++;
	}
	
	if(Info(pos) == Nil)
		count = 0;
	return count;
}

int infoRow(text L)
{
	address pos = First(L);
	int count = 1;
	while(Down(pos) != Nil ){
		pos = Down(pos);
		count++;
	}
			
	return count;
}

void welcome()
{
	printf("\n\n\n\n\n\n\n\n\t\t\tTEKS EDITOR BY YII2 CORE");
	printf("\n\n\n\n\n\n\n\n\t\t\tTEKAN APAPUN UNTUK LANJUT");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	getch();
	system("cls");
}

void saveFile(char *fname, text L)
{
	address rec, pos;
	rec = First(L);
	pos = rec;
	
	FILE *file = NULL; // untuk mendeklarasikan tipe data file

    file = fopen(fname, "w+"); // pada variabel file kita ingin membuka sebuah file dengan mode w+(overwrite)
    
    while(rec != Nil)
    {
    	while(pos != Nil)
    	{
    		fprintf(file, "%c", Info(pos));
    		pos = Next(pos);
		}
		rec = Down(rec);
		pos = rec;
		if(rec != Nil)
			fprintf(file, "\n");
	}
	fclose(file);
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void Menu(){
		
	
	int tombol;
	char menu, jawab;
	gotoxy(45,9) ;printf("+==========================+\n");
	gotoxy(45,10);printf("|==========================|\n");
	gotoxy(45,11);printf("||          MENU          ||\n");
	gotoxy(45,12);printf("|==========================|\n");
    gotoxy(45,13);printf("|  1. MULAI                |\n");
	gotoxy(45,14);printf("|  2. HELP                 |\n");
	gotoxy(45,15);printf("|  3. Keluar               |\n");
	gotoxy(45,16);printf("|==========================|\n");
	gotoxy(45,17);printf("+==========================+\n");
	gotoxy(45,19);
	printf("Pilih Menu: ");
	awal:
	scanf("%d", &tombol);
	fflush(stdin);
	switch(tombol){
		case 1:
			system("cls");
			textProses();
			gotoxy(25,23);
			printf("Tekan 'ENTER' untuk kembali!");
			getch();
			system("cls");

		case 2:
			system("cls");
			help();
			getch();
			system("cls");
			Menu();
			break;
		case 3:
			exit(1);
			break;
		default:
			gotoxy(45,21);
			printf("Pilihan tidak ada!");
   			getch();

}
}

void help(){
				printf("====================================================\n");
				printf("=============            HELP           ============\n");
				printf("====================================================\n");
				printf("1. Untuk mengakhiri program tekan CTRL +E\n");
				printf("2. Untuk menyimpan file tekan CTRL +S\n");
				printf("3. Untuk menuju menu awal tekan CTRL +B\n");
				printf("4. Untuk membuka panduan tekan CTRL +A\n\n");
				printf("Tekan apapun untuk kembali\n");
}
