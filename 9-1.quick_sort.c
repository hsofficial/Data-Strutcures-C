#include<stdio.h>

int arr[8] = { 8, 4, 2, 11, 5, 3, 9, 12 };
int len = sizeof(arr) / sizeof(int);

void quick_sort(int *arr, int start, int end)
{
	if (start >= end)
	{ // ���Ұ� 1��
		return;
	}

	int pivot = start; 
	int i = pivot + 1; // ���� ��� ����
	int j = end; // ������ ��� ����
	int temp;

	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
		{
			i++;
		}

		while (j > start&& arr[j] >= arr[pivot])
		{
			j--;
		}

		if (i > j)
		{
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}

		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	//���
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

int main(void)
{
	//chk input
	printf("before sorting\n");

	for (int i = 0; i < len; i++) 
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	printf("\n");

	//cal
	quick_sort(arr, 0, len - 1);

	//chk output
	printf("after sorting\n");

	for (int i = 0; i < len; i++) 
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;

}