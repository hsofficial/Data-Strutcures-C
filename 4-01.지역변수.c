#include<stdio.h>
void func_A(void);
int func_B(void);

void main(void) {
	int aa = 10;
	printf("�Լ� ȣ�� ���� main()�Լ��� aa�� : %d\n", aa);
	func_A();
	printf("func_A()�Լ� ȣ�� �� main()�Լ��� aa�� : % d\n", aa);
	printf("func_B()�Լ� ȣ�� �� main()�Լ��� aa�� : % d\n", func_B());
}

void func_A() {
	int aa = 20;
	int bb = 30;
	printf("func_A()�Լ��� aa�� : %d\n", aa);
	printf("func_B()�Լ��� bb�� : %d\n", bb);
}

int func_B() {
	int aa = 35;
	return aa;
}