#include <stdio.h>
int PrimeNumber(int n);

int main(void)
{
	int num1;
	int tmp;

	printf("정수 입력:");
	scanf("%d", &num1);
	tmp = PrimeNumber(num1);

	if (tmp == 1)
		printf("%d is prime number.\n", num1);
	else if (tmp == 0)
		printf("%d is not prime number.\n", num1);

	return 0;
}

int PrimeNumber(int n) 
{
	int i = 0;
	int last = n / 2; 
	if (n <= 1)
	{
		return 0;
	}
	
	for (i = 2; i <= last; i++)
	{
		if ((n % i) == 0)
		{
			return 0;
		}
	}
	return 1;
}