#include<stdio.h>

void main() {
	int a[5] = { 10, 20, 30, 40, 50 };
	int* pa;

	pa = a;
	printf("*pa = %d\n", *pa);
	pa = a + 1;
	printf("*pa = %d\n", *pa);
	pa = a + 2;
	printf("*pa = %d\n", *pa);

	printf("*pa = %d\n", *(a + 3));
	printf("*pa = %d\n", *(a + 4));
}