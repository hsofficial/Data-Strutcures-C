#include<stdio.h>

void main() {
	/*
	��������(insert sort)
	���� �־���� ��ġ�� ã�ư��鼭 �����ϴ� ���
	*/

	//creating save space
	int arr[5] = { 4,8,2,7,6 };
	int tmp;
	int len = sizeof(arr) / sizeof(int);
	
	//input data chk
	printf("before sorting\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	/*
	i������ arr[1]���� ���� j������ arr[0]���� ����
	j�� i�ձ��� �����ϸ鼭 ��
	i���� ��ҵ�� i�� �񱳸� �ؼ� ���� ��Ұ� �� ũ�� swap
	*/

	//sorting
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	//output data chk
	printf("after sorting\n");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}