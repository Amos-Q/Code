#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	char* p = "hello world";
	int a = 123;
	// itoa

	FILE* fin = fopen("test.txt", "w");
	fputs(p, fin);

	// 文本
	fputs("10000", fin);


	fclose(fin);

	return 0;
}

struct ContactInfo
{
	char name[20];
	char tel[20];
	int age;
};

int main()
{
	struct ContactInfo infos[2] = { { "jack", "18516283075", 18 }, { "rose", "18516283076", 17 } };

	FILE* fin = fopen("contact.bin", "wb");
	// 二进制写
	fwrite(infos, sizeof(struct ContactInfo), 2, fin);

	fclose(fin);

	FILE* fout = fopen("contact.bin", "rb");
	struct ContactInfo rd_infos[2];
	// 二进制读
	fread(rd_infos, sizeof(struct ContactInfo), 2, fout);

	fclose(fout);
};

int main()
{
	struct ContactInfo infos[2] = { { "jack", "18516283075", 18 }, { "rose", "18516283076", 17 } };

	FILE* fin = fopen("contact.txt", "w");
	// 文本写
	//fprintf(stdout, "%s\n%s\n%d", infos[0].name, infos[0].tel, infos[0].age);
	fprintf(fin, "%s\n%s\n%d", infos[0].name, infos[0].tel, infos[0].age);


	fclose(fin);

	FILE* fout = fopen("contact.txt", "r");
	struct ContactInfo rd_infos[2];
	//fscanf(stdin, "%s%s%d", rd_infos[0].name, rd_infos[0].tel, &rd_infos[0].age);
	fscanf(fout, "%s%s%d", rd_infos[0].name, rd_infos[0].tel, &rd_infos[0].age);


	fclose(fout);
};

int main()
{
	int a = 0;
	for (; a < 10; ++a)
	{
		printf("%d\n", a);
	}
	int i = 0;
	++i;

	return 0;
}