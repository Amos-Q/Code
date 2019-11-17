#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#define LEN sizeof(Date)
enum Weekdays {
	Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};//����weekdayö���ͱ���
typedef struct {
	int year;
	int month;
	int day;
	enum Weekdays weekday;
}Date;//�������ڵĽṹ����� 
int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//ƽ������ڣ����Խ���modify_year�޸�
Date refdate[7];//����7���ο����ڣ�����Ϊ��һ������
int datedistract(Date date1, Date date2); //��������ĺ��� 
bool isleapyear(int year);//�ж�����ĺ��� 
void modify_days(int *days, int year);//ͨ��������·������޸ĵĺ��� 
void findweekday(Date *datetime);
void weekdayprint(enum Weekdays weekday);
int count_days(int *days, Date *datetime); //����ṹ�����ڱ�����һ���д�����һ�� 
int main()
{
	printf("************���ڼ���ʵ��****************\n");
	bool next;//�Ƿ����
	do {
		Date *datetime = malloc(LEN);//����Date���͵Ľṹ��ָ��datetime,ͬʱ����һ���ڴ�(�������ڴ��ʹ�������)
		int i;
		for (i = 0; i < 7; i++)
		{
			refdate[i].year = 2018;
			refdate[i].month = 12;
			refdate[i].day = 10 + i;
		}//refdate�ṹ����������2018/12/20~2018/12/26��7�����ڣ�������������һ������ 
		printf("������һ������(year/month/day): ");
		scanf("%d/%d/%d", &datetime->year, &datetime->month, &datetime->day);
		printf("��������������е�����Ϊ%d\t", count_days(days, datetime));
		findweekday(datetime);
		weekdayprint(datetime->weekday);
		printf("\n�Ƿ����?(��:1,��:0):  ");
		//�Ƿ�������ж�����
		scanf("%d", &next);
		fflush(stdin);//ˢ�±�׼������������ѭ����ʱ���������һ��scanf 
	} while (next);
	return 0;
}
bool isleapyear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)return true;
			else return false;
		}
		else return true;
	}
	else return false;
}
//�����޸ĺ��� 
void modify_days(int *days, int year)
{
	if (isleapyear(year) == true)days[1] = 29;
	else days[1] = 28;
}
int count_days(int *days, Date *datetime)//��������·������Ѿ��ṹ�����¼�룬�����ڸ�������� 
{
	int i, count = 0;
	modify_days(days, datetime->year);
	for (i = 0; i < datetime->month - 1; i++)count += days[i];
	count += datetime->day;
	return count;
}
int datedistract(Date date1, Date date2)
{
	int year, month, day, count = 0;
	bool cmp;//�Ƚ����������ĸ���ǰ�棬����дѭ��
	Date temp;//��Ϊ�����������м����
	if (date1.year > date2.year)cmp = true;
	else if (date1.year < date2.year)cmp = false;
	else if (date1.month > date2.month)cmp = true;
	else if (date1.month < date2.month)cmp = false;
	else if (date1.day > date2.day)cmp = true;
	else cmp = false;
	if (cmp)
	{
		temp = date1;
		date1 = date2;
		date2 = temp;
	}
	//���date1��date2���棬�򽻻����ߣ���֤date1ʼ�ձ�date2С
	for (year = date1.year; year < date2.year; year++)count += isleapyear(year) ? 366 : 365;//�����Ƿ�Ϊ�������ۼ�
	count += count_days(days, &date2) - count_days(days, &date1);//������ͷ
	return abs(count);//������������
}
void findweekday(Date *datetime)
{
	int i;
	for (i = 0; i < 7; i++)
	{
		if (datedistract(*datetime, refdate[i]) % 7 == 0)
		{
			datetime->weekday = i;
			break;
		}
	}
}
void weekdayprint(enum Weekdays weekday)
{
	switch (weekday)
	{
	case 0:printf("����һ"); break;
	case 1:printf("���ڶ�"); break;
	case 2:printf("������"); break;
	case 3:printf("������"); break;
	case 4:printf("������"); break;
	case 5:printf("������"); break;
	case 6:printf("������"); break;
	}
}
