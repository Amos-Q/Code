#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())return false;
		//if (target < array[0][0])return false;
		int _length = array.size();
		for (int i = 0; i < _length; i++)
		{
			if (array[i].empty())continue;
			else if (target >= array[i][0])
			{
				if (target <= array[i][array[i].size() - 1])
				{
					for (int j = array[i].size() - 1; j >= 0; j--)
					{
						if (target == array[i][j])return 1;
						else if (target > array[i][j])break;
					}
				}
				else {
					continue;
				}
			}
			else return false;
		}
		return false;
	}
};

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL)
			return;
		int CountOfBlanks = 0;
		int Originallength = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			Originallength++;
			if (str[i] == ' ')
				++CountOfBlanks;
		}
		int len = Originallength + 2 * CountOfBlanks;
		if (len + 1 > length)
			return;

		char*pStr1 = str + Originallength;//¸´ÖÆ½áÊø·û¡®\0¡¯
		char*pStr2 = str + len;
		while (pStr1 < pStr2)
		{
			if (*pStr1 == ' ')
			{
				*pStr2-- = '0';
				*pStr2-- = '2';
				*pStr2-- = '%';
			}
			else
			{
				*pStr2-- = *pStr1;
			}
			--pStr1;
		}
	}
};

class Solution
{
public:
	vector<int> printListFromTailToHead(ListNode* head)
	{
		vector <int>  result;
		stack<int> arr;
		ListNode* p = head;
		while (p != NULL)
		{
			arr.push(p->val);
			p = p->next;
		}
		int len = arr.size();
		for (int i = 0; i < len; i++)
		{
			result.push_back(arr.top());
			arr.pop();
		}
		return  result;
	}

};