#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int &put(int n);
int vals[10];
int error = -1;
void main()
{
	put(0) = 10; //��put(0)����ֵ��Ϊ��ֵ���ȼ���vals[0]=10; 
	put(9) = 20; //��put(9)����ֵ��Ϊ��ֵ���ȼ���vals[9]=20; 
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
	if (a[i] == true)//�������ã��������ж�Ϊ�������ˣ����ﲻ���� 
	{
		for (j = 2 * i; j <= n; j += i)//�����ȥ����2,3,4 ...�ı��� 
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

