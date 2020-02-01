#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

//linkedlist를 이용한 queue => 연결리스트를 이용한 queue
typedef struct node 
{
	int data;
	struct node* link;//struct node포인터형태의 link선언 
}Node;

typedef struct lQueue
{
	Node* front;
	Node* rear;
	//front, rear 선언
}LQueue;

typedef LQueue Queue;

void Init(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}
//큐 초기화 진행

int empty(Queue* pq)
{
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}
//큐 빈상태 확인을 진행하기 위한 함수

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
	//빈상태일때는 front와 rear를 모두 변경해야한다

	else
	{
		pq->rear->link = newNode;
		pq->rear = newNode;
	}
	//이미 차있는 상태에서는 rear만 변경해주면 된다
}
//큐에 값을 집어넣는 상황을 위한 함수

Data dequeue(Queue* pq)
{
	Node* delNode;
	Data retData;
	//노드 삭제용, 리턴값용 데이터 할당 위치 지정

	if (empty(pq))
	{
		printf("큐가 비어있습니다!\n==========================\n");
	}
	//큐가 비어있는 상황에서 큐를 비우도록 요구할때 오류메시지 출력

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->link;
	//front가 다음 노드를 가리키도록 한다

	free(delNode);
	return retData;
	//노드를 삭제하여 불필요한 리소스 사용 방지
}
//큐에서 값을 빼내는 상황을 위한 함수

int main()
{
	//creates queue
	Queue q;
	Init(&q);

	//data input
	enqueue(&q, 10);
	//front rear 출력 내용이 들어갈 부분
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