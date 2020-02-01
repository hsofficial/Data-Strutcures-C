#include<stdio.h>

void main() {
	int a, b, c;
	int max;

	printf("maxinum num about three ints\n");

	printf("number a : ");
	scanf("%d", &a);
	printf("number b : ");
	scanf("%d", &b);
	printf("number c : ");
	scanf("%d", &c);

	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;

	printf("maximum num is %d .\n", max);
}