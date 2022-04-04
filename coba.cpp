#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char* argv[])
{
    char ch, nama_file_lama[20], nama_file_baru[20];
    FILE *source, *target;
    if (argc < 2)
    {
        printf("Input file name!\n");
        exit(EXIT_FAILURE);
    }
     
    strcpy(nama_file_baru, argv[1]);
    source = fopen(nama_file_baru, "r");
     
    if (source == NULL)
    {
        printf("File %s not found!\n", nama_file_lama);
        exit(EXIT_FAILURE);
    }
     
    strcpy(nama_file_baru, argv[2]);
    target = fopen(nama_file_baru, "w");
     
    if (target == NULL)
    {
        fclose(source);
        printf("Press any key to exit...\n");
        exit(EXIT_FAILURE);
    }
     
    unsigned int buff[255];
    size_t size;
     
    while (!feof(source))
    {
        fread(buff, 1, 1, source);
        fwrite(buff, 1, 1, target);
    }
     
    printf("Successfuly copied!\n");
     
    fclose(source);
    fclose(target);
    return 0;
}