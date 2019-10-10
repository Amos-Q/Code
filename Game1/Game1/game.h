#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<Windows.h>

void Playgame(char box[3][3], int row, int col);
void you(char box[3][3], int row, int col);
void mayplay(char box[3][3], int row, int col);
void complay(char box[3][3], int row, int col);
int win(char box[3][3], int row, int col);
int full(char box[3][3], int row, int col);