#include<stdio.h>
#include<stdlib.h>

//참조링크 https://new93helloworld.tistory.com/83

//상수값의 정의
#define MAX 4

typedef struct node {
	int arr[MAX]; //최대 길이만큼 공간할당
	int top; // stack의 가장 마지막 데이터 위치
}Stack; // 별칭은 Stack

//구조체 포인터변수로 매개변수를 선언하는 이유
//main이 아닌 함수에서 main의 값을 변경하기 위해
void init(Stack* p_stack)// init은 초기화 하는 함수
{
	p_stack->top = -1; //데이터를 넣을 위치를 -1로 초기화
}

//p_stack : 포인터변수 4byte짜리 주소저장하는 변수

//데이터 삽입을 위한 함수
void push(Stack *p_stack, int data) {
	//만약 stack의 인덱스가 최대기이-1 인덱스까지 왔으면 return
	if (p_stack->top >= (MAX - 1)) {
		printf("Stack이 꽉차서 더이상 저장할 수 없습니다\n");
		return; //push함수 종료
	}

	//p_stack->top++;//-1부터 시작하므로 하나 증가 => 데이터를 넣을 인덱스위치
	//주소를 따라가보니 구조체가 있네 구조체의 배열에 top인덱스에 데이터를 삽입
	//p_stack->arr[p_stack->top] = data;
	p_stack->arr[++(p_stack->top)] = data;

}

//데이터 삭제를 위한 함수
int pop(Stack *p_stack) {

	//top이 -1(초기값)까지 내려오면 반환할 데이터가 없다는 의미
	if (p_stack->top == -1) {
		printf("스택이 비어있어 반환할 값이 없습니다\n");
		return -1;
	}

	//현재 top이 가르키는 인덱스번호의 데이터를 반환하고 top을 한칸 감소시켜요
	return p_stack->arr[(p_stack->top)--];
}

//top 인덱스의 데이터를 확인할 때 사용하는 함수
int peek(Stack *p_stack) {

	//자료가 없다면 에러라는 뜻의 -1을 반환
	if (p_stack->top == -1) {
		printf("스택이 비어있어 확인할 데이터가 없습니다\n");
		return -1;
	}

	//TOP이 가르키고 있는 값을 출력
	return p_stack->arr[p_stack->top];
}


void main() {
	Stack stack;	//Stack구조체 생성
	//왜 주소를 넘겨주지? => stack은 main함수에 있어요 그런데 다른함수에서 stack의 arr[]에 값을 채워넣고 끄집어 내고싶어
	init(&stack);	//stack의 주소를 인자로 넘겨줌
	//간접참조 ->실제값 수정을 위함
	push(&stack, 5);//stack의 주소와 저장할 데이터를 넘겨줌
	push(&stack, 2);
	push(&stack, 7);
	push(&stack, 8);
	push(&stack, 10); //stack overflow발생 (배열이 꽉참)

	printf("peek : %d\n", peek(&stack));

	int n;
	n = pop(&stack); //pop함수 호출(데이터반환)
	printf("pop : %d\n", n);
	n = pop(&stack); //pop함수 호출(데이터반환)
	printf("pop : %d\n", n);
	n = pop(&stack); //pop함수 호출(데이터반환)
	printf("pop : %d\n", n);
	n = pop(&stack); //pop함수 호출(데이터반환)
	printf("pop : %d\n", n);
	n = pop(&stack); //underflow발생 (배열에 데이터가 없음)
	printf("pop : %d\n", n);
}