#include "global.h"

int main()
{
	int number, size, res;
	init(allocate_function,init_function);	//初始化

	//获取总内存值
	total_mem=get_total_memory();
	system("cls");
	print_head(total_mem, 0);

	//获取分配方法
	command = get_command();
	system("cls");

	//初始化链表
	init_function[command](total_mem, command);

	while (1)
	{
		//输出标准头部，获取操作以及操作参数
		print_head(total_mem, command);
		allocate_function[command](0, 0);
		get_action(&number, &size);
		
		//退出操作
		if (number == -1 && size == -1)
			break;

		//进行处理，输出结果
		system("cls");
		print_head(total_mem, command);
		res = allocate_function[command](number, size);
		allocate_function[command](0, 0);
		print_result(res);
		system("cls");
	}
}