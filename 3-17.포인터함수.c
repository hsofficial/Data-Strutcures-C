#include<stdio.h>
void convertToUppercase(char* s);

void main() {
	char str[] = "characters";

	printf("��ȯ �� ��Ʈ�� : %s\n", str);
	convertToUppercase(str);
	printf("��ȯ �� ��Ʈ�� : %s\n", str);
}

void convertToUppercase(char* s) {
	if (*s >= 'a' && *s <= 'z')
		*s = *s - 32;
}