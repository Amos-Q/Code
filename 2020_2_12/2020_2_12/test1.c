#define _CRT_SECURE_NO_WARNINGS 1
bool isLongPressedName(char * name, char * typed) {
	char* next = typed;
	while (*name != '\0')
	{
		if (*name == *next)
		{
			typed = next;
			name++;
			next++;
		}
		else
		{
			if (*next == *typed)
			{
				next++;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

int cmp(const void * a, const void * b)
{
	return *(int*)a - *(int*)b;
	//return *(int*)b-*(int*)a;
}

int* sortedSquares(int* A, int ASize, int* returnSize) {
	*returnSize = ASize;
	int* returns = (int*)malloc(sizeof(int)*ASize);
	for (int i = 0; i < ASize; i++)
	{
		returns[i] = A[i] * A[i];
	}
	qsort(returns, ASize, sizeof(int), cmp);
	return returns;
}