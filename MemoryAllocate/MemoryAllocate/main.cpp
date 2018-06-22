#include "global.h"

int main()
{
	init(allocat_function,init_function);	//初始化

	//获取总内存值
	total_mem=get_total_memory();
	system("cls");
	print_head(total_mem, 0);

	//获取分配方法
	command = get_command();
	system("cls");
	print_head(total_mem, command);

	//初始化链表
	init_function[command](total_mem);
	
}