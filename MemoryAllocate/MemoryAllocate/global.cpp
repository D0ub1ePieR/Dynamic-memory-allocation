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
		cout << "     |                     ��ѡ����Ҫִ�еĲ���                          |" << endl;
		cout << "     |                     1.ռ���ڴ�                                    |" << endl;
		cout << "     |                     2.�ͷ��ڴ�                                    |" << endl;
		cout << "     |                     3.�˳�����                                    |" << endl;
		cout << "     ---------------------------------------------------------------------" << endl;
		cout << "     ���������ѡ��:";
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
						cout << "     ��������ӵĳ���Ľ��̺��Լ�ռ�ô�С:";
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
							cout << ">>>>>��������ȷ������!" << endl;
					}
					break;
				case '2':
					while (1)
					{
						flag1 = 0;
						cout << "     ������ɾ���ĳ���Ľ��̺�:";
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
							cout << ">>>>>��������ȷ������!" << endl;
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
			cout << ">>>>>��������ȷ��ѡ��!" << endl;
	}
}

//������
void print_result(int res)
{
	switch (res)
	{
	case -1:
		cout << "                               ���̺�����!" << endl;
		system("pause");
		break;
	case -2:
		cout << "                               ����ʧ��!" << endl;
		system("pause");
		break;
	case 1:
		cout << "                               �����ɹ�!" << endl;
		system("pause");
		break;
	}
}