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

	for (int i = 0; i < 4; i++) {	//[�迭ũ��] - 1�� ȸ���� �ǽ���. ���⼭ i < [(�迭��ũ��) - 1]�� �������ش�
		tmp = arr[i + 1];	//�ӽð� �Ҵ�

		for (j = i; j > -1; j--) {	//�ӽð� ��ġ�� �κ� �ٷ� �պ��� arr 0���� ����

			if (arr[j] > tmp) {	//���������̹Ƿ� ������ Ȯ���Ѵ�
				arr[j + 1] = arr[j];	//�׻� ��ĭ ������ �� �ǽ�
			}

			else {
				break;	//���̹Ƿ� ���̻� �˻����� �ƴ��Ѵ�
			}
		}
		//cf. j+1�� ������ ����� �������� �� ĭ ��, �߰��� �������� j--�� �Ѿ���� ������ j=-1�� ����, 0���� �������� j+1�� �ʿ�.

		arr[j + 1] = tmp;	//�� �̻� ���� ���� �߰����� �� ������ �� �ٷ� �� ��ġ�� �ӽð��� �� ��ġ
	}

	printf("after sorting\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;

}