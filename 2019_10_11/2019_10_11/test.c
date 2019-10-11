#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//先去掉前面的空格，再去掉后面的空格
int trimSpace(char *inbuf, char *outbuf) {
	char *p = inbuf;
	//查看有多少个空格
	int len = 0;
	while (p[len] == ' ') {
		len++;
	}

	//将字符串进行前移
	int i = len;
	while (p[i]) {
		p[i - len] = p[i];
		i++;
	}
	p[i - len] = '\0';

	//去掉后面的字符串
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