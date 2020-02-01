#include<stdio.h>

void compare(int* x, int* y) {
	if (*x > * y)
		printf("%d는 %d보다 큽니다.\n", *x, *y);
	else if (*x < *y)
		printf("%d는 %d보다 큽니다.\n", *y, *x);
	else
		printf("%d는 %d과 같습니다.\n", *y, *x);
}

void main() {
	int num1, num2;
	printf("두 수를 입력 :");
	scanf("%d%d", &num1, &num2);

	compare(&num1, &num2);
}