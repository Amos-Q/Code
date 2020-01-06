#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int bool;
#define false 0
bool SafeCheck(int Max[10][10], int Allocation[10][10], int Need[10][10], int Available[10], int safe[10], int MAX_PROCESS, int MAX_RESOURCE);
void ProbeAlloc(int Allocation[10][10], int Need[10][10], int Available[10], int process, int res[10], int MAX_RESOURCE);
void RollBack(int Allocation[10][10], int Need[10][10], int Available[10], int process, int res[10], int MAX_PROCESS, int MAX_RESOURCE);
void PrintTable(int Max[10][10], int Allocation[10][10], int Need[10][10], int Available[10],int MAX_PROCESS, int MAX_RESOURCE);
bool request(int Max[10][10], int process, int res[10], int Allocation[10][10], int Need[10][10], int Available[10], int safe[10], int MAX_PROCESS, int MAX_RESOURCE);