#define _CRT_SECURE_NO_WARNINGS 1
#include"workmanager.h"

//չ�ֲ˵�
void WorkManager::Show_Menu()
{
	cout << "��ӭʹ��ְ������ϵͳ" << endl;
	cout << "8���˳��������" << endl;
	cout << "1������ְ����Ϣ" << endl;
	cout << "2����ʾְ����Ϣ" << endl;
	cout << "3��ɾ����ְְ����Ϣ" << endl;
	cout << "4���޸�ְ����Ϣ" << endl;
	cout << "5������ְ����Ϣ" << endl;
	cout << "6�����ձ������" << endl;
	cout << "7����������ĵ�" << endl;
	cout << endl;

}

//�˳�ϵͳ
void WorkManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}


WorkManager::WorkManager()
{

	//���������ʼ��
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڣ�����¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmNum = num;

	this->m_EmpArray = new worker*[this->m_EmNum];
	//���ļ��е����ݣ��浽����
	this->init_Emp();

	for (int i = 0; i < this->m_EmNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_id
			<< "������" << this->m_EmpArray[i]->m_name
			<< "���ű�ţ�" << this->m_EmpArray[i]->m_number
			<< endl;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�����ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ����¼����
		this->m_EmNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}


	//�ļ���������
	//��ʼ������
	//this->m_EmNum = 0;
	//this->m_EmpArray = NULL;
}

//���ְ��
void WorkManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;

	int addNum = 0;//�����û���������
	cin >> addNum;
	if (addNum)
	{
		//���
		//��������ռ��С
		int newSize = this->m_EmNum + addNum;//�¿ռ��С=ԭ����¼����+��������
	//�����¿ռ�
		worker**newSpace = new worker*[newSize];
		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ�����֣�" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "����ְ����λ��" << endl;
			cin >> dSelect;

			worker*work = NULL;
			switch (dSelect)
			{
			case 1:
				work = new Employee(id, name, 1);
				break;
			case 2:
				work = new Manager(id, name, 2);
				break;
			case 3:
				work = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmNum + i] = work;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//������ְ������
		this->m_EmNum = newSize;
		//����ְ����Ϊ��
		this->m_FileIsEmpty = false;
		//��ʾ��ӳɹ�
		cout << "��ӳɹ�" << addNum << "����ְ��" << endl;

		this->save();

	}
	else
	{
		cout << "��������" << endl;

	}
	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�����ļ�
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//�������ʽ���ļ�--д�ļ�

	//��ÿ���˵�����д�뵽�ļ���//ָ���ָ���Ƿ���Զ��ָ��
	for (int i = 0; i < this->m_EmNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_number << " " << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ�������
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//ͳ������
		num++;
	}
	return num;
}


//��ʼ��Ա��
void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int indiex = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker*work = NULL;

		if (dId == 1)//Ա��
		{
			work = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			work = new Manager(id, name, dId);
		}
		else
		{
			work = new Boss(id, name, dId);
		}
		this->m_EmpArray[indiex] = work;
		indiex++;
	}
	//�ر��ļ�
	ifs.close();
}

//��ʾְ��
void WorkManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}

	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}


//ɾ��ְ��
void WorkManager::WorkManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ��ְ����ţ�" << endl;
		int D_id = 0;
		cin >> D_id;

		int index = this->IsExist(D_id);
		if (index != -1)
		{
			cout << "ְ������" << endl;//�ҵ�ְ����Ҫɾ��
			//����ǰ��
			for (int i = index; i < this->m_EmNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];//���һ��λ���ڴ�й©
			}
			this->m_EmNum--;//���������м�¼��Ա����
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ְ��������" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�ã������ڷ���-1
int WorkManager::IsExist(int id)
{
	int index = -1;



	for (int i = 0; i < this->m_EmNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			//�ҵ�ְ��
			index = i;
			break;
		}
	}

	return index;
}


//�޸�ְ��
void WorkManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			cout << "ְ������" << endl;
			delete this->m_EmpArray[ret];

			int newid = 0;
			string newname = "";
			int dselect = 0;


			cout << "�鵽:" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newid;

			cout << "�������µ�������" << endl;
			cin >> newname;

			cout << "�������µ�ְλ��" << endl;
			cin >> dselect;

			worker*work = NULL;
			switch (dselect)
			{
			case 1:
				work = new Employee(newid, newname, dselect);
				break;
			case 2:
				work = new Manager(newid, newname, dselect);
				break;
			case 3:
				work = new Boss(newid, newname, dselect);
				break;
			default:
				break;
			}

			//��������
			this->m_EmpArray[ret] = work;

			cout << "�޸ĳɹ�" << endl;

			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ�ְ��������" << endl;
		}

	}

	system("psuse");
	system("cls");

}

//����ְ��
void WorkManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "id��Ż�������" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//����ID��Ų�
			int id;
			cout << "��������ҵ�ְ�����" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "ְ�����ڣ���ְ����Ϣ����" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			//����������
			string name;
			cout << "��������ҵ�ְ������" << endl;
			cin >> name;

			//�����ж��Ƿ�鵽�ı�־
			bool flag = false;//Ĭ��δ�ҵ�ְ��

			for (int i = 0; i < this->m_EmNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_name)
				{
					cout << "ְ�����ڣ���ְ����Ϣ����" << endl;
					this->m_EmpArray[i]->showInfo();

					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ�δ�ҵ�ְ��" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}


//���ձ������
void WorkManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "���չ��Ž���������߽���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmNum; i++)
		{
			int minOrMax = i;//������Сֵ�������ֵ�±�
			for (int j = i + 1; j < this->m_EmNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else//����
				{
					if (this->m_EmpArray[minOrMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}

				}
				//�ж�һ��ʼ�϶���Сֵ�������ֵ�ǲ��Ǽ������Сֵ�������ֵ��������Ǿͽ�������
				if (i != minOrMax)
				{
					worker *temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
					this->m_EmpArray[minOrMax] = temp;
				}
			}
		}
		//����ɹ�
		cout << "����ɹ��������Ľ����" << endl;
		this->save();//����������浽�ļ���
		this->Show_Emp();
	}

}

//����ļ�
void WorkManager::Clean_File()
{
	cout << "ȷ�����" << endl;
	cout << "1,��ȷ��2��������һ��Ԫ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)//ȷ�����
	{
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_FileIsEmpty != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");

}

WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}


//Ա����
	//���캯��
Employee::Employee(int id, string name, int number)
{
	this->m_id = id;
	//ְ������
	this->m_name = name;
	//���ű��
	this->m_number = number;
}

//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t���ţ�" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;
}

//��ȡ��λ
string Employee::getDeptName()
{
	return string("Ա��");
}


//������
   //���캯��
Manager::Manager(int id, string name, int number)
{
	this->m_id = id;
	//ְ������
	this->m_name = name;
	//���ű��
	this->m_number = number;
}

//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t���ţ�" << this->getDeptName()
		<< "\t��λְ������ϰ彻��������" << endl;
}

//��ȡ��λ
string Manager::getDeptName()
{
	return string("����");
}


//�ϰ���
  //���캯��
Boss::Boss(int id, string name, int number)
{
	this->m_id = id;
	//ְ������
	this->m_name = name;
	//���ű��
	this->m_number = number;
}

//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t���ţ�" << this->getDeptName()
		<< "\t��λְ�𣺲�������" << endl;
}

//��ȡ��λ
string Boss::getDeptName()
{
	return string("�ϰ�");
}
