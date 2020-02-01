#include<stdio.h>

void main() 
{
	int num;

	printf("plz input number : ");
	scanf("%d", &num);

	while (num) 
	{
		printf("%d", num % 10);
		num = num / 10;
	}
}