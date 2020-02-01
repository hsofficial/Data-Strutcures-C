#include<stdio.h>

void main() 
{
	int num, i1, i2;
	int count = 0;

	printf("input number : ");
	scanf("%d", &num);

	printf("divisor(s) are : ");

	for (i1 = 1; i1 <= num; i1++)
	{
		if (num % i1 == 0)
		{
			printf("%d ", i1);
		}
	}


	printf(", the number of weak number(s) : ");

		for (i2 = 1; i2 <= num; i2++)
		{
			if (num % i2 == 0)
			{
				count = count + 1;
			}
		}

	printf("%d", count);

}