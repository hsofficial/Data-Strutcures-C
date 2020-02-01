#include<stdio.h>
void main() {
	for (int i = 1; i < 3; i++) {
		int total = 0;
		total += i;
		printf("for의 total값은 %d\n", total);
	}

	//작동이 불가능한 코드
	/*
	if (total < 10) {
		printf("if의 total값은 %d\n", total);
	}
	*/
}