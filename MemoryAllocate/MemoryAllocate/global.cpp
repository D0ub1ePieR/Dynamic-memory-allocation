#include "global.h"

//获取内存总大小
int get_total_memory()
{
	string tmp;
	int i, flag = 0;
	while (1)
	{
		//system("cls");
		flag = 0;
		cout << "---------------------------------------------------------------------" << endl;
		cout << "                     请输入总内存大小:";
		cin >> tmp;
		//校验输入值是否合法
		for (i = 0; i < tmp.length(); i++)
			if (!isdigit(tmp[i]))
				flag = 1;
		if (!flag)
			break;
		else
		{
			cout << "                     请输入正确的数值!" << endl;
			cout << "---------------------------------------------------------------------" << endl;
		}
	}
	return atoi(tmp.c_str());
}

void print_head(int total, int method)
{
	string str;
	switch (method)
	{
		//设置分配方法名称
		case 1:str = "FF"; break;
		case 2:str = "NF"; break;
		case 3:str = "BF"; break;
		case 4:str = "WF"; break;
	};
	printf("                          *************************\n");
	printf("                          *  total memory:%5dM  *\n", total);
	if (method)
		cout << "                          *  allocate method:" << str << "   *" << endl;
	printf("                          *************************\n");
}

//获取分配方法
int get_command()
{
	string tmp;
	while (1)
	{
		cout << "     ---------------------------------------------------------------------" << endl;
		cout << "     |                     请选择动态内存分配方法                        |" << endl;
		cout << "     |                     1.首次适应算法                                |" << endl;
		cout << "     |                     2.循环首次适应算法                            |" << endl;
		cout << "     |                     3.最佳适应算法                                |" << endl;
		cout << "     |                     4.最坏适应算法                                |" << endl;
		cout << "     ---------------------------------------------------------------------" << endl;
		cout << "     请输入你的选择:";
		cin >> tmp;
		//校验输入合法性
		if (tmp.length() == 1 && tmp[0] <= '4' && tmp[0] >= '1')
			break;
		else
			cout << ">>>>>请输入正确的选择!" << endl;
	}
	return atoi(tmp.c_str());
}

//初始化函数数组
void init(int(*alloc[])(int, int), void(*init_func[])(int,int))
{
	alloc[1] = first_fit;
	alloc[2] = next_fit;

	init_func[1] = init_ff;
	init_func[2] = init_nf;
}

//
void get_action(int *number,int *size)
{
	string tmp;
	string t1, t2;
	int flag1, flag2, i;
	while (1)
	{
		cout << "     ---------------------------------------------------------------------" << endl;
		cout << "     |                     请选择你要执行的操作                          |" << endl;
		cout << "     |                     1.占用内存                                    |" << endl;
		cout << "     |                     2.释放内存                                    |" << endl;
		cout << "     |                     3.退出程序                                    |" << endl;
		cout << "     ---------------------------------------------------------------------" << endl;
		cout << "     请输入你的选择:";
		cin >> tmp;
		if (tmp.length() == 1 && tmp[0] <= '3' && tmp[0] >= '1')
		{
			switch (tmp[0])
			{
				case '1':
					while (1)
					{
						flag1 = 0;
						flag2 = 0;
						cout << "     请输入添加的程序的进程号以及占用大小:";
						cin >> t1 >> t2;
						for (i = 0; i < t1.length(); i++)
							if (!isdigit(t1[i]))
								flag1 = 1;
						for (i = 0; i < t2.length(); i++)
							if (!isdigit(t2[i]))
								flag2 = 1;
						if (!flag1 && !flag2)
						{
							*number = atoi(t1.c_str());
							*size = atoi(t2.c_str());
							break;
						}
						else
							cout << ">>>>>请输入正确的数据!" << endl;
					}
					break;
				case '2':
					while (1)
					{
						flag1 = 0;
						cout << "     请输入删除的程序的进程号:";
						cin >> t1;
						for (i = 0; i < t1.length(); i++)
							if (!isdigit(t1[i]))
								flag1 = 1;
						if (!flag1)
						{
							*number = atoi(t1.c_str());
							*size = -1;
							break;
						}
						else
							cout << ">>>>>请输入正确的数据!" << endl;
					}
					break;
				case '3':
					*number = -1;
					*size = -1;
					break;
			}
			break;
		}
		else
			cout << ">>>>>请输入正确的选择!" << endl;
	}
}

//输出结果
void print_result(int res)
{
	switch (res)
	{
	case -1:
		cout << "                               进程号有误!" << endl;
		system("pause");
		break;
	case -2:
		cout << "                               分配失败!" << endl;
		system("pause");
		break;
	case 1:
		cout << "                               操作成功!" << endl;
		system("pause");
		break;
	}
}