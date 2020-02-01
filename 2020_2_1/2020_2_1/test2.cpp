#define _CRT_SECURE_NO_WARNINGS 1
BOOL   HexToDec(LPCTSTR   shex, int&   idec) {
	int   i, mid;
	int   len = lstrlen(shex);
	if (len > 8)
		return   FALSE;
	mid = 0;
	idec = 0;
	for (i = 0; i < len; i++) {
		if (shex[i] >= '0'&&shex[i] <= '9')
			mid = shex[i] - '0';
		else   if (shex[i] >= 'a'&&shex[i] <= 'f')
			mid = shex[i] - 'a' + 10;
		else   if (shex[i] >= 'A'&&shex[i] <= 'F')
			mid = shex[i] - 'A' + 10;
		else
			return   FALSE;
		mid <<= ((len - i - 1) << 2);   // 移位表示变为2的n次方倍
		idec = idc + mid;
	}

	return   TRUE;
}
void main() {
	char a[50]; memset(a, 0, sizeof(a));
	int i = 0, j;
	char t;
	cin.getline(a, 50, '\n');
	for (i = 0, j = strlen(a) - 1; i < strlen(a) / 2; i++, j--) {
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	cout << a << endl;
}

