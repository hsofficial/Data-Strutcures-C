#include<stdio.h>

void main() {
	int a[5] = { 10, 20, 30, 40, 50 };
	int* pa;
	pa = a;
	for (int i = 0; i < 5; i++)
		printf("�迭���ּ� %p �迭�ǰ� %d\n", pa + i, *(pa + i));
}