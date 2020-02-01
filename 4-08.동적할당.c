#include<stdio.h>
#include<stdlib.h>

void main() {
	int* ptr;
	int count, i;

	printf("몇개의 공간을 생성하시겠습니까? : ");
	scanf("%d", &count);

	ptr = (int*)malloc(sizeof(int) * count);

	for (i = 0; i < count; i++) {
		ptr[i] = i + 1;
		printf("%d\n", ptr[i]);
	}
	free(ptr);
}