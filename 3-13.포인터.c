#include<stdio.h>

void main() {
	int num1 = 5, num2 = 10;
	int* p1 = &num1, * p2 = &num2;

	*p1 = num1 + num2;
	num2 = *p1 + *p2;

	printf("num1 = %d, num2 = %d, *p1 = %d, *p2 = %d\n", num1, num2, *p1, *p2);
}  