#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct student{
	int mid;
	int final;
	int hmws;
};
int main() 
{
	struct student sam = { 85, 90, 88 };
	struct student tom = { 93, 88, 91 };
	struct student *he = &tom;
	tom = sam;
	printf("tom = {%d, %d, %d}\n", tom.mid, tom.final, tom.hmws);
	printf("*he = {%d, %d, %d}\n", he->mid, he->final, he->hmws);
	printf("*he = {%d, %d, %d}\n", (*he).mid, (*he).final, (*he).hmws);
 }