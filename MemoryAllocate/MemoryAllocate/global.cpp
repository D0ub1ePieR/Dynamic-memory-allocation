#include "global.h"

//��ȡ�ڴ��ܴ�С
int get_total_memory()
{
	string tmp;
	int i, flag = 0;
	while (1)
	{
		//system("cls");
		flag = 0;
		cout << "---------------------------------------------------------------------" << endl;
		cout << "                     ���������ڴ��С:";
		cin >> tmp;
		//У������ֵ�Ƿ�Ϸ�
		for (i = 0; i < tmp.length(); i++)
			if (!isdigit(tmp[i]))
				flag = 1;
		if (!flag)
			break;
		else
		{
			cout << "                     ��������ȷ����ֵ!" << endl;
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
		//���÷��䷽������
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

//��ȡ���䷽��
int get_command()
{
	string tmp;
	while (1)
	{
		cout << "     ---------------------------------------------------------------------" << endl;
		cout << "     |                     ��ѡ��̬�ڴ���䷽��                        |" << endl;
		cout << "     |                     1.�״���Ӧ�㷨                                |" << endl;
		cout << "     |                     2.ѭ���״���Ӧ�㷨                            |" << endl;
		cout << "     |                     3.�����Ӧ�㷨                                |" << endl;
		cout << "     |                     4.���Ӧ�㷨                                |" << endl;
		cout << "     ---------------------------------------------------------------------" << endl;
		cout << "     ���������ѡ��:";
		cin >> tmp;
		//У������Ϸ���
		if (tmp.length() == 1 && tmp[0] <= '4' && tmp[0] >= '1')
			break;
		else
			cout << ">>>>>��������ȷ��ѡ��!" << endl;
	}
	return atoi(tmp.c_str());
}

//��ʼ����������
void init(int(*alloc[])(int, int), void(*init_func[])(int,int))
{
	alloc[1] = first_fit;

	init_func[1] = init_ff;
}