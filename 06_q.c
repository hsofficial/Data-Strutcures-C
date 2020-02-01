#include<stdio.h>

void main() {
	int num;

	printf("number : ");
	scanf("%d", &num);
	
	if (num % 2 == 0) {
		printf("even number\n");
	}
	else {
		print("odd number\n");
	}
}