#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define N 1000
int main()
{
	int n, i, s[N], A = 0, B = 0, C = 0, D = 0, E = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (s[i] >= 90)
			A++;
		else if (s[i] < 90 && s[i] >= 80)
			B++;
		else if (s[i] < 80 && s[i] >= 70)
			C++;
		else if (s[i] < 70 && s[i] >= 60)
			D++;
		else
			E++;
	}
	printf("%d %d %d %d %d", A, B, C, D, E);
	return 0;
}

#include<stdio.h>
#define N 1000
int main()
{
	int n, i, s[N], A = 0, B = 0, C = 0, D = 0, E = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (s[i] >= 90)
			A++;
		else if (s[i] < 90 && s[i] >= 80)
			B++;
		else if (s[i] < 80 && s[i] >= 70)
			C++;
		else if (s[i] < 70 && s[i] >= 60)
			D++;
		else
			E++;
	}
	printf("%d %d %d %d %d", A, B, C, D, E);
	return 0;
}

