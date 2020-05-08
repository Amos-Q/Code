#define _CRT_SECURE_NO_WARNINGS 1
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