#include<stdio.h>

void sv() {
	static int a = 10;
	int b = 10;
	a++;
	b++;
	printf("static���� a�� �� : %d, �������� b�� �� : %d\n", a, b);
}

void main() {
	int i;
	for (i = 0; i < 5; i++) {
		sv();
	}
}