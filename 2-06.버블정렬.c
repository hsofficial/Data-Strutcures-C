#include<stdio.h>
int main(void) {
	int arr[5] = { 4, 8, 2, 7, 6 };
	int tmp;
	int len = sizeof(arr) / sizeof(int);

	printf("before sorting\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < len - 1; i++) {

		for (int j = 0; j < len - 1; j++) {

			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	printf("after sorting\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;

}