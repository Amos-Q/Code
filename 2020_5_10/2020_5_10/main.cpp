#define _CRT_SECURE_NO_WARNINGS 1

#include "lib.h"

int main()
{
	Contact *p = new Contact[100];                                  //������p
	for (; ; )
	{
		int temp = 0;
		clear();
		interface();                                                //����interface���������������
		__fpurge(stdin);
		scanf("%d", &temp);

		switch (temp)                                                //switch���ѡ����
		{
		case 1: {
			add(p);
			printf("��enter���������棡\n");
			__fpurge(stdin);
			getchar();                                   //��ͣ���棬��������˳�����ѡ�����
			break;
		}

		case 2: {
			list(p);
			printf("��enter���������棡\n");
			__fpurge(stdin);
			getchar();
			break;
		}

		case 3: {
			mydelete(p);
			printf("��enter���������棡\n");
			__fpurge(stdin);
			getchar();
			break;
		}

		case 4: {
			seek(p);
			printf("��enter���������棡\n");
			__fpurge(stdin);
			getchar();
			break;
		}

		case 5: {
			revise(p);
			printf("��enter���������棡\n");
			__fpurge(stdin);
			getchar();
			break;
		}

		case 6:exit(0);

		default: {
			printf("�������!");
			printf("��enter���������棡\n");
			__fpurge(stdin);
			getchar();
			break;
		}
		}
	}
	return 0;
}