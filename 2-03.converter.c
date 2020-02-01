#include<stdio.h>

int card_convr(unsigned x, int n, char *d) {
	char dchar[] = "0123456789ABCDEF";
	int digits = 0;

	if (x == 0)
		d[digits++] = dchar[0];
	else {

		while (x) {
			d[digits++] = dchar[x % n];
			x /= n;
		}
	}
	return digits;
}

void main() {
	unsigned int no;
	int cd, dno, select;
	char cno[50];
	printf("10진수의 기수변환");

	while (1) {
		printf("변환하고자 하는 양의 정수 입력 : ");
		scanf("%u", &no);

		do {
			printf("몆진수로 변환하시겠습니까? (2, 8, 16) : ");
			scanf("%d", &cd);
		} while (cd < 2 || cd > 16);

		dno = card_convr(no, cd, cno);

		printf("%d진수로 ", cd);
		for (int i = dno - 1;  i >= 0; i--)
			printf("%d", cno[i]);
		printf(" 입니다\n");

		printf("한번더 작업을 실행하겠습니까(1=Y, 2=N) : ");
		scanf("%d", &select);

		if (select == 0)
			break;
	}
}