#include "findReplace.h"

struct element* createTable(char* find){
	int i;
	int j;
	
	struct element *Table;
	Table=(struct element*)malloc(sizeof(struct element)*(strlen(find)-1));
	
	for(i=0;i<strlen(find)-1;i++){
		Table[i].ch=find[i];
		Table[i].slide=strlen(find)-i-1;
		for(j=0;j<i;j++){
			if(find[i]==Table[j].ch){
				Table[j].slide=strlen(find)-i-1;
			}
		}
	}
	return Table;
}

int getSlide(struct element* Table,char cur,char* find){
	if(strlen(find)==1){
		return 1;
	}
	int i=0;
	for(i=0;i<strlen(find)-1;i++){
		if(cur==Table[i].ch){
			return Table[i].slide;
		}
	}
	return strlen(find);
}

int notSensitive(char* text,char* find,char* replace,struct element* Table){
	int initial=strlen(text);
	int i;
	int j;
	int counter=0;
	int z=0;
	int k;
	int flag=0;
	int shifter=0;
	for(i=strlen(find)-1;i<strlen(text);i){
		flag=0;
		z=0;
		for(j=0;j<strlen(find) && flag==0;j++){
			if(text[i-j]!=find[strlen(find)-1-j] && text[i-j]+32!=find[strlen(find)-1-j]){
				flag=1;                                                                   
				if(text[i]>64 && text[i]<91){											 
				i+=getSlide(Table,text[i]+32,find);
			}
				else{
					i+=getSlide(Table,text[i],find);
				}
				}
			}
			if(flag==0){
				counter++;
				if(strlen(replace)>strlen(find)){
					shifter=strlen(replace)-strlen(find);
					for(k=initial+shifter;k>i+shifter;k--){
						text[k]=text[k-shifter];
					}
					for(k=0;k<strlen(replace);k++){
						text[k+i-j+1]=replace[k];
					}
					initial=initial+shifter;
					i=i+shifter;
				}
				else if(strlen(replace)==strlen(find)){
					for(k=0;k<strlen(find);k++){
						text[k+i-j+1]=replace[k];
					}
					i++;
				}
				else{
					shifter=strlen(find)-strlen(replace);

					for(k=0;k<strlen(replace);k++){
						text[k+i-j+1]=replace[k];
					}
					for(k=i-shifter+1;k<initial;k++){
						text[k]=text[k+shifter];
					}
					initial=initial+shifter;
					i=i-1;
				}
			}
		}
	return counter;	
}
int findReplace(){
	char find[100];
	char replace[100];
	char text[2000];	
	FILE *fp;
	char filename[100];
	clock_t start,end;
	char counter;
	
	printf("Masukkan Nama File:");
	gets(filename);
	fp=fopen(filename,"rb+");
	if(fp==NULL){
		printf("Error! File not found");
		return 1;
	}
	
	int i=0;

	while(!feof(fp) ){
		text[i]=fgetc(fp);
		i++;
	}
	text[i-1]='\0';
	
	printf("\nTeks Asli:\n%s",text);
	
	printf("\nMasukkan kata :");
	gets(find);
	
	printf("\nMasukkan Kata yang ingin diganti :");
	gets(replace);
	
	struct element *Table1;
	Table1=createTable(find);
	
	struct element *Table2;
	
			for(i=0;i<strlen(find);i++){
				if(find[i]<91 && find[i]>64){
					find[i]=find[i]+32;
				}
			}
			
		Table2=createTable(find);			
		counter=notSensitive(text,find,replace,Table2);
		fclose(fp);
		fp=fopen(filename,"w");
		for(i=0;i<strlen(text);i++){
			if(text[i]=='\r')
			text[i]=' ';
		}
		fputs(text,fp);
		printf("%s",text);
		fclose(fp);
		
		printf("\n Found and Replaced:%d",counter);	
		
	
	end=clock();
	 printf("\nRunning Time: %f ms",(double)((double)end-(double)start)/CLOCKS_PER_SEC);
	return 0;
}
