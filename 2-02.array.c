#include<stdio.h>

void main() {
	char arr[10];
	scanf("%s", arr);

	for (int i = 0; i < 10; i++) {
		printf("arr[%d] = %c\n", i, arr[i]);
	}

	printf("\n\n%s\n", arr);
}