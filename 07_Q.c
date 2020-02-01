#include<stdio.h>

void main() {
	int a, b;
	int max;

	printf("maxinum num about 2 ints\n");

	printf("number a : ");
	scanf("%d", &a);

	printf("number b : ");
	scanf("%d", &b);

	max = a;

	if (b > max)
		max = b;

	printf("maximum num is %d\n", max);
}