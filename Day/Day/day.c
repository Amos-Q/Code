#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#define LEN sizeof(Date)
enum Weekdays {
	Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};//定义weekday枚举型变量
typedef struct {
	int year;
	int month;
	int day;
	enum Weekdays weekday;
}Date;//定义日期的结构体变量 
int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//平年的日期，可以借助modify_year修改
Date refdate[7];//定义7个参考日期，依次为周一到周日
int datedistract(Date date1, Date date2); //日期相减的函数 
bool isleapyear(int year);//判断闰年的函数 
void modify_days(int *days, int year);//通过闰年对月份日期修改的函数 
void findweekday(Date *datetime);
void weekdayprint(enum Weekdays weekday);
int count_days(int *days, Date *datetime); //计算结构体日期变量在一年中处于哪一天 
int main()
{
	printf("************日期计算实验****************\n");
	bool next;//是否继续
	do {
		Date *datetime = malloc(LEN);//定义Date类型的结构体指针datetime,同时开辟一段内存(不开辟内存会使程序崩溃)
		int i;
		for (i = 0; i < 7; i++)
		{
			refdate[i].year = 2018;
			refdate[i].month = 12;
			refdate[i].day = 10 + i;
		}//refdate结构体数组存放了2018/12/20~2018/12/26的7个日期，他们正好是周一到周日 
		printf("请输入一个日期(year/month/day): ");
		scanf("%d/%d/%d", &datetime->year, &datetime->month, &datetime->day);
		printf("该日期所在年份中的天数为%d\t", count_days(days, datetime));
		findweekday(datetime);
		weekdayprint(datetime->weekday);
		printf("\n是否继续?(是:1,否:0):  ");
		//是否继续的判断如下
		scanf("%d", &next);
		fflush(stdin);//刷新标准输入流，否则循环的时候会跳过第一个scanf 
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
//闰年修改函数 
void modify_days(int *days, int year)
{
	if (isleapyear(year) == true)days[1] = 29;
	else days[1] = 28;
}
int count_days(int *days, Date *datetime)//将该年各月份日期已经结构体变量录入，计算在该年的天数 
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
	bool cmp;//比较两个日期哪个在前面，方便写循环
	Date temp;//作为交换变量的中间变量
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
	//如果date1在date2后面，则交换二者，保证date1始终比date2小
	for (year = date1.year; year < date2.year; year++)count += isleapyear(year) ? 366 : 365;//按照是否为闰年书累加
	count += count_days(days, &date2) - count_days(days, &date1);//计算零头
	return abs(count);//返回所差日期
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
	case 0:printf("星期一"); break;
	case 1:printf("星期二"); break;
	case 2:printf("星期三"); break;
	case 3:printf("星期四"); break;
	case 4:printf("星期五"); break;
	case 5:printf("星期六"); break;
	case 6:printf("星期日"); break;
	}
}
