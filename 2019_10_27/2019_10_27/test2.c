#define _CRT_SECURE_NO_WARNINGS 1
int Invert2(char* str)
{
	if (str == NULL)
		return -1;

	int num = 0, negFlag = 0;
	if (str[0] == '-')
	{
		negFlag = 1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			num = num * 10 + (*str - '0');
		}
		else
		{
			num = -1;
			break;
		}
		str++;
	}

	if (negFlag)
		num *= -1;

	return num;
}
int main(int argc, char *argv[])
{
	if (1)
	{
		char *str1 = "1234";
		int str_i1 = Invert2(str1);
		printf("str1=%s, str_i1=%d\n", str1, str_i1);
		char *str2 = "-1234";
		int str_i2 = Invert2(str2);
		printf("str2=%s, str_i2=%d\n", str2, str_i2);
		char *str3 = "-12s4";
		int str_i3 = Invert2(str3);
		printf("str3=%s, str_i3=%d\n", str3, str_i3);
	}
	return 0;
}
