#include "global.h"

int main()
{
	init(allocat_function,init_function);	//��ʼ��

	//��ȡ���ڴ�ֵ
	total_mem=get_total_memory();
	system("cls");
	print_head(total_mem, 0);

	//��ȡ���䷽��
	command = get_command();
	system("cls");
	print_head(total_mem, command);

	//��ʼ������
	init_function[command](total_mem);
	
}