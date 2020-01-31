#define _CRT_SECURE_NO_WARNINGS 1
#include <assert.h>
#include <string.h>
#include <stack>

//////////////////////////////////////////////////////////////////////////  
// C++ 经典面试算法题  [7/28/2016 FreeAngel]  

//1.实现strcpy.  
char* MyStrCpy(char *pDest, const char *pSrc)
{
	if (nullptr == pDest || nullptr == pSrc)
	{
		return nullptr;
	}
	if (pDest == pSrc)
	{
		return pDest;
	}
	char *pIter = pDest;
	while ((*pIter++ = *pSrc++) != '\0');
	return pDest;
}

//2.实现strcat.  
char* MyStrCat(char *pDest, const char *pSrc)
{
	if (nullptr == pDest || nullptr == pSrc)
	{
		return nullptr;
	}

	char *pIter = pDest + strlen(pDest);
	while ((*pIter++ = *pSrc++) != '\0');
	return pDest;
}

//3.实现CString字符串类缺省四个方法  
class MyCString
{
public:

	MyCString(char *pData = nullptr)
	{
		if (nullptr == pData)
		{
			mpData = new char[1];
			assert(nullptr != mpData);
			*mpData = '\0';
		}
		else
		{
			mpData = new char[strlen(pData) + 1];
			assert(nullptr != mpData);
			strcpy(mpData, pData);
		}
	}

	MyCString(const MyCString &Other)
	{
		mpData = new char[strlen(Other.mpData) + 1];
		assert(nullptr != mpData);
		strcpy(mpData, Other.mpData);
	}

	~MyCString()
	{
		if (nullptr != mpData)
		{
			delete[] mpData;
			mpData = nullptr;
		}
	}

	const MyCString& operator =(const MyCString &Other)
	{
		if (this == &Other)
		{
			return *this;
		}
		delete[] mpData;
		mpData = new char[strlen(Other.mpData) + 1];
		assert(nullptr != mpData);
		strcpy(mpData, Other.mpData);
		return *this;
	}

private:

	char *mpData;
};

//4.不使用第三个变量交换两个数的值  
void SwapA(int &A, int &B)
{
	if (A == B)
	{
		return;
	}
	A = A + B;
	B = A - B;
	A = A - B;
}
void SwapB(unsigned int &A, unsigned int &B)
{
	if (A == B)
	{
		return;
	}
	A = A ^ B;
	B = A ^ B;
	A = A ^ B;
}

//5.C语言中字符串转数字的方法是什么( atoi )，请实现它  
int Myatoi(const char *pString)
{
	assert(nullptr != pString);
	const int Len = strlen(pString);
	int Value = 0;
	int Times = 1;
	for (int i = Len - 1; i >= 0; --i, Times *= 10)
	{
		Value += (pString[i] - '0') * Times;
	}
	return Value;
}

//6.实现一个将字符串逆序的方法  
char* MyInverted(char *pDest)
{
	assert(nullptr != pDest);
	const int Len = strlen(pDest);
	char T = 0;
	for (int i = 0; i < Len / 2; ++i)
	{
		T = pDest[i];
		pDest[i] = pDest[Len - i - 1];
		pDest[Len - i - 1] = T;
	}
	return pDest;
}

//7.实现一个将字符串中所有字母转换为大写的方法  
char* MyUpper(char *pDest)
{
	assert(nullptr != pDest);
	for (char *i = pDest; *i != '\0'; ++i)
	{
		if (*i < 'a' || *i > 'z')
		{
			continue;
		}
		*i -= 'a' - 'A';
	}
	return pDest;
}

//8.已知一个数组已经降序排序请用二分查字法找到其中的某个元素找到返回索引否则返回-1  
int BinarySearch(int *pArray, int Count, int Value)
{
	assert(nullptr != pArray);
	int Left = 0;
	int Right = Count - 1;
	int Mid = 0;
	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;
		if (Value < pArray[Mid])
		{
			Right = Mid - 1;
		}
		else if (Value > pArray[Mid])
		{
			Left = Mid + 1;
		}
		else
		{
			return Mid;
		}
	}
	return -1;
}

struct Node
{
	Node *mpNext;
	int mData;
};
//9.删除链表中值为Value的所有元素( [Head]->[node1]->[node2]->...[noden] )
void DeleteFromList(Node *pHead, int Value)
{
	Node *pPrev = pHead;
	Node *pNext = pHead->mpNext;
	while (nullptr != pNext)
	{
		if (pNext->mData != Value)
		{
			pPrev = pNext;
			pNext = pNext->mpNext;
		}
		else
		{
			pPrev->mpNext = pNext->mpNext;
			delete pNext;
			pNext = pPrev->mpNext;
		}
	}
}

//10.在链表Index位置插入新的值为Value的元素  
void InsertFromList(Node *pHead, int Index, int Value)
{
	Node *pIter = pHead;
	for (int i = 0; i < Index && nullptr != pIter; ++i, pIter = pIter->mpNext);
	assert(nullptr != pIter);
	Node *pNew = new Node;
	pNew->mData = Value;
	pNew->mpNext = pIter->mpNext;
	pIter->mpNext = pNew;
}