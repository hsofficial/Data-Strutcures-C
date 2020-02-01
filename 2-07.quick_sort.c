#include<stdio.h>

//배열을 입력해준다
int arr[8] = { 8, 4, 2, 11, 5, 3, 9, 12 };
int len = sizeof(arr) / sizeof(int);

//quick_sort 함수를 선정의하여 계산과정에 사용한다
void quick_sort(int *arr, int start, int end) {

	if (start >= end)
	{ // 원소가 1개인 경우는 그냥 출력시켜주면 된다
		return;
	}

	int pivot = start; //pivot 설정
	int i = pivot + 1; // 왼쪽 출발 지점은 pivot의 다음 값
	int j = end; // 오른쪽 출발 지점
	int temp;

	while (i <= j)
	{ // 교차가 발생하기 이전까지 반복해준다

		// 피벗보다 큰 값을 찾는 과정 
		// low를 오른쪽으로 이동
		while (i <= end && arr[i] <= arr[pivot])
		{
			i++;
		}

		// 피벗보다 작은 값을 찾는 과정 
		// high를 왼쪽으로 이동
		while (j > start&& arr[j] >= arr[pivot])
		{
			j--;
		}

		// 엇갈림이 발생했을 때
		//피벗과 high가 가리키는 대상을 교환 
		// 옮겨진 피벗의 위치정보를 반환
		if (i > j)
		{
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}

		// 교차되지 않은 상태이면 스왑 과정 실행 
		// low와 high를 스왑 
		else
		{ 
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	// 분할 계산하여 각각 오른쪽과 왼쪽 영역 정렬
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

	//cal>앞서 정의한 quick_sort를 불러와서 실행한다
	quick_sort(arr, 0, len - 1);

	//chk output
	printf("after sorting\n");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;

}