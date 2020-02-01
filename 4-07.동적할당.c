#include<stdio.h>
#include<stdlib.h>

void main() {
	int* ptr = (int*)malloc(sizeof(int));
	*ptr = 100;

	printf("ptr이 가르키는 값 : %d\n", *ptr);
	printf("ptr이 가르키는 공간의 크기 : %d\n", sizeof(*ptr));

	free(ptr);

	printf("ptr이 가르키는 값 : %d\n", *ptr);
	printf("ptr이 가르키는 공간의 크기 : %d\n", sizeof(*ptr));
}