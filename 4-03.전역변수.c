#include<stdio.h>
int num;
void grow();

void main() {
	printf("�Լ� ȣ�� �� num�� �� : %d\n", num);
	grow();
	printf("�Լ� ȣ�� �� num�� �� : %d\n", num);
}

void grow() {
	num = 60;
	printf("�Լ� ���� num�� �� : %d\n", num);
}