#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;
typedef struct tree* bintree;
typedef bintree position;
struct tree {
	int data;
	position lchild;
	position rchild;
};