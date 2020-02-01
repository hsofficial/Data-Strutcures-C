#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node* next;
	int data;

}node;

typedef node* node_pointer;

typedef struct list 
{
	int count;
	node_pointer head;
}list;

void init(list* list_pointer)
{
	list_pointer->count = 0;
	list_pointer->head = NULL;
}
//���� �Լ����� list�� ����� �� �ּҸ� init()�� �Ѱ��ش�
//count�� head�� �ʱ�ȭ

void insert(list* list_pointer, int data)
{
	printf("insert �۾��� �����մϴ�.\n");
	printf("input data is %d.\n", data);
	printf("-----------------------------------------------\n");

	node_pointer new_nptr = (node*)malloc(sizeof(node));
	new_nptr->data = data;
	//new_nptr ��������Ϳ� node �����ŭ�� �޸𸮸� �����Ҵ�
	//data������ ����

	if (list_pointer == NULL) {
		new_nptr->next = list_pointer->head;
		list_pointer->head = new_nptr;
		return;
	}
	else {
		new_nptr->next = list_pointer->head;
		list_pointer->head = new_nptr;
	}

	list_pointer->count++;
	//���� ��ġ �����ϸ� ������ �� ����Ʈ�� ī���͸� 1 ����
}
//������Լ��� ����
//������ head���� EMPTY�϶� �� �ƴҶ��� ������ ����
//head���� EMPTY�϶� �����Ҵ�� �ּҸ� ��ȯ�޾� �־��ְ� return
//�ƴ� �ÿ��� head�� ����Ű�� �ִ� ����ü�� link�� �ּҷ� ����Լ� ȣ��

//������Լ� ���� ����
//������ head���� EMPTY�϶� �� �ƴҶ��� ������ ����
//�ƴҽÿ��� ������ head���� ���� link �ȿ� �ִ� ���� EMPTY�� ���� �˻� �� 
//ã���� �� �� �ȿ� �����Ҵ�� �ּҸ� �־���



void add(list* list_pointer, int data, int pos)
{
	printf("add �۾��� �����մϴ�.\n");
	printf("input data is %d, input position is %d.\n", data, pos);
	printf("-----------------------------------------------\n");

	if (pos<1 || pos>(list_pointer->count) + 1)
	{
		printf("��ġ���� �������� �ʽ��ϴ�\n");
		return;
	}
	//position ���� �������� üũ

	node_pointer new_nptr = (node*)malloc(sizeof(node));
	new_nptr->data = data;
	//new_nptr ��������Ϳ� node �����ŭ�� �޸𸮸� �����Ҵ�
	//data������ ����

	if (pos == 1)
	{
		new_nptr->next = list_pointer->head;
		list_pointer->head = new_nptr;
	}
	//pos==1�϶� head �����Ͱ� �ٲ��� ��

	else
	{
		node_pointer tmp = list_pointer->head;
		int i;

		for ( i = 1; i < pos - 1; i++)
		{
			tmp = tmp->next;
		}

		new_nptr->next = tmp->next;
		tmp->next = new_nptr;
	}
	//pos�� 1�� �ƴҶ�
	//head ������ ���� tmp�� ����
	//for���� �̿��� �ǵ��� ��ġ�� �����Ҷ����� next�� Ž��

	list_pointer->count++;
	//���� ��ġ �����ϸ� ������ �� ����Ʈ�� ī���͸� 1 ����
}
//��� ���� �Լ�. ����Ʈ�� ������ ������ ��, ��ġ�� �μ��� �޴´�.

void delete(list* list_pointer, int pos) 
{
	printf("delete �۾��� �����մϴ�.\n");
	printf("input position is %d.\n", pos);
	printf("-----------------------------------------------\n");
	if (pos<1 || pos>(list_pointer->count))
	{
		printf("��ġ���� �������� �ʽ��ϴ�\n");
		return;
	}
	//position ���� �������� üũ
	//������ ��� �� �ڿ��� ���� ����
	//������ �����ϴ� ������ position�� �޾ƾ� �ϴ� ���� �Լ��ʹ� ������ 1 ����

	node_pointer tmp = list_pointer->head;
	//head ������ ���� tmp�� ����

	if (pos == 1)
	{
		list_pointer->head = tmp->next;
		free(tmp);
	}
	//pos == 1�϶� head ��� �ٲ��ش�

	else
	{
		int i;
		for (i = 1; i < pos; i++)
		{
			tmp = tmp->next;
		}
		node_pointer tmp2 = tmp->next;
		tmp->next = tmp2->next;
		free(tmp2);
	}
	//������ ����� �� ��带 tmp
	//�� ���� ��带 tmp2
	//tmp2 ���� ��尡 tmp ���� ��尡 �ǵ��� ��

	list_pointer->count--;
}
//���� �Լ�. ����Ʈ�� �����ͺ����� ��ġ�� �μ��� �޴´�.

void modify(list* list_pointer, int data, int pos)
{
	printf("insert �۾��� �����մϴ�.\n");
	printf("input data is %d, input position is %d.\n",data,pos);
	printf("-----------------------------------------------\n");
	if (pos<1 || pos>(list_pointer->count))
	{
		printf("��ġ���� �������� �ʽ��ϴ�\n");
		return;
	}
	//position ���� �������� üũ

	node_pointer tmp = list_pointer->head;
	//head ������ ���� tmp�� ����

	int i;
	for (i = 1; i < pos; i++)
	{
		tmp = tmp->next;
	}

	tmp->data = data;
}
//���� �Լ�. ����Ʈ�� ������ ������ ��, ��ġ�� �μ��� �޴´�.
//�ش� ��ġ�� ��常 ã�Ƽ� ���� �ٲ��ָ� �ȴ�.

void print_list(list* list_pointer) {
	node_pointer tmp = list_pointer->head;
	printf("List : ");
	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	printf("-----------------------------------------------\n");
	printf("Total: %d value(s)\n", list_pointer->count);
	printf("===============================================\n");
}
//�˻�� ����Ʈ ����Ʈ �Լ�

int main() {
	printf("===============================================\n");
	list* mylist = (list*)malloc(sizeof(list));
	init(mylist);

	insert(mylist, 3);
	insert(mylist, 4);
	insert(mylist, 5);
	print_list(mylist);

	add(mylist, 1, 1);
	print_list(mylist);
	add(mylist, 2, 2);
	print_list(mylist);
	add(mylist, 3, 3);
	print_list(mylist);
	add(mylist, 4, 4);
	print_list(mylist);
	add(mylist, 5, 5);
	print_list(mylist);
	add(mylist, 6, 6);
	print_list(mylist);
	add(mylist, 7, 7);


	print_list(mylist);

	delete(mylist, 3);
	print_list(mylist);
	delete(mylist, 5);

	print_list(mylist);

	modify(mylist, 100, 1);
	print_list(mylist);

	modify(mylist, 101, 2);

	print_list(mylist);

	return 0;
}