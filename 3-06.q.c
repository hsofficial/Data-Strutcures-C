#include <stdio.h>
void odd_even(int num) {
	if (num % 2 == 0) {
		printf("Â¦¼ö\n");
	}

	else if (num % 2 == 1) {
		printf("È¦¼ö\n");
	}
}


void main() { 

	int num1; 
	printf("Á¤¼ö ÀÔ·Â:");
	scanf("%d", &num1);
	odd_even(num1);
}