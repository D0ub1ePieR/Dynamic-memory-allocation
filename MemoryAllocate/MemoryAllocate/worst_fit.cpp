#include "worst_fit.h"

struct list
{
	int used;
	int number;
	int start;
	int end;
	int size;
	struct list *pre;
	struct list *next;
};

struct list *head_wf;

//输出当前内存情况
void print_memory_wf()
{
	int i;
	list *p = head_wf;
	cout << endl << "                               当前内存情况" << endl << "                               ";
	while (p != NULL)
	{
		for (i = p->start; i <= p->end; i++)
			if (p->used)
				cout << "*";
			else
				cout << "+";
		p = p->next;
	}
	cout << endl << endl;
	p = head_wf;
	while (p != NULL)
	{
		cout << "     块" << p->start << "-" << p->end << ",大小:" << p->size << ",状态:";
		if (p->used)
			cout << "占用,进程号:" << p->number << endl;
		else
			cout << "空闲" << endl;
		p = p->next;
	}
	cout << endl;
}

//校验程序号是否已经存在
int check_exsit_wf(int number)
{
	list *p = head_wf;
	while (p != NULL)
	{
		if (p->used && p->number == number)
			return 1;
		p = p->next;
	}
	return 0;
}

//初始化
void init_wf(int total, int command)
{
	head_wf = (struct list*)malloc(sizeof(struct list));
	head_wf->used = 0;
	head_wf->start = 0;
	head_wf->end = total - 1;
	head_wf->size = head_wf->end - head_wf->start + 1;
	head_wf->pre = NULL;
	head_wf->next = NULL;
}

//分配
int allocate_wf(int number, int size)
{
	struct list *p = head_wf, *alloc = NULL;
	while (p != NULL)
	{
		if (!p->used && p->size >= size)
			if (alloc == NULL)
				alloc = p;
			else
				if (p->size - size > alloc->size - size)
					alloc = p;
		p = p->next;
	}
	if (alloc == NULL)
		return 0;
	if (alloc->size == size)
	{
		alloc->used = 1;
		alloc->number = number;
	}
	else
	{
		struct list *tmp;
		tmp = (struct list *)malloc(sizeof(struct list));
		tmp->start = alloc->start;
		tmp->end = alloc->start + size - 1;
		tmp->size = size;
		tmp->number = number;
		tmp->used = 1;
		tmp->pre = alloc->pre;
		tmp->next = alloc;
		if (alloc->pre != NULL)
			alloc->pre->next = tmp;
		alloc->pre = tmp;
		alloc->start = tmp->end + 1;
		alloc->size = alloc->end - alloc->start + 1;
		if (alloc == head_wf)
			head_wf = tmp;
	}
}

//释放
void release_wf(int number)
{
	struct list *p = head_wf;
	while (p != NULL)
	{
		if (p->number == number)
			break;
		p = p->next;
	}
	p->used = 0;
	if (p->pre && !p->pre->used)
	{
		p->pre->size += p->size;
		p->pre->end = p->end;
		p->pre->next = p->next;
		if (p->next != NULL)
			p->next->pre = p->pre;
		p = p->pre;
	}
	if (p->next && !p->next->used)
	{
		p->next->size += p->size;
		p->next->start = p->start;
		p->next->pre = p->pre;
		if (p->pre != NULL)
			p->pre->next = p->next;
	}
	return;
}

int worst_fit(int number, int size)
{
	if (!size)
		print_memory_wf();
	if (size > 0)
		//占用内存
		if (check_exsit_wf(number))
			return -1;
		else
			if (allocate_wf(number, size))
				return 1;
			else
				return -2;
	else
		//释放内存
		if (!check_exsit_wf(number))
			return -1;
		else
		{
			release_wf(number);
			return 1;
		}
	return 0;
}