#define _CRT_SECURE_NO_WARNINGS 1
#include "home.h"

int main()
{
	load();
	face();//调用face函数以展现主页面
	menu();//调用menu以展示功能菜单
	return 0;
}
//一定要注意文件的内容格式要与fscanf()里面的格式一一对应，此处不是代码注释 可删。
