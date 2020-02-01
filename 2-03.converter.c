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
	printf("10������ �����ȯ");

	while (1) {
		printf("��ȯ�ϰ��� �ϴ� ���� ���� �Է� : ");
		scanf("%u", &no);

		do {
			printf("�p������ ��ȯ�Ͻðڽ��ϱ�? (2, 8, 16) : ");
			scanf("%d", &cd);
		} while (cd < 2 || cd > 16);

		dno = card_convr(no, cd, cno);

		printf("%d������ ", cd);
		for (int i = dno - 1;  i >= 0; i--)
			printf("%d", cno[i]);
		printf(" �Դϴ�\n");

		printf("�ѹ��� �۾��� �����ϰڽ��ϱ�(1=Y, 2=N) : ");
		scanf("%d", &select);

		if (select == 0)
			break;
	}
}