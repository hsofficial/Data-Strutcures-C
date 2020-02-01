#include<stdio.h>

void main(void) {
	int age;
	printf("your age is : ");
	scanf("%d", &age);

	if (age > 0) {
		if (age > 19) {
			printf("over 19");
		}
		
		else {
			printf("under 19");
		}
	}

	else {
		printf("incorrect input");
	}
}