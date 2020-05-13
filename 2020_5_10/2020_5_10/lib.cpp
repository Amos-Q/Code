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
	cout << "����������������������������" << endl;
	cout << "��ţ�" << j << endl;
	cout << "������" << m_name << endl;
	cout << "�Ա�" << m_ismale << endl;
	cout << "�绰��" << m_tel << endl;
	cout << "QQ�ţ�" << m_qq << endl;
	cout << "��ַ��" << m_address << endl;
	cout << "��ע��" << m_remark << endl;
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
	system("clear");                                                //����
}

void interface()                                                    //���溯�������������
{
	cout << "         *********************************************************************************       " << endl;
	cout << "         *                                       *               " << endl;
	cout << "     *                                               *       " << endl;
	cout << "     |                                               |       " << endl;
	cout << "     |                      ͨ  Ѷ  ¼                      |       " << endl;
	cout << "     |                                               |       " << endl;
	cout << "     |                   ����������������                    |       " << endl;
	cout << "     |                     1����Ӻ��ѣ�                       |       " << endl;
	cout << "     |                     2���鿴�б�                       |       " << endl;
	cout << "     |                     3��ɾ�����ѣ�                       |       " << endl;
	cout << "     |                     4�����Һ��ѣ�                       |       " << endl;
	cout << "     |                     5���޸���Ϣ��                       |       " << endl;
	cout << "     |                     6���˳�����                       |       " << endl;
	cout << "     |                   ����������������                    |       " << endl;
	cout << "     |                                               |       " << endl;
	cout << "     |           ���ܣ�1.ADD��2.LIST��3.DELETE��4.SEEK��5.REVISE��6.EXIT         |       " << endl;
	cout << "     |           ������������1��2��3��4��5��6ѡ����Ĳ�����                |       " << endl;
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

		cout << "��������ϵ��������";
		__fpurge(stdin);
		cin >> name;
		p[i].setname(name);

		cout << "��������ϵ���Ա�";
		__fpurge(stdin);
		cin >> ismale;
		p[i].setmale(ismale);

		cout << "��������ϵ�˵绰��";
		__fpurge(stdin);
		cin >> tel;
		p[i].settel(tel);

		cout << "��������ϵ��QQ�ţ�";
		__fpurge(stdin);
		cin >> qq;
		p[i].setqq(qq);

		cout << "��������ϵ��סַ��";
		__fpurge(stdin);
		cin >> address;
		p[i].setaddress(address);

		cout << "��������ϵ�˱�ע��";
		__fpurge(stdin);
		cin >> remark;
		p[i].setremark(remark);

		i++;

		cout << "�Ƿ������ӣ�(y/other):";
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

void seek(Contact *p)                                               //������Һ�����ͨ����������
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

		cout << "������������ҵ���ϵ�˵�������";
		cin >> name;

		accum = findnum(name, a, p);                              //����findnum�����������ҵ�������ϵ�˸���accum

		if (accum == 0)
		{
			cout << "����ϵ�˲����ڣ�" << endl;
		}

		else if (accum == 1)                                       //����ҵ�һ����ϵ�ˣ���������ϵ�˵���Ϣ
		{
			temp = a[0];
			p[temp].print(temp);
		}

		else if (accum > 1)                                        //�ҵ���ֹһ����ϵ�ˣ����ȫ����ϵ����Ϣ
		{
			cout << "��" << accum << "����ϵ�ˣ�" << endl;
			for (j = 0; j < accum; j++)
			{
				temp = a[j];
				p[temp].print(temp);
			}
		}
		cout << "�Ƿ��������? (y/other) :";
		__fpurge(stdin);
		cin >> c;

	} while (c == 'y');
}

void coverdata(int j, Contact *p)                                 //���帲����Ϣ����
{
	int m = 0;
	char c = 0;
	string name;
	string ismale;
	string tel;
	string qq;
	string address;
	string remark;

	cout << "�Ƿ�ɾ������ϵ�ˣ�(y/n)";
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
		i--;                                                        //����һ������Ϣ����ǰһ��
		cout << "ɾ���ɹ���" << endl;
	}
}
void mydelete(Contact *p)                                           //����ɾ����ϵ�˺���
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

		cout << "����������ɾ������ϵ�˵�������";
		cin >> name;

		accum = findnum(name, a, p);                               //����findnum�����������ҵ�������ϵ�˸���accum

		if (accum == 0)
		{
			cout << "����ϵ�˲����ڣ�" << endl;
		}

		else if (accum == 1)
		{
			temp = a[0];
			coverdata(temp, p);
		}

		else if (accum > 1)
		{
			cout << "��" << accum << "����ϵ�ˣ�" << endl;                    //����ҵ���ֹһ����ϵ�ˣ������Щ��ϵ����Ϣ���ò�����ѡ��Ҫɾ������ϵ�˱��
			for (j = 0; j < accum; j++)
			{
				temp = a[j];
				p[temp].print(temp);
			}

			cout << "������Ҫɾ���˵ı�ţ�";
			cin >> temp;
			coverdata(temp, p);
		}

		cout << "�Ƿ����ɾ��? (y/other) :";
		__fpurge(stdin);
		cin >> c;

	} while (c == 'y');
}

void modify(int j, Contact *p)                                    //�����޸ĺ���
{
	clear();
	p[j].print(j);

	int temp = 0;
	string ch;

	cout << endl;
	cout << "1��������" << endl;
	cout << "2�����Ա�" << endl;
	cout << "3�����绰" << endl;
	cout << "4����qq��" << endl;
	cout << "5����סַ" << endl;
	cout << "6������ע" << endl;
	cout << "��������Ҫ�޸ĵ��" << endl;
	cin >> temp;
	cout << endl;

	switch (temp)                                                    //��switch���ѡ��Ҫ�޸ĵ���Ϣ
	{
	case 1: {
		cout << "��������Ҫ�ĳɵ�������";
		cin >> ch;
		p[j].setname(ch);
		cout << "�޸ĳɹ���" << endl;
		break;
	}

	case 2: {
		cout << "��������Ҫ�ĳɵ��Ա�";
		cin >> ch;
		p[j].setmale(ch);
		cout << "�޸ĳɹ���" << endl;
		break;
	}

	case 3: {
		cout << "��������Ҫ�ĳɵĵ绰��";
		cin >> ch;
		p[j].settel(ch);
		cout << "�޸ĳɹ���" << endl;
		break;
	}

	case 4: {
		cout << "��������Ҫ�ĳɵ�qq�ţ�";
		cin >> ch;
		p[j].setqq(ch);
		cout << "�޸ĳɹ���" << endl;
		break;
	}

	case 5: {
		cout << "��������Ҫ�ĳɵ�סַ��";
		cin >> ch;
		p[j].setaddress(ch);
		cout << "�޸ĳɹ���" << endl;
		break;
	}

	case 6: {
		cout << "��������Ҫ�ĳɵı�ע��";
		cin >> ch;
		p[j].setremark(ch);
		cout << "�޸ĳɹ���" << endl;
		break;
	}

	default:cout << "�������" << endl;
	}
}
void revise(Contact *p)                                             //�����޸���Ϣ����
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

		cout << "�����������޸ĵ���ϵ�˵�������";
		cin >> name;

		accum = findnum(name, a, p);

		if (accum == 0)
		{
			cout << "����ϵ�˲����ڣ�" << endl;
		}

		else if (accum == 1)
		{
			temp = a[0];
			modify(temp, p);
		}

		else if (accum > 1)
		{
			cout << "��" << accum << "����ϵ�ˣ�" << endl;
			for (j = 0; j < accum; j++)
			{
				temp = a[j];
				p[temp].print(temp);                                //�в�ֹһ����ϵ��ʱ���������ϵ����Ϣ���ò�����ѡ��Ҫ�޸ĵ���ϵ�˱��
			}
			cout << "��������Ҫ�޸ĵ��˵ı�ţ�";
			cin >> temp;
			modify(temp, p);
		}
		cout << "�Ƿ�����޸�? (y/other) :";
		__fpurge(stdin);
		cin >> c;

	} while (c == 'y');
}