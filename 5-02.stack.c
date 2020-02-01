#include<stdio.h>
#include<stdlib.h>//malloc�� ����ϱ� ���� ���
#define EMPTY 0 //EMPTY�� 0���� ����

//linkedlist�� �̿��� ���� => ���Ḯ��Ʈ�� �̿��� ����
typedef struct node {
	int data;
	struct node* link;//struct node������������ link���� 
}Stack;

//heap������ �����Ҵ��ϴ� �Լ�
Stack* get_node() {
	Stack* tmp;
	//heap������ Stack����ü ũ���� �ּҸ� �Ҵ��ϰ� �� �ּҸ� tmp�� ����
	tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = EMPTY; //����ü�� link�� EMPTY�� ����(�ƹ��ּҵ� ���� ���� ����)
	return tmp;
}

void push(Stack** top, int data) {
	//top : main�� top�� �ּҸ� ����־��
	//*top : main�� top�� ����Ű�� �ּҸ� �����ѿ�
	//**top : main�� top�� ����Ű�� �ּҷ� ���󰡺��� ���̴� ����ü
	//(**top).data == (*top)->data
	Stack* tmp = *top;//push�� tmp���� main�Լ��� top�� ����Ű�� �ּ� ����

	*top = get_node();//main�� top�� ����Ű�� �ּҸ� haep������ �ּҷ� �ٲ���(get_nodeȣ��)

	(*top)->data = data;
	(*top)->link = tmp;
	//main�� top�� ����Ű�� �ּ��� ����ü�� data������ �� data����
	//main�� top�� ����Ű�� �ּ��� ����ü�� link������ �� tmp����
}

int pop(Stack** top) {
	if ((*top) == EMPTY) {
		printf("Stack is Underflow\n");
		return -1;
	}
	Stack* tmp = (*top); //3000������ tmp���� ����
	*top = (*top)->link; //main�� top�� 2000������ ����Ű���� �մϴ�.
	int data = tmp->data; //3000������ �����͸� data�� ����
	free(tmp);//3000������ �������
	return data;
}
void main() {
	Stack* top = EMPTY;//Stack����ü������ tmp���� ���� �� �� ������ ����Ű���� �ʱ�ȭ
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top)); //underflow�߻� 
}