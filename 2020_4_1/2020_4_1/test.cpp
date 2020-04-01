#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int &put(int n);
int vals[10];
int error = -1;
void main()
{
	put(0) = 10; //以put(0)函数值作为左值，等价于vals[0]=10; 
	put(9) = 20; //以put(9)函数值作为左值，等价于vals[9]=20; 
	cout << vals[0];
	cout << vals[9];
}
int &put(int n)
{
	if (n >= 0 && n <= 9) return vals[n];
	else { cout << "subscript error"; return error; }
}




union
{
	int i;
	char x[2];
}a;


void main()
{
	a.x[0] = 10;
	a.x[1] = 1;
	printf("%d", a.i);
}



for (int i = 2; i <= n; ++i)
{
	a[i] = true;
}

for (int i = 2; i <= n; ++i)
{
	if (a[i] == true)//这里作用，后边如果判断为非质数了，这里不成立 
	{
		for (j = 2 * i; j <= n; j += i)//这里除去所有2,3,4 ...的倍数 
		{
			a[j] = false;
		}
	}

}


for (int m = 2; m <= n; ++m)
{
	if (a[m])
	{
		printf("%d,", m);
	}
}

return 0;

