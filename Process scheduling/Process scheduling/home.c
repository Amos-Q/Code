#include "home.h"

int main()
{
	int num = 0;
	printf("��������̸���:");
	scanf("%d",&num);
	struct Node job[10];
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("�����������������ʱ�䡢����ʱ��:\n");
		scanf("%s", &job[i].name);
		scanf("%d",&job[i].Tarrive);
		scanf("%d",&job[i].Tservice);
	}
	display(job,num);
	system("pause");
	return 0;
}
