#include<stdio.h>
#include<stdlib.h>//malloc을 사용하기 위한 헤더
#define EMPTY 0 //EMPTY를 0으로 지정

//linkedlist를 이용한 스택 => 연결리스트를 이용한 스택
typedef struct node {
	int data;
	struct node* link;//struct node포인터형태의 link선언 
}Stack;

//heap영역에 동적할당하는 함수
Stack* get_node() {
	Stack* tmp;
	//heap영역에 Stack구조체 크기의 주소를 할당하고 그 주소를 tmp에 들고옴
	tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = EMPTY; //구조체의 link에 EMPTY를 넣음(아무주소도 넣지 않은 상태)
	return tmp;
}

void push(Stack** top, int data) {
	//top : main의 top의 주소를 들고있어요
	//*top : main의 top이 가르키는 주소를 가르켜요
	//**top : main의 top이 가르키는 주소로 따라가보니 보이는 구조체
	//(**top).data == (*top)->data
	Stack* tmp = *top;//push의 tmp에게 main함수의 top이 가르키는 주소 저장

	*top = get_node();//main의 top이 가르키는 주소를 haep영역의 주소로 바꿔줌(get_node호출)

	(*top)->data = data;
	(*top)->link = tmp;
	//main의 top이 가르키는 주소의 구조체에 data변수에 내 data저장
	//main의 top이 가르키는 주소의 구조체에 link변수에 내 tmp저장
}

int pop(Stack** top) {
	if ((*top) == EMPTY) {
		printf("Stack is Underflow\n");
		return -1;
	}
	Stack* tmp = (*top); //3000번지를 tmp에게 저장
	*top = (*top)->link; //main의 top이 2000번지를 가르키도록 합니다.
	int data = tmp->data; //3000번지의 데이터를 data에 저장
	free(tmp);//3000번지를 없애줘요
	return data;
}
void main() {
	Stack* top = EMPTY;//Stack구조체포인터 tmp변수 선언 후 빈 공간을 가르키도록 초기화
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top)); //underflow발생 
}