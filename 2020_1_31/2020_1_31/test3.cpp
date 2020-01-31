#define _CRT_SECURE_NO_WARNINGS 1
#include <assert.h>
#include <string.h>
#include <stack>

void CountLetter(const char *pSrc)
{
	int count[256] = {};
	for (; *pSrc != '\0'; ++pSrc)
	{
		const char &c = *pSrc;
		if ((c < 'A' || c > 'z') && (c < 'a' || c > 'z'))
		{
			continue;
		}
		++count[c];
	}
}

void SelectSort(int *pArray, int count)
{
	for (int i = 0; i < count; ++i)
	{
		//Ĭ�ϵ�λԪ����С
		int MinValue = pArray[i];
		//Ĭ�ϱ����λԪ�ص�����
		int MinIndex = i;
		//������һ��Ԫ�����Ƿ��б�����С��Ԫ��( ���� )
		for (int j = i + 1; j < count; ++j)
		{
			//�����ҵ�������С��Ԫ�����¸�ֵ�ͱ�������
			if (pArray[j] < MinValue)
			{
				MinValue = pArray[j];
				MinIndex = j;
			}
		}
		//���ҵ���СԪ�ط��������λ����
		const int Temp = pArray[i];
		pArray[i] = MinValue;
		pArray[MinIndex] = Temp;
	}
}

void BubbleSort(int *pArray, int count)
{
	//eg.[6][8][8][0][9][1]
	//i = 0,j < 5    [6][8][0][8][1][9]
	//i = 1,j < 4    [6][0][8][1][8][9]
	//i = 2,j < 3    [0][6][1][8][8][9]
	//i = 3,j < 2    [0][1][6][8][8][9]

	//����Ϊֹ�Ѿ�����OK��
	//i = 4,j < 1    [0][1][6][8][8][9]
	//i = 5,j < 0    [0][1][6][8][8][9]
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count - i - 1; ++j)
		{
			if (pArray[j] > pArray[j + 1])
			{
				const int Temp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = Temp;
			}
		}
	}
}

void MergeSort(int *pMerge, int *p1, int p1len, int *p2, int p2len)
{
	assert(nullptr != pMerge && nullptr != p1 && nullptr != p2);
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < p1len && j < p2len)
	{
		if (p1[i] < p2[j])
		{
			pMerge[k] = p1[i];
			++k;
			++i;
		}
		else
		{
			pMerge[k] = p2[j];
			++k;
			++j;
		}
	}
	while (i < p1len)
	{
		pMerge[k] = p1[i];
		++k;
		++i;
	}
	while (j < p2len)
	{
		pMerge[k] = p2[j];
		++k;
		++j;
	}
}

int FindSec(int *p, int len)
{
	assert(nullptr != p);
	int maxv = p[0];
	int secv = p[0];
	for (int i = 1; i < len; ++i)
	{
		if (maxv < p[i])
		{
			secv = maxv;
			maxv = p[i];
		}
	}
	return secv;
}