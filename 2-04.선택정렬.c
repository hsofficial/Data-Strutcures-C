#include<stdio.h>

int main(void) {
	int arr[5] = { 4, 8, 2, 7, 6 };
	int tmp;

	printf("before sorting\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < 4; i++) {  //5-1���� ������ ����� ���� �ʿ䰡 ������.
		for (int j = i + 1; j < 5; j++) {  //���� ��ġ +1���� ���������� ��.
			if (arr[i] > arr[j]) {  //���������̴� ������ Ȯ��.
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