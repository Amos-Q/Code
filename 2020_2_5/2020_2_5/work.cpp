#define _CRT_SECURE_NO_WARNINGS 1
#include"workmanager.h"

//展现菜单
void WorkManager::Show_Menu()
{
	cout << "欢迎使用职工管理系统" << endl;
	cout << "8、退出管理程序" << endl;
	cout << "1、增加职工信息" << endl;
	cout << "2、显示职工信息" << endl;
	cout << "3、删除离职职工信息" << endl;
	cout << "4、修改职工信息" << endl;
	cout << "5、查找职工信息" << endl;
	cout << "6、按照编号排序" << endl;
	cout << "7、清空所有文档" << endl;
	cout << endl;

}

//退出系统
void WorkManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}


WorkManager::WorkManager()
{

	//三种情况初始化
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，并记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmNum = num;

	this->m_EmpArray = new worker*[this->m_EmNum];
	//将文件中的数据，存到数组
	this->init_Emp();

	for (int i = 0; i < this->m_EmNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_id
			<< "姓名：" << this->m_EmpArray[i]->m_name
			<< "部门编号：" << this->m_EmpArray[i]->m_number
			<< endl;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//代表文件为空
		cout << "文件为空" << endl;
		//初始化记录人数
		this->m_EmNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}


	//文件中有数据
	//初始化属性
	//this->m_EmNum = 0;
	//this->m_EmpArray = NULL;
}

//添加职工
void WorkManager::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;

	int addNum = 0;//保存用户输入数量
	cin >> addNum;
	if (addNum)
	{
		//添加
		//计算新添空间大小
		int newSize = this->m_EmNum + addNum;//新空间大小=原来记录人数+新增人数
	//开辟新空间
		worker**newSpace = new worker*[newSize];
		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工名字：" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工岗位：" << endl;
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
			//将创建职工职责，保存到数组中
			newSpace[this->m_EmNum + i] = work;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更改新职工人数
		this->m_EmNum = newSize;
		//更新职工不为空
		this->m_FileIsEmpty = false;
		//提示添加成功
		cout << "添加成功" << addNum << "名新职工" << endl;

		this->save();

	}
	else
	{
		cout << "输入有误" << endl;

	}
	//按任意键，清屏回到上级目录
	system("pause");
	system("cls");
}

//保存文件
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出方式打开文件--写文件

	//将每个人的数据写入到文件中//指针的指针是否可以多次指向
	for (int i = 0; i < this->m_EmNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_number << " " << endl;
	}
	//关闭文件
	ofs.close();
}

//统计文件中人数
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
		//统计人数
		num++;
	}
	return num;
}


//初始化员工
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

		if (dId == 1)//员工
		{
			work = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
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
	//关闭文件
	ifs.close();
}

//显示职工
void WorkManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	//按任意键，清屏回到上级目录
	system("pause");
	system("cls");
}


//删除职工
void WorkManager::WorkManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除职工编号：" << endl;
		int D_id = 0;
		cin >> D_id;

		int index = this->IsExist(D_id);
		if (index != -1)
		{
			cout << "职工存在" << endl;//找到职工需要删除
			//数据前移
			for (int i = index; i < this->m_EmNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];//最后一个位置内存泄漏
			}
			this->m_EmNum--;//更新数组中记录人员个数
			//数据同步更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "职工不存在" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//判断职工是否存在 如果存在返回职工所在数组中的位置，不存在返回-1
int WorkManager::IsExist(int id)
{
	int index = -1;



	for (int i = 0; i < this->m_EmNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			//找到职工
			index = i;
			break;
		}
	}

	return index;
}


//修改职工
void WorkManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			cout << "职工存在" << endl;
			delete this->m_EmpArray[ret];

			int newid = 0;
			string newname = "";
			int dselect = 0;


			cout << "查到:" << id << "号职工，请输入新职工号：" << endl;
			cin >> newid;

			cout << "请输入新的姓名：" << endl;
			cin >> newname;

			cout << "请输入新的职位：" << endl;
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

			//更新数据
			this->m_EmpArray[ret] = work;

			cout << "修改成功" << endl;

			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，职工不存在" << endl;
		}

	}

	system("psuse");
	system("cls");

}

//查找职工
void WorkManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "id编号或者姓名" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照ID编号查
			int id;
			cout << "请输入查找的职工编号" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "职工存在，该职工信息如下" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名查
			string name;
			cout << "请输入查找的职工姓名" << endl;
			cin >> name;

			//加入判断是否查到的标志
			bool flag = false;//默认未找到职工

			for (int i = 0; i < this->m_EmNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_name)
				{
					cout << "职工存在，该职工信息如下" << endl;
					this->m_EmpArray[i]->showInfo();

					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，未找到职工" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	//按任意键清零
	system("pause");
	system("cls");
}


//按照编号排序
void WorkManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "按照工号进行升序或者降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmNum; i++)
		{
			int minOrMax = i;//声明最小值或者最大值下标
			for (int j = i + 1; j < this->m_EmNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minOrMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}

				}
				//判断一开始认定最小值或者最大值是不是计算的最小值或者最大值，如果不是就交换数据
				if (i != minOrMax)
				{
					worker *temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
					this->m_EmpArray[minOrMax] = temp;
				}
			}
		}
		//排序成功
		cout << "排序成功，排序后的结果：" << endl;
		this->save();//排序后结果保存到文件中
		this->Show_Emp();
	}

}

//清除文件
void WorkManager::Clean_File()
{
	cout << "确定清空" << endl;
	cout << "1,、确定2、返回上一单元" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)//确定清空
	{
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_FileIsEmpty != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
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


//员工类
	//构造函数
Employee::Employee(int id, string name, int number)
{
	this->m_id = id;
	//职工姓名
	this->m_name = name;
	//部门编号
	this->m_number = number;
}

//显示个人信息
void Employee::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t部门：" << this->getDeptName()
		<< "\t岗位职责：完成经理交待的任务" << endl;
}

//获取岗位
string Employee::getDeptName()
{
	return string("员工");
}


//经理类
   //构造函数
Manager::Manager(int id, string name, int number)
{
	this->m_id = id;
	//职工姓名
	this->m_name = name;
	//部门编号
	this->m_number = number;
}

//显示个人信息
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t部门：" << this->getDeptName()
		<< "\t岗位职责：完成老板交待的任务" << endl;
}

//获取岗位
string Manager::getDeptName()
{
	return string("经理");
}


//老板类
  //构造函数
Boss::Boss(int id, string name, int number)
{
	this->m_id = id;
	//职工姓名
	this->m_name = name;
	//部门编号
	this->m_number = number;
}

//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t部门：" << this->getDeptName()
		<< "\t岗位职责：布置任务" << endl;
}

//获取岗位
string Boss::getDeptName()
{
	return string("老板");
}
