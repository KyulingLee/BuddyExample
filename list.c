/*
 * 더블 링크드 리스트 함수
 * 작성자: Kyuling Lee
 * kyuling@me.com
 */

#include "Header/list.h"

void list_add(struct list_head* new, struct list_head* head)
{
	__list_add(new, head, head->next);
}

void __list_add(struct list_head* new, struct list_head* prev, struct list_head* next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

void list_del(struct list_head* entry)
{
	__list_del(entry->prev, entry->next);
	entry->next = (void*)0;
	entry->prev = (void*)0;
}

void __list_del(struct list_head* prev, struct list_head* next)
{
	next->prev = prev;
	prev->next = next;
}

void list_add_tail(struct list_head* new, struct list_head* head)
{
	__list_add(new, head->prev, head);
}
