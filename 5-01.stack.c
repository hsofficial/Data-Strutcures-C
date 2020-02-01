#include<stdio.h>
#include<stdlib.h>

//������ũ https://new93helloworld.tistory.com/83

//������� ����
#define MAX 4

typedef struct node {
	int arr[MAX]; //�ִ� ���̸�ŭ �����Ҵ�
	int top; // stack�� ���� ������ ������ ��ġ
}Stack; // ��Ī�� Stack

//����ü �����ͺ����� �Ű������� �����ϴ� ����
//main�� �ƴ� �Լ����� main�� ���� �����ϱ� ����
void init(Stack* p_stack)// init�� �ʱ�ȭ �ϴ� �Լ�
{
	p_stack->top = -1; //�����͸� ���� ��ġ�� -1�� �ʱ�ȭ
}

//p_stack : �����ͺ��� 4byte¥�� �ּ������ϴ� ����

//������ ������ ���� �Լ�
void push(Stack *p_stack, int data) {
	//���� stack�� �ε����� �ִ����-1 �ε������� ������ return
	if (p_stack->top >= (MAX - 1)) {
		printf("Stack�� ������ ���̻� ������ �� �����ϴ�\n");
		return; //push�Լ� ����
	}

	//p_stack->top++;//-1���� �����ϹǷ� �ϳ� ���� => �����͸� ���� �ε�����ġ
	//�ּҸ� ���󰡺��� ����ü�� �ֳ� ����ü�� �迭�� top�ε����� �����͸� ����
	//p_stack->arr[p_stack->top] = data;
	p_stack->arr[++(p_stack->top)] = data;

}

//������ ������ ���� �Լ�
int pop(Stack *p_stack) {

	//top�� -1(�ʱⰪ)���� �������� ��ȯ�� �����Ͱ� ���ٴ� �ǹ�
	if (p_stack->top == -1) {
		printf("������ ����־� ��ȯ�� ���� �����ϴ�\n");
		return -1;
	}

	//���� top�� ����Ű�� �ε�����ȣ�� �����͸� ��ȯ�ϰ� top�� ��ĭ ���ҽ��ѿ�
	return p_stack->arr[(p_stack->top)--];
}

//top �ε����� �����͸� Ȯ���� �� ����ϴ� �Լ�
int peek(Stack *p_stack) {

	//�ڷᰡ ���ٸ� ������� ���� -1�� ��ȯ
	if (p_stack->top == -1) {
		printf("������ ����־� Ȯ���� �����Ͱ� �����ϴ�\n");
		return -1;
	}

	//TOP�� ����Ű�� �ִ� ���� ���
	return p_stack->arr[p_stack->top];
}


void main() {
	Stack stack;	//Stack����ü ����
	//�� �ּҸ� �Ѱ�����? => stack�� main�Լ��� �־�� �׷��� �ٸ��Լ����� stack�� arr[]�� ���� ä���ְ� ������ ����;�
	init(&stack);	//stack�� �ּҸ� ���ڷ� �Ѱ���
	//�������� ->������ ������ ����
	push(&stack, 5);//stack�� �ּҿ� ������ �����͸� �Ѱ���
	push(&stack, 2);
	push(&stack, 7);
	push(&stack, 8);
	push(&stack, 10); //stack overflow�߻� (�迭�� ����)

	printf("peek : %d\n", peek(&stack));

	int n;
	n = pop(&stack); //pop�Լ� ȣ��(�����͹�ȯ)
	printf("pop : %d\n", n);
	n = pop(&stack); //pop�Լ� ȣ��(�����͹�ȯ)
	printf("pop : %d\n", n);
	n = pop(&stack); //pop�Լ� ȣ��(�����͹�ȯ)
	printf("pop : %d\n", n);
	n = pop(&stack); //pop�Լ� ȣ��(�����͹�ȯ)
	printf("pop : %d\n", n);
	n = pop(&stack); //underflow�߻� (�迭�� �����Ͱ� ����)
	printf("pop : %d\n", n);
}