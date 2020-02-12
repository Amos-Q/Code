#define _CRT_SECURE_NO_WARNINGS 1
char * reverseOnlyLetters(char * S) {
	int left = 0;
	int right = strlen(S) - 1;
	char tmp = 0;
	while (left <= right)
	{
		if (S[left] >= 'A'&&S[left] <= 'Z' || S[left] >= 'a'&&S[left] <= 'z')
		{
			if (S[right] >= 'A'&&S[right] <= 'Z' || S[right] >= 'a'&&S[right] <= 'z')
			{
				tmp = S[left];
				S[left] = S[right];
				S[right] = tmp;
				left++;
				right--;
			}
			else
			{
				right--;
			}
		}
		else
		{
			if (S[right] >= 'A'&&S[right] <= 'Z' || S[right] >= 'a'&&S[right] <= 'z')
			{
				left++;
			}
			else
			{
				left++;
				right--;
			}
		}
	}
	return S;
}
