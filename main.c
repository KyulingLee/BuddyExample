/*
 * 버디 시스템을 테스트 하는 메인 함수
 * 작성자: Kyuling Lee
 * kyuling@me.com
 */

#include "Header/buddy.h"

int main(void)
{
	input_size();

	int i = 0;
	struct page* page1;
	struct page* page2;
	struct page* page3;

	init_memory();

	printf("Initial State\n");
	for (i = 0; i <= 3; i++)
		_show_free_order_list(i);

	printf("\n\n");

	printf("Order1 page allocation\n");
	page1 = alloc_pages(0, 1);
	for (i = 0; i <= 3; i++)
		_show_free_order_list(i);

	printf("\n\n");

	printf("Order2 page allocation\n");
	page2 = alloc_pages(0, 2);
	for (i = 0; i <= 3; i++)
		_show_free_order_list(i);

	printf("\n\n");

	printf("Order3 page allocation\n");
	page3 = alloc_pages(0, 3);
	for (i = 0; i <= 3; i++)
		_show_free_order_list(i);

	_free_pages(page1->addr);
	_free_pages(page2->addr);
	_free_pages(page3->addr);

	free_memory();

	return 0;
}
