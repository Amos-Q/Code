#define _CRT_SECURE_NO_WARNINGS 1
void frequency(String& s, char& A[], int& C[], int &k)
{
	int i, j, len = s.length();
	if (!len) { cout << "The string is empty. " << endl;  k = 0;  return; }
	else
	{
		A[0] = s[0];  C[0] = 1;  k = 1;  	/*���s[i]�Ǵ������ز���*/
		for (i = 1; i < len; i++) C[i] = 0;  			/*��ʼ��*/
		for (i = 1; i < len; i++)
		{	 		/*��⴮�������ַ�*/
			j = 0;   while (j < k && A[j] != s[i]) j++; /*���s[i]�Ƿ�����A[ ]��*/
			if (j == k)
			{
				A[k] = s[i]; C[k]++; k++
			}		/*s[i]��δ����*/
			else C[j]++;			/*s[i]�Ѿ�����*/
		}
	}
}
#include <assert.h>
template <class Type> class Queue {	//ѭ�����е��ඨ��
public:
	Queue(int = 10);
	~Queue() { delete[] elements; }
	void EnQueue(Type & item);
	Type DeQueue();
	Type GetFront();
	void MakeEmpty() { length = 0; }		//�ÿն���
	int IsEmpty() const { return length == 0; }	//�ж��пշ�
	int IsFull() const { return length == maxSize; }	//�ж�������
private:
	int rear, length;				//��βָ��Ͷ��г���
	Type *elements;				//��Ŷ���Ԫ�ص�����
	int maxSize;				//������������Ԫ�ظ���
}��