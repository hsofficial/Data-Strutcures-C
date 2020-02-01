#include<stdio.h>
int sum(int n);

int main() {
	int num;
	int res;

	printf("1부터 모두 더하고자 하는 수 입력 : ");
	scanf("%d", &num);
	
	res = sum(num);

	printf("1부터 %d까지의 합은 %d\n", num, res);

	return 0;
}

int sum(int n) {
	if (n <= 0)
		return 0;
	return n + sum(n - 1);
}