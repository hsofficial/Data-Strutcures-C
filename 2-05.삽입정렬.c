#include<stdio.h>
int main(void) {
	int arr[5] = { 4, 8, 2, 7, 6 };
	int tmp;
	int j;

	printf("before sorting\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < 4; i++) {	//[배열크기] - 1번 회전을 실시함. 여기서 i < [(배열의크기) - 1]로 지정해준다
		tmp = arr[i + 1];	//임시값 할당

		for (j = i; j > -1; j--) {	//임시값 위치한 부분 바로 앞부터 arr 0까지 진행

			if (arr[j] > tmp) {	//오름차순이므로 작은지 확인한다
				arr[j + 1] = arr[j];	//항상 한칸 위에서 비교 실시
			}

			else {
				break;	//앞이므로 더이상 검사하지 아니한다
			}
		}
		//cf. j+1인 이유는 종료된 시점보다 한 칸 앞, 추가로 마지막에 j--로 넘어오기 때문에 j=-1인 상태, 0번에 넣으려면 j+1이 필요.

		arr[j + 1] = tmp;	//더 이상 작은 값을 발견하지 못 했으니 그 바로 앞 위치가 임시값이 들어갈 위치
	}

	printf("after sorting\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;

}