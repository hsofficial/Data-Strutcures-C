#include<stdio.h>

void main() {
	int num1 = 10, num2;
	int* ptr;

	ptr = &num1;
	num1++;
	num2 = 5;
	ptr = &num2;
	*ptr = *ptr + num1 + num2;

	printf("num1 = %d, num2 = %d, *ptr = %d\n", num1, num2, *ptr);
}