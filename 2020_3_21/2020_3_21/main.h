#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>

void select_Sort1(int a[], int n);
void select_Sort2(int a[], int n);
void bubble_Sort(int a[], int n);
void insert_Sort(int a[], int n);
void quick_Sort(int a[], int low, int high);
int findpos(int a[], int low, int high);