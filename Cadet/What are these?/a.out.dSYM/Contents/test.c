#include <stdio.h>

typedef struct test
{
	int x;
	struct test *next;
} test;

int main()
{
	test root, elem2;
	root.x = 15;
	root.next = &elem2;
	elem2.x = 42;
	root.next = NULL;

	printf("%d\n", root.x);
}