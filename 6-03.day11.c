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
		printf("������ �����ڰ� �����ϴ�\n");
		return -1;
	}
	Queue* tmp = *front;//1000������ tmp�� ����
	*front = (*front)->link;//main�� front�� 2000������ ����Ű���մϴ�.
	int num = tmp->data;//1000������ data�� ����
	
	printf("�����ȣ %d, %s���� ������ �����մϴ�.\n", tmp->data, tmp->name);
	free(tmp);//1000���� ���� ����

	
}

void print_all(Queue** front) {
	int num;
	Queue* tmp;
	tmp = *front;
	while (tmp != EMPTY) {
		printf("�����ȣ : %d, �̸� : %s\n", tmp->data, tmp->name);
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
		printf("1. ��������\n");
		printf("2. �������\n");
		printf("3. �������ȸ\n");
		printf("======================================\n");
		printf(" ��ȣ�� �����ϼ���[����-> 0] : ");
		scanf("%d", &number);

		if (number == 0)
			return;

		switch (number)
		{
		case 1:
			printf("======================================\n");
			printf("1. �������� �޴��Դϴ�.\n");
			printf("======================================\n");
			printf("�����ڴ��� ������ �Է����ּ��� : ");
			scanf("%s", name);
			printf("�����ڴ��� �����ȣ�� �Է����ּ��� : ");
			scanf("%d", &data);

			printf("======================================\n");
			printf("�����ȣ�� %d, ������ %s �Դϴ�.\n", data, name);
			
			enqueue(&front, &rear, data, name);
			break;

		case 2:
			printf("======================================\n");
			printf("2. �������� �޴��Դϴ�.\n");
			printf("======================================\n");
			dequeue(&front, name, data);
			break;

		case 3:
			printf("======================================\n");
			printf("3. ����� Ȯ�� �޴��Դϴ�.\n");
			printf("======================================\n");
			print_all(&front);
			printf("======================================\n");
			printf("��� ������� ����� �Ϸ��߽��ϴ�.\n");

			break;

		default:
			printf("======================================\n");
			printf(" ���! %d �� �޴��� ���� ��ȣ�Դϴ�. \n", number);

		}
		system("pause");
		system("cls");
	}

	return 0;
}