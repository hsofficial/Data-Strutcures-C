#include<stdio.h>

int main(void) {
	int arr[5] = { 4, 8, 2, 7, 6 };
	int tmp;

	printf("before sorting\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < 4; i++) {  //5-1까지 마지막 대상은 비교할 필요가 없으니.
		for (int j = i + 1; j < 5; j++) {  //선정 위치 +1부터 마지막까지 비교.
			if (arr[i] > arr[j]) {  //오름차순이니 작은지 확인.
				tmp = arr[i];//swap.
				arr[i] = arr[j];
				arr[j] = tmp;
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