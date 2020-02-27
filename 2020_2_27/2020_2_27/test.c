#define _CRT_SECURE_NO_WARNINGS 1
#include "hospital.h"

void cmd_process(int argc, char* argv[])
{
	char *pszCmd = NULL;
	int iCmdNum = 0;
	//内存分配失败，退出函数
	pszCmd = (char*)malloc(CMD_LEN);
	if (NULL == pszCmd)
	{
		return;

	}
}

int main(int argc, char* argv[])
{
	cmd_process(argc, argv);
	return 0;
}