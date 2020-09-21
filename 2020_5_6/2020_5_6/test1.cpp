#include <iostream>
#include <cstdio>

using namespace std;

void isPrime(int n)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	int sum = 0;
	int t = 0;
	for (i = 2; i < n; i++)
	{
		sum = 0;
		for (j = 2; j <= i; j++)
		{
			if (i%j == 0)
				sum++;
		}
		if (sum <= 2)
		{
			t = i;
			if ((t - 1) % 10 == 0)
			{
				if (flag != 0)
				{
					printf(" ");
				}
				flag = 1;
				printf("%d", i);
			}
		}
	}
	if (flag == 0)
	{
		printf("%d", -1);
	}
}


int main() {
	int n = 0;
	while (cin >> n)
	{
		isPrime(n);
		cout << endl;
	}
	return 0;
}