#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define EMPTY 0

typedef struct node {
	int data;
	struct node* link;
	char name[30];
}Queue;

Queue* GetNode() {
	Queue* tmp;
	tmp = (Queue*)malloc(sizeof(Queue));
	tmp->link = EMPTY;
	return tmp;
}

void enqueue(Queue** front, Queue** rear, int data, char* name) {

	if (*front == EMPTY) 
	{
		*front = GetNode();
		*rear = *front;
		(*front)->data = data;
		strcpy((*front)->name, name);
	}

	else 
	{
		Queue* tmp = *rear;
		*rear = GetNode();
		(*rear)->data = data;
		strcpy((*rear)->name, name);
		tmp->link = *rear;
	}


}

int dequeue(Queue** front) {

	if (*front == EMPTY) {
		printf("접수된 응시자가 없습니다\n");
		return -1;
	}
	Queue* tmp = *front;//1000번지를 tmp에 저장
	*front = (*front)->link;//main의 front가 2000번지를 가르키게합니다.
	int num = tmp->data;//1000번지의 data를 저장
	
	printf("수험번호 %d, %s님의 시험을 진행합니다.\n", tmp->data, tmp->name);
	free(tmp);//1000번지 공간 해제

	
}

void print_all(Queue** front) {
	int num;
	Queue* tmp;
	tmp = *front;
	while (tmp != EMPTY) {
		printf("수험번호 : %d, 이름 : %s\n", tmp->data, tmp->name);
		tmp = tmp->link;
	}
}

void main()
{
	int number, data;
	char name[30];

	Queue* front = EMPTY;
	Queue* rear = EMPTY;

	puts("\n * queue test * \n");

	while (1)
	{
		printf("======================================\n");
		printf("1. 시험접수\n");
		printf("2. 시험시작\n");
		printf("3. 대기자조회\n");
		printf("======================================\n");
		printf(" 번호를 선택하세요[종료-> 0] : ");
		scanf("%d", &number);

		if (number == 0)
			return;

		switch (number)
		{
		case 1:
			printf("======================================\n");
			printf("1. 시험접수 메뉴입니다.\n");
			printf("======================================\n");
			printf("응시자님의 성함을 입력해주세요 : ");
			scanf("%s", name);
			printf("응시자님의 수험번호를 입력해주세요 : ");
			scanf("%d", &data);

			printf("======================================\n");
			printf("수험번호는 %d, 성함은 %s 입니다.\n", data, name);
			
			enqueue(&front, &rear, data, name);
			break;

		case 2:
			printf("======================================\n");
			printf("2. 시험진행 메뉴입니다.\n");
			printf("======================================\n");
			dequeue(&front, name, data);
			break;

		case 3:
			printf("======================================\n");
			printf("3. 대기자 확인 메뉴입니다.\n");
			printf("======================================\n");
			print_all(&front);
			printf("======================================\n");
			printf("모든 대기자의 출력을 완료했습니다.\n");

			break;

		default:
			printf("======================================\n");
			printf(" 경고! %d 는 메뉴에 없는 번호입니다. \n", number);

		}
		system("pause");
		system("cls");
	}

	return 0;
}