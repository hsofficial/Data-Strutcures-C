#include<stdio.h>

void sv() {
	static int a = 10;
	int b = 10;
	a++;
	b++;
	printf("static변수 a의 값 : %d, 지역변수 b의 값 : %d\n", a, b);
}

void main() {
	int i;
	for (i = 0; i < 5; i++) {
		sv();
	}
}