#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	//����1
	int num = 0;
	scanf("%d", &num);
	int arr[1000] = { 0 };
	//����2
	int* ptr = NULL;
	ptr = (int*)malloc(num * sizeof(int));
	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
	{
		int i = 0;
		for (i = 0; i < num; i++)
		{
			*(ptr + i) = 0;
		}
	}
	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
	ptr = NULL;//�Ƿ��б�Ҫ��
	return 0;
}

int main()
{
	int *ptr = malloc(100);
	if (ptr != NULL)
	{
		//ҵ����
	}
	//��չ����
	//����1
	ptr = realloc(ptr, 1000);//����������(�������ʧ�ܻ���Σ�)

	//����2
	int*p = NULL;
	p = realloc(ptr, 1000);
	if (p != NULL)
	{
		ptr = p;
	}
	//ҵ����
	free(ptr);
	return 0;