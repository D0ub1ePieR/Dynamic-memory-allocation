#include "global.h"

int main()
{
	int number, size, res;
	init(allocate_function,init_function);	//��ʼ��

	//��ȡ���ڴ�ֵ
	total_mem=get_total_memory();
	system("cls");
	print_head(total_mem, 0);

	//��ȡ���䷽��
	command = get_command();
	system("cls");

	//��ʼ������
	init_function[command](total_mem, command);

	while (1)
	{
		//�����׼ͷ������ȡ�����Լ���������
		print_head(total_mem, command);
		allocate_function[command](0, 0);
		get_action(&number, &size);
		
		//�˳�����
		if (number == -1 && size == -1)
			break;

		//���д���������
		system("cls");
		print_head(total_mem, command);
		res = allocate_function[command](number, size);
		allocate_function[command](0, 0);
		print_result(res);
		system("cls");
	}
}