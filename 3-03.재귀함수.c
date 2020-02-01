#include<stdio.h>
void Recursive(int n) {
	if (n == 0) {
		return;
	}
	Recursive(n - 1);
	printf("%d", n);
}

void main() {
	Recursive(3);
}