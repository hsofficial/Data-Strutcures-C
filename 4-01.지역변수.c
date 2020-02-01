#include<stdio.h>
void func_A(void);
int func_B(void);

void main(void) {
	int aa = 10;
	printf("함수 호출 이전 main()함수의 aa값 : %d\n", aa);
	func_A();
	printf("func_A()함수 호출 후 main()함수의 aa값 : % d\n", aa);
	printf("func_B()함수 호출 후 main()함수의 aa값 : % d\n", func_B());
}

void func_A() {
	int aa = 20;
	int bb = 30;
	printf("func_A()함수의 aa값 : %d\n", aa);
	printf("func_B()함수의 bb값 : %d\n", bb);
}

int func_B() {
	int aa = 35;
	return aa;
}