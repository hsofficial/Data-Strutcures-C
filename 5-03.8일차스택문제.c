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

void push(Stack** top, int data)
{
	printf("======================================\n");
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

	printf("push 명령을 잘 실행했습니다.\n");
}

int pop(Stack**top)
{
	if ((*top) == EMPTY)
	{
		printf("스택에 쌓여있는 모든 함수를 꺼내었습니다.\n Underflow가 발생합니다.\n");
		return -1;
	}

	Stack* tmp = (*top); //3000번지를 tmp에게 저장
	*top = (*top)->link; //main의 top이 2000번지를 가르키도록 합니다.
	int data = tmp->data; //3000번지의 데이터를 data에 저장
	free(tmp);//3000번지를 없애줘요
	return data;

}

void print_all(Stack** top)
{
	printf("print_all : 현시점 전체 데이터를 확인합니다 \n");
	//반복문 이용해서 현재 스택의 다음 노드를 읽어가며 프린트하도록 구성한다
	int num;
	Stack* tmp;
	tmp = *top;
	while (tmp != EMPTY) {
		printf("데이터 : %d \n", tmp->data);
		tmp = tmp->link;
	}
}


void main()
{
	Stack* top = EMPTY;
	//Stack구조체포인터 tmp변수 선언 후 빈 공간을 가르키도록 초기화
	
	int number;
	int push_tmp;

	puts("\n * stack test * \n");

	while (1)
	{
		printf("======================================\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. PRINT_ALL\n");
		printf("======================================\n");
		printf(" 번호를 선택하세요[종료-> 0] : ");
		scanf("%d", &number);

		if (number == 0)
			return;

		switch (number)
		{
		case 1:
			printf("======================================\n");
			printf("push 하고자 하는 int형 데이터 입력 : ");
			scanf("%d", &push_tmp);
			push(&top, push_tmp);
			break;

		case 2:
			printf("======================================\n");
			printf("pop 함수가 < %d > 데이터를 꺼냈습니다.\n", pop(&top));
			break;

		case 3:
			printf("======================================\n");
			print_all(&top);
			break;

		default:
			printf(" %d 는 메뉴에 없는 번호입니다. \n", number);

		}

	}

	return 0;
}
