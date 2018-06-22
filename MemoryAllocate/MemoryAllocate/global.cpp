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

	init_func[1] = init_ff;
}