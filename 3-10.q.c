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
	printf("����ϰ��� �ϴ� �Ǻ���ġ ���� ������ ��ġ ����\n(�Ǻ���ġ ������ �Լ��� fib(n)���� �����Ҷ� n�� ��) : ");
	scanf("%d", &n);
	printf("result is %lld\n", f(n));
}