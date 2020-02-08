#define _CRT_SECURE_NO_WARNINGS 1

bool canConstruct(char * ransomNote, char * magazine) {
	if (*ransomNote != '\0' && *magazine == '\0')
		return false;
	if ((*ransomNote == '\0' && *magazine != '\0') || (*ransomNote == '\0' && *magazine == '\0'))
		return true;
	char* head = ransomNote;
	char* next = magazine;
	while (*head != '\0')
	{
		if (*head == *next)
		{
			*next = '1';
			head++;
			next = magazine;
		}
		else
		{
			next++;
		}
		if (*next == '\0')
			return false;
	}
	return true;
}


