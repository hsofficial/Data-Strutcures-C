//���� ���ϴ� �Լ�
#include<stdio.h>
power(int num, int n);

int main() {
	int num, n, i;
	printf("���� �� �����Է� : ");
	scanf("%d", &num);
	printf("������ �� �����Է� : ");
	scanf("%d", &n);

	i = power(num, n);

	printf("%d�� %d���� %d\n", num, n, i);
}

power(int num, int n) {
	if (n <= 0)
		return 1;
	else
		return (num * power(num, n - 1));
}