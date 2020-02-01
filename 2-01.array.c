#include<stdio.h>

void main() {
	int arr[10];

	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 10; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}