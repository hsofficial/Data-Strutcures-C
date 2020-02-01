#include<stdio.h>
#include<stdlib.h>

//#define TRUE 1
//#define FALSE 0
#define LIST_LEN 5

typedef int LData;
//������ ����� �ڷ��� ������ ���� typedef ����

typedef struct ArrayList
{
	LData arr[LIST_LEN];	//����Ʈ ����ҷ� �迭 ���
	int data_num;	//����Ǵ� �������� ��
	int position;	//������ ������ġ ���
}ArrayList;
//�迭��� ����Ʈ ���� ����ü

typedef ArrayList List;
//����Ʈ�� ������ �����ϰ� �ϱ� ���� typedef ����

void Init(List * plist)
{
	plist->data_num = 0;
}
//�ʱ�ȭ�� ����Ʈ�� �ּҰ��� ���ڷ� �����Ѵ�

void Insert(List* plist, LData data)
{
	if (plist->data_num >= LIST_LEN)
	{
		printf("������ ������ �����ϴ�\n");
		return;
	}

	plist->arr[plist->data_num] = data; //������ ����
	plist->data_num++; //����� �������� ���� ����
}
//����Ʈ�� �����͸� �����ϸ� �Ű����� data�� ����� ���� �����Ѵ�

/*

int First(List* plist, LData* data)
{
	if (plist->data_num == 0)
		return FALSE;
	//����� �����Ͱ� �ϳ��� ���ٸ� f�� ��ȯ�Ѵ�

	(plist->position) = 0;	//���� ��ġ�� �ʱ�ȭ
	*data = plist->arr[0];	//data�� ����Ű�� ������ ������ ����
	return TRUE;
}
//ù��° ������ ���� �Լ�

int Next(List* plist, LData* data)
{
	if(plist->position >= (plist->data_num) - 1)
		return FALSE;
	//���̻� ������ �����Ͱ� ���ٸ� f�� ��ȯ�Ѵ�

	(plist->position)++;	//������ġ�� 1�� ������Ų��
	*data = plist->arr[plist->position];
	//���� ��ȯ�� �Ű������� �����ϸ� �Լ��� ��ȯ�� �������θ� ��ȯ�Ѵ�

	return TRUE;
}
//���� ������ ���� �Լ�

*/

int Del(List* plist, int rdata)
{
	int head = 0;
	int rcount = 0;
	while (head < plist->data_num) {
		if (plist->arr[head] == rdata) {
			for (; head < plist->data_num - 1; head++)
				plist->arr[head] = plist->arr[head + 1];

			(plist->data_num)--;
			rcount++;
			break;
		}
		head++;
	}
	if (rcount == 0) {
		printf("ã�� �����Ͱ� �����ϴ�.\n");
		return;
	}
}
//�����͸� �����Ѵ�. ������ �����ʹ� ��ȯ�ȴ�.
//������ ��ȯ �����͸� �����ϹǷ� ���ӵ� �ݺ� ȣ���� ���� �ʴ´�.

void PrintAll(List* plist)
{
	if (plist->data_num == 0)
		printf("�����Ͱ� �����ϴ�.\n");

	else
	{
		int head = 0;

		while (head < plist->data_num)
		{
			printf("%d ", plist->arr[head]);
			head++;
		}
	}
}
//�Լ��� ȣ���ϴ� ������ ���Ḯ��Ʈ�� ����� ��� ���� ����Ѵ�

int main()
{
	/*** ArrayArrayList�� ���� �� �ʱ�ȭ ***/
	List list;
	int data;
	Init(&list);

	/*** 5���� ������ ���� ***/
	Insert(&list, 11);
	Insert(&list, 11);
	Insert(&list, 22);
	Insert(&list, 33);
	Insert(&list, 33);


	/*** ����� �������� ��ü ��� ***/
	printf("���� �������� ��: %d \n", list.data_num);
	PrintAll(&list);
	printf("\n\n");

	/*** ���� Ž���Ͽ� ���� ***/
	printf("������ �����͸� �Է� : ");
	scanf("%d", &data);
	Del(&list, data);
	printf("\n\n");

	/*** ���� �� ����� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", list.data_num);
	PrintAll(&list);


}