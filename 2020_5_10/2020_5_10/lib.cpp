#define _CRT_SECURE_NO_WARNINGS 1
#include "lib.h"

void Contact::setname(string name)
{
	m_name = name;
}

void Contact::setmale(string ismale)
{
	m_ismale = ismale;
}

void Contact::settel(string tel)
{
	m_tel = tel;
}

void Contact::setqq(string qq)
{
	m_qq = qq;
}

void Contact::setaddress(string address)
{
	m_address = address;
}

void Contact::setremark(string remark)
{
	m_remark = remark;
}

void Contact::print(int j)
{
	cout << "＊＊＊＊＊＊＊＊＊＊＊＊＊＊" << endl;
	cout << "编号：" << j << endl;
	cout << "姓名：" << m_name << endl;
	cout << "性别：" << m_ismale << endl;
	cout << "电话：" << m_tel << endl;
	cout << "QQ号：" << m_qq << endl;
	cout << "地址：" << m_address << endl;
	cout << "备注：" << m_remark << endl;
	cout << endl;
}

string Contact::getname()
{
	return m_name;
}

string Contact::getmale()
{
	return m_ismale;
}

string Contact::gettel()
{
	return m_tel;
}

string Contact::getqq()
{
	return m_qq;
}

string Contact::getaddress()
{
	return m_address;
}

string Contact::getremark()
{
	return m_remark;
}


void clear()
{
	system("clear");                                                //清屏
}

void interface()                                                    //界面函数，输出主界面
{
	cout << "         *********************************************************************************       " << endl;
	cout << "         *                                       *               " << endl;
	cout << "     *                                               *       " << endl;
	cout << "     |                                               |       " << endl;
	cout << "     |                      通  讯  录                      |       " << endl;
	cout << "     |                                               |       " << endl;
	cout << "     |                   ～～～～～～～～                    |       " << endl;
	cout << "     |                     1、添加好友；                       |       " << endl;
	cout << "     |                     2、查看列表；                       |       " << endl;
	cout << "     |                     3、删除好友；                       |       " << endl;
	cout << "     |                     4、查找好友；                       |       " << endl;
	cout << "     |                     5、修改信息；                       |       " << endl;
	cout << "     |                     6、退出程序；                       |       " << endl;
	cout << "     |                   ～～～～～～～～                    |       " << endl;
	cout << "     |                                               |       " << endl;
	cout << "     |           功能：1.ADD、2.LIST、3.DELETE、4.SEEK、5.REVISE、6.EXIT         |       " << endl;
	cout << "     |           请在下面输入1、2、3、4、5、6选择你的操作。                |       " << endl;
	cout << "     |                                               |       " << endl;
	cout << "     *                                               *       " << endl;
	cout << "         *                                       *               " << endl;
	cout << "         *********************************************************************************       " << endl;
}

void add(Contact *p)
{
	char c;
	string name;
	string ismale;
	string tel;
	string qq;
	string address;
	string remark;

	do
	{
		clear();

		cout << "请输入联系人姓名：";
		__fpurge(stdin);
		cin >> name;
		p[i].setname(name);

		cout << "请输入联系人性别：";
		__fpurge(stdin);
		cin >> ismale;
		p[i].setmale(ismale);

		cout << "请输入联系人电话：";
		__fpurge(stdin);
		cin >> tel;
		p[i].settel(tel);

		cout << "请输入联系人QQ号：";
		__fpurge(stdin);
		cin >> qq;
		p[i].setqq(qq);

		cout << "请输入联系人住址：";
		__fpurge(stdin);
		cin >> address;
		p[i].setaddress(address);

		cout << "请输入联系人备注：";
		__fpurge(stdin);
		cin >> remark;
		p[i].setremark(remark);

		i++;

		cout << "是否继续添加：(y/other):";
		__fpurge(stdin);

		cin >> c;
	} while (c == 'y');
}

void list(Contact *p)
{
	clear();

	int j = 0;

	for (j = 0; j < i; j++)
	{
		p[j].print(j);
	}
}

int findnum(string s, int *accumlate, Contact *p)
{
	int m = 0;
	int j = 0;

	for (m = 0; m < i; m++)
	{
		if (s == p[m].getname())
		{
			accumlate[j++] = m;
		}
	}
	return j;
}

void seek(Contact *p)                                               //定义查找函数，通过姓名查找
{
	char c = 0;
	do
	{
		clear();

		int j = 0;
		int temp = 0;
		int accum = 0;
		int a[20] = { 0 };
		string name;

		cout << "请输入你想查找的联系人的姓名：";
		cin >> name;

		accum = findnum(name, a, p);                              //调用findnum函数，并把找到几个联系人赋给accum

		if (accum == 0)
		{
			cout << "此联系人不存在！" << endl;
		}

		else if (accum == 1)                                       //如果找到一个联系人，输出这个联系人的信息
		{
			temp = a[0];
			p[temp].print(temp);
		}

		else if (accum > 1)                                        //找到不止一个联系人，输出全部联系人信息
		{
			cout << "有" << accum << "个联系人！" << endl;
			for (j = 0; j < accum; j++)
			{
				temp = a[j];
				p[temp].print(temp);
			}
		}
		cout << "是否继续查找? (y/other) :";
		__fpurge(stdin);
		cin >> c;

	} while (c == 'y');
}

void coverdata(int j, Contact *p)                                 //定义覆盖信息函数
{
	int m = 0;
	char c = 0;
	string name;
	string ismale;
	string tel;
	string qq;
	string address;
	string remark;

	cout << "是否删除该联系人？(y/n)";
	__fpurge(stdin);
	cin >> c;

	if (c == 'y')
	{
		for (m = j; m < i; m++)
		{
			name = p[m + 1].getname();
			p[m].setname(name);
			ismale = p[m + 1].getmale();
			p[m].setmale(ismale);
			tel = p[m + 1].gettel();
			p[m].settel(tel);
			qq = p[m + 1].getqq();
			p[m].setqq(qq);
			address = p[m + 1].getaddress();
			p[m].setaddress(address);
			remark = p[m + 1].getremark();
			p[m].setremark(remark);
		}
		i--;                                                        //将后一个的信息传给前一个
		cout << "删除成功！" << endl;
	}
}