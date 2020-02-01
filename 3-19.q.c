#include<stdio.h>

//str의 시작주소를 저장하기 위해 char*형태로 매개변수 선언
void convertToUppercase(char* s) {
	while (*s != '\0') {//s의 주소가 가르키는 값이 '\0'값이 아니야
		if (*s >= 'a' && *s <= 'z')
			*s = *s - 32;
		else if (*s >= 'A' && *s <= 'Z')
			*s = *s + 32;
		s++; //s = s + 1 => 100 => 101번지를 저장 
	}
}
void main() {
	char str[25];
	printf("영어 단어 입력 : ");
	scanf("%s", str);
	printf("변환전의 스트링 : %s\n", str);
	convertToUppercase(str);//함수호출(str의 시작주소를 인자로 넘김)
	printf("변환후의 스트링 : %s\n", str);
}