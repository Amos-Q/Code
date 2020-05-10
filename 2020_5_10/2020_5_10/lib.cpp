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