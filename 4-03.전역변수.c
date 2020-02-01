#include<stdio.h>
int num;
void grow();

void main() {
	printf("함수 호출 전 num의 값 : %d\n", num);
	grow();
	printf("함수 호출 후 num의 값 : %d\n", num);
}

void grow() {
	num = 60;
	printf("함수 내부 num의 값 : %d\n", num);
}