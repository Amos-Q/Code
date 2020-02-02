#define _CRT_SECURE_NO_WARNINGS 1
#include < iostream >
#include < fstream >
using namespace std;
void main()
{
	char a[100];
	ofstream writeFile("text.txt");
	int i;
	while (1)
	{
		cin >> a;
		if (a[0] == '$')
			return;
		i = 0;
		while (a[i] != '\0')
		{
			if (a[i] >= 65 && a[i] <= 90)
				a[i] = a[i] + 32;
			i++;
		}
		writeFile << a << " ";
	}
}