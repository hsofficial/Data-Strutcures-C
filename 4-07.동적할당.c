#include<stdio.h>
#include<stdlib.h>

void main() {
	int* ptr = (int*)malloc(sizeof(int));
	*ptr = 100;

	printf("ptr�� ����Ű�� �� : %d\n", *ptr);
	printf("ptr�� ����Ű�� ������ ũ�� : %d\n", sizeof(*ptr));

	free(ptr);

	printf("ptr�� ����Ű�� �� : %d\n", *ptr);
	printf("ptr�� ����Ű�� ������ ũ�� : %d\n", sizeof(*ptr));
}