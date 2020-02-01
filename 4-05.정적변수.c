#include<stdio.h>

void count();

void main() {
	int num = 0;
	while (num < 3)
	{
		count();
		num++;
	}
}

void count(void) {
	static int x = 0;
	int y = 0;
	x += 1;
	y += 1;
	printf("x = %d, y = %d\n", x, y);
}