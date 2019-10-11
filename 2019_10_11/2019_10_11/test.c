#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//��ȥ��ǰ��Ŀո���ȥ������Ŀո�
int trimSpace(char *inbuf, char *outbuf) {
	char *p = inbuf;
	//�鿴�ж��ٸ��ո�
	int len = 0;
	while (p[len] == ' ') {
		len++;
	}

	//���ַ�������ǰ��
	int i = len;
	while (p[i]) {
		p[i - len] = p[i];
		i++;
	}
	p[i - len] = '\0';

	//ȥ��������ַ���
	for (int j = 0; j < strlen(p); j++) {
		if (p[j] == ' ') {
			p[j] = '\0';
			outbuf = p;
			return 1;
		}
	}
	return 0;
}


int main() {
	char str[] = "        abcdefgdddd        ";
	char *outbuf = NULL;

	if (trimSpace(str, outbuf)) {
		printf("start.%s.end", str);
	}
	else {
		printf("No need for trim.");
	}
	system("pause");
	return 0;
}