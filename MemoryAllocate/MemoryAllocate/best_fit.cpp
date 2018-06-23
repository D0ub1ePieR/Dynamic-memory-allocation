#include "best_fit.h"

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

struct list *head_bf;

//�����ǰ�ڴ����
void print_memory_bf()
{
	int i;
	list *p = head_bf;
	cout << endl << "                               ��ǰ�ڴ����" << endl << "                               ";
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
	p = head_bf;
	while (p != NULL)
	{
		cout << "     ��" << p->start << "-" << p->end << ",��С:" << p->size << ",״̬:";
		if (p->used)
			cout << "ռ��,���̺�:" << p->number << endl;
		else
			cout << "����" << endl;
		p = p->next;
	}
	cout << endl;
}

//У�������Ƿ��Ѿ�����
int check_exsit_bf(int number)
{
	list *p = head_bf;
	while (p != NULL)
	{
		if (p->used && p->number == number)
			return 1;
		p = p->next;
	}
	return 0;
}

//��ʼ��
void init_bf(int total, int command)
{
	head_bf = (struct list*)malloc(sizeof(struct list));
	head_bf->used = 0;
	head_bf->start = 0;
	head_bf->end = total - 1;
	head_bf->size = head_bf->end - head_bf->start + 1;
	head_bf->pre = NULL;
	head_bf->next = NULL;
}

//����
int allocate_bf(int number, int size)
{
	struct list *p = head_bf, *alloc = NULL;
	while (p != NULL)
	{
		if (!p->used && p->size >= size)
			if (alloc == NULL)
				alloc = p;
			else
				if (p->size - size < alloc->size - size)
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
		if (alloc == head_bf)
			head_bf = tmp;
	}
}

//�ͷ�
void release_bf(int number)
{
	struct list *p = head_bf;
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


int best_fit(int number, int size)
{
	if (!size)
		print_memory_bf();
	if (size > 0)
		//ռ���ڴ�
		if (check_exsit_bf(number))
			return -1;
		else
			if (allocate_bf(number, size))
				return 1;
			else
				return -2;
	else
		//�ͷ��ڴ�
		if (!check_exsit_bf(number))
			return -1;
		else
		{
			release_bf(number);
			return 1;
		}
	return 0;
}