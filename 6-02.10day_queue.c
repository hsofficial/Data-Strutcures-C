#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

//linkedlist�� �̿��� queue => ���Ḯ��Ʈ�� �̿��� queue
typedef struct node 
{
	int data;
	struct node* link;//struct node������������ link���� 
}Node;

typedef struct lQueue
{
	Node* front;
	Node* rear;
	//front, rear ����
}LQueue;

typedef LQueue Queue;

void Init(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}
//ť �ʱ�ȭ ����

int empty(Queue* pq)
{
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}
//ť ����� Ȯ���� �����ϱ� ���� �Լ�

void enqueue(Queue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->link = NULL;
	newNode->data = data;

	if (empty(pq))	
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	//������϶��� front�� rear�� ��� �����ؾ��Ѵ�

	else
	{
		pq->rear->link = newNode;
		pq->rear = newNode;
	}
	//�̹� ���ִ� ���¿����� rear�� �������ָ� �ȴ�
}
//ť�� ���� ����ִ� ��Ȳ�� ���� �Լ�

Data dequeue(Queue* pq)
{
	Node* delNode;
	Data retData;
	//��� ������, ���ϰ��� ������ �Ҵ� ��ġ ����

	if (empty(pq))
	{
		printf("ť�� ����ֽ��ϴ�!\n==========================\n");
	}
	//ť�� ����ִ� ��Ȳ���� ť�� ��쵵�� �䱸�Ҷ� �����޽��� ���

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->link;
	//front�� ���� ��带 ����Ű���� �Ѵ�

	free(delNode);
	return retData;
	//��带 �����Ͽ� ���ʿ��� ���ҽ� ��� ����
}
//ť���� ���� ������ ��Ȳ�� ���� �Լ�

int main()
{
	//creates queue
	Queue q;
	Init(&q);

	//data input
	enqueue(&q, 10);
	//front rear ��� ������ �� �κ�
	enqueue(&q, 20);
	//printf("f : %d, r : %d\n", node* front, node* rear);
	enqueue(&q, 30);
	//fr print
	enqueue(&q, 40);
	//fr print

	//data output > dequeue
	printf("dequeue : %d\n", dequeue(&q));
	printf("dequeue : %d\n", dequeue(&q));
	printf("dequeue : %d\n", dequeue(&q));
	printf("dequeue : %d\n", dequeue(&q));
	printf("===============\n");
	return 0;
}