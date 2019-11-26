#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	FILE * pFile;
	long size;
	pFile = fopen("myfile.txt", "rb");
	if (pFile == NULL) perror("Error opening file");
	else
	{
		fseek(pFile, 0, SEEK_END); 
		size = ftell(pFile);
		fclose(pFile);
		printf("Size of myfile.txt: %ld bytes.\n", size);
	}
	return 0;
}