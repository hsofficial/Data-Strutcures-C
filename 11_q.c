#include<stdio.h>

void main() {
	int kor, eng, mat, avg;

	printf("kr score : ");
	scanf("%d", &kor);
	printf("en score : ");
	scanf("%d", &eng);
	printf("mat score : ");
	scanf("%d", &mat);

	avg = (kor + eng + mat) / 3;

	switch (avg / 10) {
	case 10: case 9: //case 9, case 10�� ���ӹ����� ����
		printf("����� %d, A����Դϴ�.\n",avg);
		break;
	case 8:
		printf("����� %d, B����Դϴ�.\n", avg);
		break;
	case 7:
		printf("����� %d, C����Դϴ�.\n", avg);
		break;
	case 6:
		printf("����� %d, D����Դϴ�.\n", avg);
		break;
	default:
		printf("����� %d, F����Դϴ�.\n", avg);
	}
}