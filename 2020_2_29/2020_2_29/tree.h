#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50
typedef char DATA;       //����Ԫ������ 
typedef struct ChainTree  //���������������� 
{
	DATA data;  //Ԫ������
	struct ChainTree *left; //���������ָ��
	struct ChainTree *right;    //���������ָ��
}ChainBinTree;