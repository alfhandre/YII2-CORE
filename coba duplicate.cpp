#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char c;
	char namadup[30];
	
	printf("==============================\n");
	printf("Nama File yang akan diduplicate (MAKS 30 KARAKTER):");
	gets(namadup);

	ifstream i_file(namadup);
	ofstream o_file("new.txt");
	
	while(i_file.get(c))
	{
		o_file.put(c);
	}
	i_file.close();
	o_file.close();
	cout<<"Duplicate file berhasil";
	return 0;	 
}