#include <stdio.h>

int n;

long long int f(int k)
{
	if (k <= 2)
		return 1;
	return f(k - 2) + f(k - 1);
}

int main()
{
	printf("출력하고자 하는 피보나치 수열 숫자의 위치 지정\n(피보나치 수열의 함수를 fib(n)으로 정의할때 n의 값) : ");
	scanf("%d", &n);
	printf("result is %lld\n", f(n));
}