#pragma once
#include "include.h"

static int total_mem, command;

static int(*allocat_function[5])(int number, int size);	//分配方法处理函数
static void(*init_function[5])(int total, int command);		//初始化分配链表

//获取总内存大小
int get_total_memory();
//标准化输出界面顶部
void print_head(int total, int method);
//获取分配方式
int get_command();
//初始化各函数数组
void init(int(*alloc[])(int, int), void(*init_func[])(int,int));
