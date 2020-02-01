//제곱 구하는 함수
#include<stdio.h>
power(int num, int n);

int main() {
	int num, n, i;
	printf("밑이 될 정수입력 : ");
	scanf("%d", &num);
	printf("지수가 될 정수입력 : ");
	scanf("%d", &n);

	i = power(num, n);

	printf("%d의 %d승은 %d\n", num, n, i);
}

power(int num, int n) {
	if (n <= 0)
		return 1;
	else
		return (num * power(num, n - 1));
}