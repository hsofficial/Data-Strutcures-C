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
	case 10: case 9: //case 9, case 10의 종속문장이 같음
		printf("평균은 %d, A등급입니다.\n",avg);
		break;
	case 8:
		printf("평균은 %d, B등급입니다.\n", avg);
		break;
	case 7:
		printf("평균은 %d, C등급입니다.\n", avg);
		break;
	case 6:
		printf("평균은 %d, D등급입니다.\n", avg);
		break;
	default:
		printf("평균은 %d, F등급입니다.\n", avg);
	}
}