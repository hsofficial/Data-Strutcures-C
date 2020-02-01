#include<stdio.h>

void main() 
{
	int num, num_len, i;
	num_len = 0;
	i = 1;

	printf("plz input number : ");
	scanf("%d", &num);

	while (num > i) 
	{
		i *= 10;
		num_len++;
	}

	printf("%d is %d digit num.", num, num_len);
}