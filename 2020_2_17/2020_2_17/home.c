#define _CRT_SECURE_NO_WARNINGS 1
#include"home.h"

int main() {
	int number;
	system("color e");
	mainmenuface();
	readfile();
	while (1) {

	loop: printf("-------------------��ѡ�����Ĳ�����----------------------\n");
		scanf("%d", &number);

		if (number >= 1 && number <= 9) {

			switch (number) {
			case 1:
				Inputdata();
				goto loop;
				break;
			case 2:
				Lookdata(head);
				break;
			case 3:
				Changedata(head);
				goto loop;
				break;
			case 4:
				Seek(head);
				break;
			case 5:
				Keepdata(head);
				break;
			case 6:
				Insertdata();
				break;
			case 7:
				deletedata();
				break;
			case 8:
				mainmenuface();
				break;
			case 9:
				exit(1);
				break;
			}
		}

		else {
			printf("---------------ѡ��Ĳ�������ȷ�����������룺------------------\n");
			goto loop;
		}

	}
	return 0;
}