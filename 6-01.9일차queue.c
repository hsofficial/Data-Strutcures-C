#include<stdio.h>
#include<stdlib.h>

#define LEN 4	//ť�� ���̸� 4�� �����Ѵ�

typedef int Data;

typedef struct Queue
{
	int front;      //�������� ���� �κ�
	int rear;       //�������� �� �κ�
	Data queArr[LEN + 1];
}Queue;

typedef Queue Queue;

void init(Queue* p_q)
{
	p_q->front = 0;
	p_q->rear = 0;
}
/*
ť�� �ʱ�ȭ�� ����.ť ���� �� ���� ���� ȣ��Ǿ�� �ϴ� �Լ�
ť�� ������� front�� rear�� ���� ��ġ�� ����Ű���� �����Ѵ�
*/

int index(int i)
{
	if (i == LEN)
		return 0;
	else
		return i + 1;
}
/*
ť���꿡 ���� front�� rear�� �̵��Ҷ� �̵��ؾ� �� ��ġ�� �˷��ִ� �Լ�
�Ű������� front�� rear�� �ε�����ȣ�� �����ϰ�
�ε��� ��ȣ�� �迭�� ������ �ε����̸� ù �ε���(0)�� ��ȯ
�ƴϸ� �ε�����ȣ�� 1 ���� ���Ѽ� ��ȯ�ϴ� �Լ�
*/


void enqueue(Queue* p_q, int data)
{
	if (index(p_q->rear) == p_q->front)    //ť�� �� á�ٸ�
	{
		printf("ť�� ���� á���ϴ�\n===============\n");
	}

	/*
	p_q->rear = index(p_q->rear);  //rear�� �� ĭ �̵�
	p_q->queArr[p_q->rear] = data;      //rear�� ����Ű�� ���� ������ ����
	*/
	p_q->queArr[p_q->rear = index(p_q->rear)] = data;
}
//ť�� �Ű����� data�� ����

int dequeue(Queue* p_q)
{
	if (index(p_q->rear) == p_q->front)    //ť�� �� á�ٸ�
	{
		printf("ť�� ������ϴ�\n===============\n");
	}

	p_q->front = index(p_q->front);
	return p_q->queArr[p_q->front];
	//return p_q->queArr[p_q->front = index(p_q->front)];
}
/*
��������� ���� �ռ� �����͸� ��ȯ �� ����
�� �Լ��� ȣ���� ���ؼ� �����Ͱ� �ϳ� �̻� �����ؾ� ��
*/

int peek(Queue* p_q)
{
	if (index(p_q->rear) == p_q->front)    //ť�� �� á�ٸ�
	{
		printf("ť�� ������ϴ�\n===============\n");
	}
	return p_q->queArr[index(p_q->front)];
}
//��������� ���� �ռ� �����͸� ��ȯ������ �������� �ʴ´�

/*
	front�� �� ĭ ������ ��ġ�� ���Ұ��� ��ȯ�������
	front�� rear�� ���� ��ġ�� ������ �� �� �����̹Ƿ�
	����ó���� ����� �Ѵ�.
	dequeue�� �޸� front�� ��ġ�� ������ ��ĭ �̵��ϴ� ���� �ƴ�
	��ĭ �̵��� �����͸� ���
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