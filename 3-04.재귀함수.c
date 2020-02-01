#include<stdio.h>
int Factorial(int n) {
	if (n == 0) {
		return 1;
	}
	return n * Factorial(n - 1);
}

void main() {
	int result = Factorial(9);
	printf("result is %d\n", result);
}