#pragma once
#include "include.h"

static int total_mem, command;

static int(*allocate_function[5])(int number, int size);	//���䷽��������
static void(*init_function[5])(int total, int command);		//��ʼ����������

//��ȡ���ڴ��С
int get_total_memory();
//��׼��������涥��
void print_head(int total, int method);
//��ȡ���䷽ʽ
int get_command();
//��ʼ������������
void init(int(*alloc[])(int, int), void(*init_func[])(int,int));
//��ȡִ�еĲ���
void get_action(int *number, int *size);
//���������
void print_result(int res);
