#include<stdio.h>
char compare(int x, int y);

void main() {
	int num1, num2;
	char size;
	printf("input 2 numbers : \n");
	scanf("%d%d", &num1, &num2);
	size = compare(num1, num2);

	if (size == 'Y')
		printf("result : %d \n", num1);
	else if (size == 'N')
		printf("result : %d \n", num2);
	else if (size == '=')
		printf("%d and %d are same\n", num1, num2);
}

char compare(int x, int y) {
	if (x > y)
		return 'Y';
	else if (x < y)
		return 'N';
	else
		return '=';
}