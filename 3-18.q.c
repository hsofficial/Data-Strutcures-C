#include<stdio.h>

void compare(int* x, int* y) {
	if (*x > * y)
		printf("%d�� %d���� Ů�ϴ�.\n", *x, *y);
	else if (*x < *y)
		printf("%d�� %d���� Ů�ϴ�.\n", *y, *x);
	else
		printf("%d�� %d�� �����ϴ�.\n", *y, *x);
}

void main() {
	int num1, num2;
	printf("�� ���� �Է� :");
	scanf("%d%d", &num1, &num2);

	compare(&num1, &num2);
}