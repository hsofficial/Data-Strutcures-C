#include<stdio.h>
#include<stdlib.h>

#define LEN 4	//큐의 길이를 4로 정의한다

typedef int Data;

typedef struct Queue
{
	int front;      //데이터의 시작 부분
	int rear;       //데이터의 끝 부분
	Data queArr[LEN + 1];
}Queue;

typedef Queue Queue;

void init(Queue* p_q)
{
	p_q->front = 0;
	p_q->rear = 0;
}
/*
큐의 초기화를 진행.큐 생성 후 제일 먼저 호출되어야 하는 함수
큐가 비었을때 front와 rear은 동일 위치를 가리키도록 설정한다
*/

int index(int i)
{
	if (i == LEN)
		return 0;
	else
		return i + 1;
}
/*
큐연산에 의해 front와 rear가 이동할때 이동해야 할 위치를 알려주는 함수
매개변수로 front나 rear의 인덱스번호를 저장하고
인덱스 번호가 배열의 마지막 인덱스이면 첫 인덱스(0)을 반환
아니면 인덱스번호를 1 증가 시켜서 반환하는 함수
*/


void enqueue(Queue* p_q, int data)
{
	if (index(p_q->rear) == p_q->front)    //큐가 꽉 찼다면
	{
		printf("큐가 가득 찼습니다\n===============\n");
	}

	/*
	p_q->rear = index(p_q->rear);  //rear을 한 칸 이동
	p_q->queArr[p_q->rear] = data;      //rear이 가리키는 곳에 데이터 저장
	*/
	p_q->queArr[p_q->rear = index(p_q->rear)] = data;
}
//큐에 매개변수 data를 저장

int dequeue(Queue* p_q)
{
	if (index(p_q->rear) == p_q->front)    //큐가 꽉 찼다면
	{
		printf("큐가 비었습니다\n===============\n");
	}

	p_q->front = index(p_q->front);
	return p_q->queArr[p_q->front];
	//return p_q->queArr[p_q->front = index(p_q->front)];
}
/*
저장순서가 가장 앞선 데이터를 반환 및 삭제
본 함수의 호출을 위해서 데이터가 하나 이상 존재해야 함
*/

int peek(Queue* p_q)
{
	if (index(p_q->rear) == p_q->front)    //큐가 꽉 찼다면
	{
		printf("큐가 비었습니다\n===============\n");
	}
	return p_q->queArr[index(p_q->front)];
}
//저장순서가 가장 앞선 데이터를 반환하지만 삭제하지 않는다

/*
	front가 한 칸 전진한 위치의 원소값을 반환시켜줘요
	front와 rear가 같은 위치에 있으면 텅 빈 상태이므로
	예외처리를 해줘야 한다.
	dequeue와 달리 front의 위치가 실제로 한칸 이동하는 것이 아닌
	한칸 이동한 데이터만 출력
*/

int main()
{
	//creates queue
	Queue q;
	init(&q);

	//data input
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);

	//data output > peek and dequeue
	printf("peek : %d\n===============\n", peek(&q));

	printf("dequeue : %d\n", dequeue(&q));
	printf("dequeue : %d\n", dequeue(&q));
	printf("dequeue : %d\n", dequeue(&q));
	printf("dequeue : %d\n", dequeue(&q));
	printf("===============\n");
	return 0;
}