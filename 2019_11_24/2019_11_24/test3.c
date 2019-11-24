#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fin = fopen("D:\\课堂代码\\65班\\11-21\\11-21\\test.c", "a");
	fputc('h', fin);
	fputc('e', fin);
	fputc('l', fin);
	fputc('l', fin);
	fputc('o', fin);

	//getchar();

	return 0;
}

int main()
{
	//FILE* fin = fopen("D:\\课堂代码\\65班\\11-21\\11-21\\test.c", "w");
	//fputs("#include<stdio.h>\n", fin);
	//fputs("int main()\n", fin);
	//fputs("{\n", fin);
	//fputs("     printf(\"hello world\n\");\n", fin);
	//fputs("}\n", fin);




	return 0;
}

int main()
{
	FILE* fout = fopen("main.cpp", "r");
	FILE* fin = fopen("main.c", "w");

	int flag = 0;

	char out_ch = fgetc(fout);
	while (out_ch != EOF)
	{
		if (out_ch == '/')
		{
			char next_ch = fgetc(fout);
			if (next_ch == '/')
			{
				//fputc('/', fin);
				//fputc('*', fin);
				fputs("/*", fin);

				flag = 1;
			}
			else
			{
				fputc(out_ch, fin);
				fputc(next_ch, fin);
			}
		}
		else
		{
			if (flag == 1 && out_ch == '\n')
			{
				fputs("*/", fin);
				fputc('\n', fin);
				flag = 0;
			}
			else
			{
				fputc(out_ch, fin);
			}
		}

		out_ch = fgetc(fout);
	}

	fclose(fout);
	fclose(fin);

	return 0;
}


int main()
{
	FILE* fout = fopen("test.txt", "r");
	char out_ch;
	for (size_t i = 0; i < 5; ++i)
	{
		out_ch = fgetc(fout);
		printf("%c", out_ch);
	}
	fseek(fout, 5, SEEK_CUR);

	while (out_ch != EOF)
	{
		out_ch = fgetc(fout);
		printf("%c", out_ch);
	}

	return 0;
}

int main()
{
	FILE* fout = fopen("11-21(文件).wmv", "rb");
	char ch = fgetc(fout);
	fseek(fout, 0, SEEK_END);
	long long n = ftell(fout);
	printf("%d\n", n);

	fseek(fout, 0, SEEK_SET);
	while (n--)
	{
		printf("%c", ch);
		ch = fgetc(fout);
	}

	printf("%d\n", n);

	//if (feof(fout) != 0)
	//{
	//	printf("read end of file\n");
	//}

	//if (ferror(fout) != 0)
	//{
	//	printf("read error\n");
	//}

	//判断是什么原因结束的
	if (ferror(fout))
		puts("I/O error when reading");
	else if (feof(fout))
		puts("End of file reached successfully");

	return 0;
}

int main()
{
	char* p = "hello world";
	int a = 10000;

	FILE* fin = fopen("test.txt", "w");
	fputs(p, fin);
	//fputc('\n', fin);


	// 二进制
	fwrite(&a, sizeof(int), 1, fin);

	//fputc('\n', fin);

	fclose(fin);

	return 0;
}

int main()
{

	char p[100];
	FILE* fin = fopen("test.txt", "rb");
	int n = fgets(p, 12, fin);
	int a;
	fread(&a, sizeof(int), 1, fin);

	printf("%s", p);
	printf("%d", a);

	return 0;
//}