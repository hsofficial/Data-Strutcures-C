#include <stdio.h>
void odd_even(int num) {
	if (num % 2 == 0) {
		printf("¦��\n");
	}

	else if (num % 2 == 1) {
		printf("Ȧ��\n");
	}
}


void main() { 

	int num1; 
	printf("���� �Է�:");
	scanf("%d", &num1);
	odd_even(num1);
}