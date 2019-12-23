#define _CRT_SECURE_NO_WARNINGS 1

#define MAX_length 640 //����ڴ�ռ�Ϊ640KB

#include<iostream>
using namespace std;
const int MinSize = 5; //������С����Ƭ�ռ�Ϊ5

//����һ�����з�����ṹ
typedef struct Node
{
	int ID;   //������
	long size;   //������С
	long address; //������ַ
	bool state;   //״̬
}Node;

//�������ṹ
typedef struct Link //double linked list
{
	Node data;
	struct Link *prior; //ǰ��ָ��
	struct Link *next;  //���ָ��
}Link;

Link* block_first; //ͷ���
Link* block_follow = block_first;	//����ڵ�
Link* block_last;  //β���

bool Initblock()//������ͷ�����ڴ�ռ�����
{
	block_first = (Link*)malloc(sizeof(Link));
	block_last = (Link*)malloc(sizeof(Link));
	//ͷ�ڵ�����
	block_first->prior = NULL;
	block_first->data.ID = -1;
	block_first->next = block_last;
	//β�ڵ�����(β�ڵ�Ϊ��ǰ�ĵ�һ���ڵ�)
	block_last->prior = block_first;
	block_last->next = NULL;
	block_last->data.address = 0;
	block_last->data.size = MAX_length;
	block_last->data.ID = 0;
	block_last->data.state = false;
	return true;
}

//------------------ �״���Ӧ�㷨 -----------------------
bool First_fit(int ID, int request)//������ҵ����������
{
	//Ϊ������ҵ�����¿ռ��ҳ�ʼ��
	Link* temp = (Link*)malloc(sizeof(Link));
	temp->data.ID = ID;
	temp->data.size = request;
	temp->data.state = true;

	Link* p = block_first->next;
	while (p)
	{
		if (p->data.state == false && p->data.size == request)
		{//�д�Сǡ�ú��ʵĿ��п�
			p->data.state = true;
			p->data.ID = ID;
			return true;
		}
		if (p->data.state == false && p->data.size > request)
		{//�п��п���������������ʣ��"
			temp->prior = p->prior;
			temp->next = p;
			temp->data.address = p->data.address;
			p->prior->next = temp;
			p->prior = temp;
			p->data.address = temp->data.address + temp->data.size;
			p->data.size -= request;
			return true;
		}
		p = p->next;
	}
	return false;
}

//--------------------  �����Ӧ�㷨  ------------------------
bool Best_fit(int ID, int request)
{
	int ch; //��¼��Сʣ��ռ�
	Link* temp = (Link*)malloc(sizeof(Link));
	temp->data.ID = ID;
	temp->data.size = request;
	temp->data.state = true;
	Link *p = block_first->next;
	Link *q = NULL; //��¼��Ѳ���λ��
	while (p) //��ʼ����С�ռ�����λ��
	{
		if (p->data.state == false && (p->data.size > request || p->data.size == request))
		{
			q = p;
			ch = p->data.size - request;
			break;
		}
		p = p->next;
	}
	//��ͷ����һ�α���
	p = block_first->next;
	while (p)
	{
		if (p->data.state == false && p->data.size == request)
		{//���п��Сǡ�ú���
			p->data.ID = ID;
			p->data.state = true;
			return true;
		}
		if (p->data.state == false && p->data.size > request)
		{//���п���ڷ�������
			if (p->data.size - request < ch)//ʣ��ռ�ȳ�ֵ��С
			{
				ch = p->data.size - request;//����ʣ����Сֵ
				q = p;//�������λ��ָ��
			}
		}
		p = p->next;
	}
	if (q == NULL)
		return false;//û���ҵ����п�
	else
	{
		//�ҵ������λ�ò�ʵ�ַ���
		temp->prior = q->prior;
		temp->next = q;
		temp->data.address = q->data.address;
		q->prior->next = temp;
		q->prior = temp;
		q->data.address += request;
		q->data.size = ch;
		return true;
	}
}

//--------------------���Ӧ�㷨 -------------------------
bool Worse_fit(int ID, int request)
{
	int ch; //��¼���ʣ��ռ�
	Link* temp = (Link*)malloc(sizeof(Link));
	temp->data.ID = ID;
	temp->data.size = request;
	temp->data.state = true;
	Link *p = block_first->next;
	Link *q = NULL; //��¼��Ѳ���λ��
	while (p) //��ʼ�����ռ�����λ��
	{
		if (p->data.state == false && (p->data.size > request || p->data.size == request))
		{
			q = p;
			ch = p->data.size - request;
			break;
		}
		p = p->next;
	}
	//��ͷ����һ�α���
	p = block_first->next;
	while (p)
	{
		if (p->data.state == false && p->data.size > request)
		{//���п���ڷ�������
			if (p->data.size - request > ch)//ʣ��ռ�ȳ�ֵ��С
			{
				ch = p->data.size - request;//����ʣ�����ֵ
				q = p;//�������λ��ָ��
			}
		}
		p = p->next;
	}
	if (q == NULL)
		return false;//û���ҵ����п�
	else
	{
		//�ҵ������λ�ò�ʵ�ַ���
		temp->prior = q->prior;
		temp->next = q;
		temp->data.address = q->data.address;
		q->prior->next = temp;
		q->prior = temp;
		q->data.address += request;
		q->data.size = ch;
		return true;
	}
}

//------------------ ѭ���״���Ӧ�㷨 -----------------------
bool Re_First_fit(int ID, int request)
{
	//Ϊ������ҵ�����¿ռ��ҳ�ʼ��
	Link* temp = (Link*)malloc(sizeof(Link));
	temp->data.ID = ID;
	temp->data.size = request;
	temp->data.state = true;

	Link* p = block_follow;
	while (p)
	{
		if (p->data.state == false && p->data.size == request)
		{//�д�Сǡ�ú��ʵĿ��п�
			p->data.state = true;
			p->data.ID = ID;
			block_follow = p->next;
			return true;
		}
		if (p->data.state == false && p->data.size > request)
		{//�п��п���������������ʣ��"
			temp->prior = p->prior;
			temp->next = p;
			temp->data.address = p->data.address;
			p->prior->next = temp;
			p->prior = temp;
			p->data.address = temp->data.address + temp->data.size;
			p->data.size -= request;
			block_follow = p->next;
			return true;
		}
		p = p->next;
		if (p == NULL)
		{
			p = block_first->next;
		}
		if (block_follow == p)
			return false;
	}
	return false;
}


//-----------------------   �� �� �� ��   --------------------
bool free(int ID)
{
	Link *p = block_first;
	while (p)
	{
		if (p->data.ID == ID)
		{
			p->data.state = false;
			p->data.ID = false;
			Link *_head = p->prior;
			Link *_next = p->next;
			if (_head != block_first && _next != NULL)
			{
				if (p->prior->data.state == false && p->next->data.state == false)//ǰ���ǿյ�
				{
					_head->next = _next->next;
					_next->prior = p->prior;
					_head->data.size += p->data.size + _next->data.size;
					free(p);
				}
				else if (p->prior->data.state == false)//��ǰ��Ŀ��п�����
				{
					_head->data.size += p->data.size;
					_head->next = _next;
					_next->prior = p->prior;
					free(p);
				}
				else if (p->next->data.state == false)//�����Ŀ��п�����
				{
					p->data.size += _next->data.size;
					_next->prior = p;
					p->next = _next->next;
					free(_next);
				}
				return true;
			}
			else if (_head == block_first && _next != NULL)
			{
				if (p->next->data.state == false)//�����Ŀ��п�����
				{
					p->data.size += _next->data.size;
					_next->next->prior = p;
					p->next = _next->next;
					free(_next);
				}
				return true;
			}
			else if (_head != block_first && _next == NULL)
			{
				if (p->prior->data.state == false)//��ǰ��Ŀ��п�����
				{
					_head->data.size += p->data.size;
					_head->next = _next;
					_next->prior = p->prior;
					free(p);
				}
				return true;
			}
			else
			{
				p->data.state = false;
				return true;
			}
		}
		p = p->next;
	}
	return false;
}

//----------------------- �� �� �� �� -------------------------
bool alloc()
{
	block_follow = block_first;
	int ch;//�㷨ѡ����
	cout << "       �ڴ涯̬�������������       \n";
	cout << "************************************\n";
	cout << "** 1)�״���Ӧ�㷨 \n";
	cout << "** 2)�����Ӧ�㷨 \n";
	cout << "** 3)���Ӧ�㷨 \n";
	cout << "** 4)ѭ���״���Ӧ��Ӧ�㷨\n";
	cout << "************************************\n";
	cout << "��ѡ������㷨��";
	cin >> ch;

	int ID, request;
	cout << "��������ҵ(������)��";
	cin >> ID;
	cout << "��������Ҫ����������С(��λ:KB)��";
	cin >> request;

	if (request < 0 || request == 0)
	{
		cout << "�����С�����ʣ������ԣ�" << endl;
		return false;
	}
	switch (ch)
	{
	case 2:
		if (Best_fit(ID, request) == true)
			cout << "����ɹ���" << endl;
		else
			cout << "�ڴ治�㣬����ʧ�ܣ�" << endl;
		break;
	case 1:
		if (First_fit(ID, request) == true)
			cout << "����ɹ���" << endl;
		else
			cout << "�ڴ治�㣬����ʧ�ܣ�" << endl;
		break;
	case 3:
		if (Worse_fit(ID, request) == true)
			cout << "����ɹ���" << endl;
		else
			cout << "�ڴ治�㣬����ʧ�ܣ�" << endl;
		break;
	case 4:
		if (Re_First_fit(ID, request) == true)
			cout << "����ɹ���" << endl;
		else
			cout << "�ڴ治�㣬����ʧ�ܣ�" << endl;
		break;
	default:
		break;
	}
}


//---------------  ��ʾ���������� ------------------
void show()
{
	cout << "+++++++++++++++++++++++++++++++++++++++\n";
	cout << "+++        �� �� �� �� �� ��        +++\n";
	cout << "+++++++++++++++++++++++++++++++++++++++\n";
	Link *p = block_first->next;
	while (p)
	{
		cout << "�� �� �ţ�";
		if (p->data.ID == false)
			cout << "Free" << endl;
		else
			cout << p->data.ID << endl;
		cout << "��ʼ��ַ��" << p->data.address << endl;
		cout << "������С��" << p->data.size << " KB" << endl;
		cout << "״    ̬��";
		if (p->data.state == false)
			cout << "��  ��" << endl;
		else
			cout << "�ѷ���" << endl;
		cout << "����������������������������" << endl;
		p = p->next;
	}
}

int main()
{
	Initblock(); //�����ռ��
	int choice;  //����ѡ����
	cout << "********************************************\n";
	cout << "**    1: �����ڴ�        2: �����ڴ�      **\n";
	cout << "**    3: �鿴����        0: ��    ��      **\n";
	cout << "********************************************\n";
	do {
		cout << "���������Ĳ��� ��";
		cin >> choice;
		switch (choice) {
		case 0:
			break;
		case 1:
			// �����ڴ�
			alloc();
			break;
		case 2:
			int ID;
			cout << "��������Ҫ�ͷŵķ����ţ�";
			cin >> ID;
			free(ID);
			break;
		case 3:
			show();
			break;
		default:
			cout << "����������������룡" << endl;
			break;
		}
	} while (choice != 0);
}
