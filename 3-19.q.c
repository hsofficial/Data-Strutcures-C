#include<stdio.h>

//str�� �����ּҸ� �����ϱ� ���� char*���·� �Ű����� ����
void convertToUppercase(char* s) {
	while (*s != '\0') {//s�� �ּҰ� ����Ű�� ���� '\0'���� �ƴϾ�
		if (*s >= 'a' && *s <= 'z')
			*s = *s - 32;
		else if (*s >= 'A' && *s <= 'Z')
			*s = *s + 32;
		s++; //s = s + 1 => 100 => 101������ ���� 
	}
}
void main() {
	char str[25];
	printf("���� �ܾ� �Է� : ");
	scanf("%s", str);
	printf("��ȯ���� ��Ʈ�� : %s\n", str);
	convertToUppercase(str);//�Լ�ȣ��(str�� �����ּҸ� ���ڷ� �ѱ�)
	printf("��ȯ���� ��Ʈ�� : %s\n", str);
}