#include"first_fit.h"

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

struct list *head;
int tot, com;

//��ʼ������
void init_ff(int total, int command)
{
	head = (struct list*)malloc(sizeof(struct list));
	head->used = 0;
	head->start = 0;
	head->end = total - 1;
	head->size = head->end - head->start + 1;
	head->pre = head;
	head->next = head;
	tot = total;
	com = command;
}

//�����ǰ�ڴ����
void print_memory()
{
	int i;
	list *p;
	cout << endl << "                               ��ǰ�ڴ����" << endl << "                               ";
	for (i = head->start; i <= head->end; i++)
		if (head->used)
			cout << "*";
		else
			cout << "+";
	p = head->next;
	while(p!=head)
	{
		for (i = p->start; i <= p->end; i++)
			if (p->used)
				cout << "*";
			else
				cout << "+";
		p = p->next;
	}
	cout << endl << endl;
	cout << "     ��" << head->start << "-" << head->end << ",��С:" << head->size << ",״̬:";
	if (head->used)
		cout << "ռ��,���̺�:" << head->number << endl;
	else
		cout << "����" << endl;
	p = head->next;
	while (p != head)
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
int check_exsit(int number)
{
	list *p;
	if (head->used && head->number == number)
		return 1;
	p = head->next;
	while (p != head)
	{
		if (p->used && p->number == number)
			return 1;
		p = p->next;
	}
	return 0;
}

//�����ڴ�
bool allocate(int number, int size)
{
	struct list *p;
	if (!head->used && head->size >= size)
	{
		if (head->size == size)
		{
			//ͷ����С������������
			head->used = 1;
			head->number = number;
		}
		else
		{
			//ͷ����С��������
			struct list *tmp;
			tmp = (struct list *)malloc(sizeof(struct list));
			tmp->start = 0;
			tmp->end = size - 1;
			tmp->size = size;
			tmp->number = number;
			tmp->used = 1;
			tmp->pre = head->pre;
			tmp->next = head;
			head->pre = tmp;
			head->next = tmp;
			head->start = size;
			head->size = head->end - head->start + 1;
			head = tmp;
		}
		return 1;
	}
	p = head->next;
	while (p != head)
	{
		if (!p->used && p->size >= size)
		{
			if (p->size == size)
			{
				//���н���С������������
				p->used = 1;
				p->number = number;
			}
			else
			{
				//���н���С��������
				struct list *tmp;
				tmp = (struct list *)malloc(sizeof(struct list));
				tmp->start = p->start;
				tmp->end = p->start + size - 1;
				tmp->size = size;
				tmp->number = number;
				tmp->used = 1;
				tmp->pre = p->pre;
				tmp->next = p;
				p->pre->next = tmp;
				p->pre = tmp;
				p->start = tmp->end + 1;
				p->size = p->end - p->start + 1;
			}
			return 1;
		}
		else
			p = p->next;
	}
	return 0;
}

//�ͷ��ڴ�
void release(int number)
{
	struct list *p;
	if (head->number == number && head->used)
	{
		if (head->next != head && head->next->used == 0)
		{
			head->next->size += head->size;
			head->next->start = 0;
			head->next->pre = head->pre;
			head->pre->next = head->next;
			head = head->next;
			return;
		}
		else
		{
			head->used = 0;
			return;
		}
	}
	p = head->next;
	while (p != head)
	{
		if (p->number == number)
			break;
		p = p->next;
	}
	p->used = 0;
	if (!p->pre->used)
	{
		p->pre->size += p->size;
		p->pre->end = p->end;
		p->pre->next = p->next;
		p->next->pre = p->pre;
		p = p->pre;
	}
	if (!p->next->used && p->next != head)
	{
		p->next->size += p->size;
		p->next->start = p->start;
		p->next->pre = p->pre;
		p->pre->next = p->next;
	}
	return;
}

int first_fit(int number, int size)
{
	if (!size)
		print_memory();
	if (size > 0)
		//ռ���ڴ�
		if (check_exsit(number))
			return -1;
		else
			if (allocate(number, size))
				return 1;
			else
				return -2;
	else
		//�ͷ��ڴ�
		if (!check_exsit(number))
			return -1;
		else
		{
			release(number);
			return 1;
		}
	return 0;
}