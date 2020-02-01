#include<stdio.h>

int sum(int x, int y) {
	int result;
	result = x + y;

	return result;
}

void main() {
	int num1, num2, result;
	printf("put 2 numbers : ");
	scanf("%d%d", &num1, &num2);
	result = sum(num1, num2);
	printf("sum : %d\n", result);
}