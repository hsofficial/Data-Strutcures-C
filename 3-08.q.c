#include<stdio.h>
int sum(int n);

int main() {
	int num;
	int res;

	printf("1���� ��� ���ϰ��� �ϴ� �� �Է� : ");
	scanf("%d", &num);
	
	res = sum(num);

	printf("1���� %d������ ���� %d\n", num, res);

	return 0;
}

int sum(int n) {
	if (n <= 0)
		return 0;
	return n + sum(n - 1);
}