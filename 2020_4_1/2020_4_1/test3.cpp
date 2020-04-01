#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;
int n, f;
int a[505][505];
int s[505], j[505], t, ma, o = 505, k[505], q;//,l[505];
void bs(int x)
{
	cout << x << endl;
	a[x][x] = 0;
	for (int i = 1; i <= 505; i++)
	{
		if (a[x][i] > 0)
		{
			a[x][i]--;
			a[i][x]--;
			bs(i);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);


	cin >> f;
	for (int i = 1; i <= f; i++)
	{
		long long x, y;
		scanf("%lld%lld", &x, &y);
		if (k[x] == 0)
		{
			k[x] = 1;
			q++;

		}
		if (k[y] == 0)
		{
			k[y] = 1;
			q++;

		}
		a[x][y]++;
		a[y][x]++;
		s[y]++;
		s[x]++;
		if (x <= o)
			o = x;
		if (y <= o)
			o = y;
	}
	for (int i = 1; i <= f; i++)
		if (s[i] % 2 == 1)
		{
			t = i;
			bs(i);
			exit(0);
		}

	if (t == 0)
		bs(o);
	return 0;
}