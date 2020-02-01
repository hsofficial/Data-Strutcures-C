#include<stdio.h>

//�迭�� �Է����ش�
int arr[8] = { 8, 4, 2, 11, 5, 3, 9, 12 };
int len = sizeof(arr) / sizeof(int);

//quick_sort �Լ��� �������Ͽ� �������� ����Ѵ�
void quick_sort(int *arr, int start, int end) {

	if (start >= end)
	{ // ���Ұ� 1���� ���� �׳� ��½����ָ� �ȴ�
		return;
	}

	int pivot = start; //pivot ����
	int i = pivot + 1; // ���� ��� ������ pivot�� ���� ��
	int j = end; // ������ ��� ����
	int temp;

	while (i <= j)
	{ // ������ �߻��ϱ� �������� �ݺ����ش�

		// �ǹ����� ū ���� ã�� ���� 
		// low�� ���������� �̵�
		while (i <= end && arr[i] <= arr[pivot])
		{
			i++;
		}

		// �ǹ����� ���� ���� ã�� ���� 
		// high�� �������� �̵�
		while (j > start&& arr[j] >= arr[pivot])
		{
			j--;
		}

		// �������� �߻����� ��
		//�ǹ��� high�� ����Ű�� ����� ��ȯ 
		// �Ű��� �ǹ��� ��ġ������ ��ȯ
		if (i > j)
		{
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}

		// �������� ���� �����̸� ���� ���� ���� 
		// low�� high�� ���� 
		else
		{ 
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	// ���� ����Ͽ� ���� �����ʰ� ���� ���� ����
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);

}

int main(void)
{
	//chk input
	printf("before sorting\n");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("\n");

	//cal>�ռ� ������ quick_sort�� �ҷ��ͼ� �����Ѵ�
	quick_sort(arr, 0, len - 1);

	//chk output
	printf("after sorting\n");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;

}