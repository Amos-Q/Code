#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int i = 0;                                              //����ȫ�ֱ���i

/*����Contact�࣬�����ı�š��������Ա𡢵绰��qq�š�סַ����ע����Ϣ*/
class Contact
{
private:
	string m_name;
	string m_ismale;
	string m_tel;
	string m_qq;
	string m_address;
	string m_remark;
public:
	void setname(string name);
	void setmale(string ismale);
	void settel(string tel);
	void setqq(string qq);
	void setaddress(string address);
	void setremark(string remark);
	void print(int j);
	string getname();
	string getmale();
	string gettel();
	string getqq();
	string getaddress();
	string getremark();
};