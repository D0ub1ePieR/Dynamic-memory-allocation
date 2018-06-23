#include "next_fit.h"

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

struct list *head_nf, *cur;

//输出当前内存情况
void print_memory_nf()
{
	int i;
	list *p = head_nf;
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
	p = head_nf;
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
int check_exsit_nf(int number)
{
	list *p = head_nf;
	while (p != NULL)
	{
		if (p->used && p->number == number)
			return 1;
		p = p->next;
	}
	return 0;
}

//初始化
void init_nf(int total, int command)
{
	head_nf = (struct list*)malloc(sizeof(struct list));
	head_nf->used = 0;
	head_nf->start = 0;
	head_nf->end = total - 1;
	head_nf->size = head_nf->end - head_nf->start + 1;
	head_nf->pre = NULL;
	head_nf->next = NULL;
	cur = head_nf;
}

//分配
int allocate_nf(int number, int size)
{
	struct list *p;
	if (!cur->used && cur->size >= size)
	{
		if (cur->size == size)
		{
			//当前结点大小正好满足需求
			cur->used = 1;
			cur->number = number;
		}
		else
		{
			//当前结点大小大于需求
			struct list *tmp;
			tmp = (struct list *)malloc(sizeof(struct list));
			tmp->start = cur->start;
			tmp->end = cur->start + size - 1;
			tmp->size = size;
			tmp->number = number;
			tmp->used = 1;
			tmp->pre = cur->pre;
			tmp->next = cur;
			if (cur->pre != NULL)
				cur->pre->next = tmp;
			cur->pre = tmp;
			cur->start = tmp->end + 1;
			cur->size = cur->end - cur->start + 1;
			if (cur == head_nf)
				head_nf = tmp;
		}
		return 1;
	}
	p = cur->next;
	while (p != cur)
	{
		if (p == NULL)
			p = head_nf;
		if (!p->used && p->size >= size)
		{
			cur = p;
			if (p->size == size)
			{
				//空闲结点大小正好满足需求
				p->used = 1;
				p->number = number;
			}
			else
			{
				//空闲结点大小大于需求
				struct list *tmp;
				tmp = (struct list *)malloc(sizeof(struct list));
				tmp->start = p->start;
				tmp->end = p->start + size - 1;
				tmp->size = size;
				tmp->number = number;
				tmp->used = 1;
				tmp->pre = p->pre;
				tmp->next = p;
				if (p->pre != NULL)
					p->pre->next = tmp;
				p->pre = tmp;
				p->start = tmp->end + 1;
				p->size = p->end - p->start + 1;
				if (p == head_nf)
					head_nf = tmp;
			}
			return 1;
		}
		else
			p = p->next;
	}
	return 0;
}

//释放
void release_nf(int number)
{
	struct list *p = head_nf;
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
		if (p->next!=NULL)
			p->next->pre = p->pre;
		p = p->pre;
	}
	if (p->next && !p->next->used )
	{
		p->next->size += p->size;
		p->next->start = p->start;
		p->next->pre = p->pre;
		if (p->pre!=NULL)
			p->pre->next = p->next;
	}
	return;
}

int next_fit(int number, int size)
{
	if (!size)
		print_memory_nf();
	if (size > 0)
		//占用内存
		if (check_exsit_nf(number))
			return -1;
		else
			if (allocate_nf(number, size))
				return 1;
			else
				return -2;
	else
		//释放内存
		if (!check_exsit_nf(number))
			return -1;
		else
		{
			release_nf(number);
			return 1;
		}
	return 0;
}