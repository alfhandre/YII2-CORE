#include "fitur.h"

void textEditor()
{
	char text[BARIS][KOLOM];
	int t;
	//, x, j;
  	for(t = 0;t < BARIS;t++)
	  {
  		gets(text[t]);
  		if(!*text[t])
  		break;
	  }
}

//void menu()

void panduan()
{
	printf("==========================================\n");
	printf("       			PANDUAN				      \n");
	printf("==========================================\n");
	printf("1. Pilih menu 1 untuk memulai text editor\n");
	printf("2. Untuk keluar tekan enter 3 kali");
	printf("\n\n\nTekan Enter Untuk Kembali Ke Menu\n");
	printf("==========================================\n");
}

void openFile()
{
	char buff[255];
	FILE *fptr;
	char namafile[30];
	
	//nama file yang akan di buka  
	printf("\nNama File yang akan di buka :");
	gets(namafile);
	system("cls");
	
	//operasi file 
	if((fptr = fopen(namafile,"r")) == NULL)
	{
		printf("ERORR! Data tidak ditemukan\n");
		printf("\nTekan Enter Untuk Kembali");
	}
	while(fgets(buff, sizeof(buff),fptr))
	{
		printf("%s", buff);
	}

	fclose(fptr);
}

void newFile()
{
	char buff[255];
	FILE *fptr;
	char namafile[30];
	char text[100];
	char c;
	
	//nama file yang akan di buat  
	
	printf("\nNama File yang akan dibuat :");
	gets(namafile);
	system("cls");
	
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
		}else if(c == 19)
		{	
			system("cls");
			printf("\n\tFile Berhasil Di Save");
			printf("\n\n\tTekan Enter untuk keluar");
			fclose(fptr);
			break;
		}else
		{
			fputc(c, fptr);
		}
	}
}

void duplicateFile()
{
   char ch, source_file[20], target_file[20];
   FILE *source, *target;
 
   printf(" Masukkan Nama File yang akan diduplikasi\n");
   gets(source_file);
 
   source = fopen(source_file, "r");
 
   if( source == NULL )
   {
      printf("Tekan Enter untuk keluarn");
      exit(EXIT_FAILURE);
   }
 
   printf("Masukkan Nama File\n");
   gets(target_file);
 
   target = fopen(target_file, "w");
 
   if( target == NULL )
   {
      fclose(source);
      printf("Tekan Enter untuk keluar\n");
      exit(EXIT_FAILURE);
   }
 
   while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);
 
   printf("Duplikasi File Berhasil!\n");
 
   fclose(source);
   fclose(target);
 
//   return 0;
}

void renameFile()
{
    // Path to old and new files
    char oldName[100], newName[100];

    // Input old and new file name
    printf("Masukkan Nama File yang akan diganti: ");
    scanf("%s", oldName);

    printf("Masukkan Nama File baru: ");
    scanf("%s", newName);

    // rename old file with new name
    if (rename(oldName, newName) == 0)
    {
        printf("Penggantian Nama File Berhasil!\n");
    }else
    {
        printf("Tidak dapat mengganti nama file. Silakan periksa file yang ada dan Anda memiliki izin untuk memodifikasi file.\n");
    }

}
