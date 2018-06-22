#include"first_fit.h"

struct list
{
	int used;
	int number;
	int start;
	int end;
	struct list *pre;
	struct list *next;
};

struct list *head;
int tot, com;

void init_ff(int total, int command)
{
	head = (struct list*)malloc(sizeof(struct list));
	head->used = 0;
	head->start = 0;
	head->end = total - 1;
	head->pre = head;
	head->next = head;
	tot = total;
	com = command;
}

int first_fit(int number, int size)
{
	return 0;
}