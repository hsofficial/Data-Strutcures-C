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

void push(Stack** top, int data)
{
	printf("======================================\n");
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

	printf("push ����� �� �����߽��ϴ�.\n");
}

int pop(Stack**top)
{
	if ((*top) == EMPTY)
	{
		printf("���ÿ� �׿��ִ� ��� �Լ��� ���������ϴ�.\n Underflow�� �߻��մϴ�.\n");
		return -1;
	}

	Stack* tmp = (*top); //3000������ tmp���� ����
	*top = (*top)->link; //main�� top�� 2000������ ����Ű���� �մϴ�.
	int data = tmp->data; //3000������ �����͸� data�� ����
	free(tmp);//3000������ �������
	return data;

}

void print_all(Stack** top)
{
	printf("print_all : ������ ��ü �����͸� Ȯ���մϴ� \n");
	//�ݺ��� �̿��ؼ� ���� ������ ���� ��带 �о�� ����Ʈ�ϵ��� �����Ѵ�
	int num;
	Stack* tmp;
	tmp = *top;
	while (tmp != EMPTY) {
		printf("������ : %d \n", tmp->data);
		tmp = tmp->link;
	}
}


void main()
{
	Stack* top = EMPTY;
	//Stack����ü������ tmp���� ���� �� �� ������ ����Ű���� �ʱ�ȭ
	
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
		printf(" ��ȣ�� �����ϼ���[����-> 0] : ");
		scanf("%d", &number);

		if (number == 0)
			return;

		switch (number)
		{
		case 1:
			printf("======================================\n");
			printf("push �ϰ��� �ϴ� int�� ������ �Է� : ");
			scanf("%d", &push_tmp);
			push(&top, push_tmp);
			break;

		case 2:
			printf("======================================\n");
			printf("pop �Լ��� < %d > �����͸� ���½��ϴ�.\n", pop(&top));
			break;

		case 3:
			printf("======================================\n");
			print_all(&top);
			break;

		default:
			printf(" %d �� �޴��� ���� ��ȣ�Դϴ�. \n", number);

		}

	}

	return 0;
}
