#include<stdio.h>
void convertToUppercase(char* s);

void main() {
	char str[] = "characters";

	printf("변환 전 스트림 : %s\n", str);
	convertToUppercase(str);
	printf("변환 후 스트림 : %s\n", str);
}

void convertToUppercase(char* s) {
	if (*s >= 'a' && *s <= 'z')
		*s = *s - 32;
}