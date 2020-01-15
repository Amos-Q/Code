#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

boolean JudgeSafe() { //判断是否安全
	int i = 0, j = 0;
	for (i = 0; i < 5; i++)
	{
		Finish[i] = false;
		WorkSign[i].A = 0;
		WorkSign[i].B = 0;
		WorkSign[i].C = 0;
	}
	int step[5];
	Work = Available;
	for (i = 0; i < 5; i++) {
		if (Finish[i] == false) {
			if (Work.A >= Need[i].A&&Work.B >= Need[i].B&&Work.C >= Need[i].C) {
				WA[i].A = Work.A + Allocation[i].A;
				WA[i].B = Work.B + Allocation[i].B;
				WA[i].C = Work.C + Allocation[i].C;
				WorkSign[j].A = Work.A;
				WorkSign[j].B = Work.B;
				WorkSign[j].C = Work.C;
				step[j] = i;
				j++;
				Work.A = WA[i].A;
				Work.B = WA[i].B;
				Work.C = WA[i].C;
				Finish[i] = true;
				i = -1;
			}
		}
	}
	if (Finish[0] == true && Finish[1] == true && Finish[2] == true && Finish[3] == true && Finish[4] == true)
	{
		printf("Finish为0代表False，Finish为1代表True\n");
		printf("     Work          Need        Allocation       Work+Allocation       Finish\n");
		printf("     A  B  C      A  B  C       A  B  C            A  B  C\n");
		for (i = 0; i < 5; i++)
		{
			printf("P%d  %2d %2d %2d     %2d %2d %2d      %2d %2d %2d           %2d %2d %2d          %5d\n", step[i], WorkSign[i].A, WorkSign[i].B, WorkSign[i].C,
				Need[step[i]].A, Need[step[i]].B, Need[step[i]].C, Allocation[step[i]].A, Allocation[step[i]].B, Allocation[step[i]].C,
				WA[step[i]].A, WA[step[i]].B, WA[step[i]].C, Finish[step[i]]);
		}
		printf("此时安全,序列为：");
		for (i = 0; i < 5; i++)
		{
			printf("P%d ", step[i]);
		}
		printf("\n");
		return true;
	}
	else return false;
}
int main()
{
	system("pause");
	return 0;
}