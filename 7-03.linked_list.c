#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define EMPTY 0

typedef struct node {
	int age, kor, eng, math;
	char name[20];
	char address[20];
	struct node* link;
}Linkedlist;

Linkedlist* GetNode() 
{
	Linkedlist* tmp;
	tmp = (Linkedlist*)malloc(sizeof(Linkedlist));
	tmp->link = EMPTY;
	return tmp;
}

void enroll(Linkedlist** head) {
	Linkedlist* tmp;
	//head : main�� head�� �ּ�
	//*head : main�� head�� ����Ű�� �ּ�
	tmp = *head;
	if (tmp == EMPTY) { //main�� head�� ����Ű�� �ּҰ� ���������
		*head = GetNode();//main�� head���� heap������ ���� �ּ�����
		printf("�л� �̸� �Է� : ");
		scanf("%s", (*head)->name);
		printf("�л� ���� �Է� : ");
		scanf("%d", &(*head)->age);
		printf("�л� �ּ� �Է� : ");
		scanf("%s", (*head)->address);
		printf("�л� ���� �Է� : ");
		scanf("%d", &(*head)->kor);
		printf("�л� ���� �Է� : ");
		scanf("%d", &(*head)->eng);
		printf("�л� ���� �Է� : ");
		scanf("%d", &(*head)->math);
		printf("�л� ���� �Է� �Ϸ�\n");
	}
	else
		enroll(&(*head)->link);//����Լ� ȣ��
}

void modify(Linkedlist** head, char* mname) {
	char mname2[20];
	char maddress[20];
	int menu, mage, cwhile = 1;

	if (*head == EMPTY) {
		printf("�����ϰ��� �ϴ� �л��� �������� �ʽ��ϴ�.\n");
	}
	//!strcmp((*head)->name, mname)
	else if (strcmp((*head)->name, mname) == 0) {
		while (cwhile) {
			search(head, (*head)->name);

			printf("\n\n������ �׸��� �����Ͻÿ�\n");
			printf("======================================\n");
			printf("1.�̸�\t2.����\t3.�ּ�\t4.����\t5.��������\n");
			printf("���� : ");
			scanf("%d", &menu);
			switch (menu)
			{
			case 1:
				printf("���� �̸� : %s\n", (*head)->name);
				printf("������ �̸� : ");
				scanf("%s", mname2);
				printf("======================================\n");
				printf("%s -> %s�� �̸� ���� �Ϸ�\n", (*head)->name, mname2);
				//strcpy(���纻,����) : ������ ���ڿ��� ���纻���� ����
				strcpy((*head)->name, mname2);
				break;
			case 2:
				printf("���� ���� : %d\n", (*head)->age);
				printf("������ ���� : ");
				scanf("%d", &mage);
				printf("======================================\n");
				printf("%d -> %d�� ���� ���� �Ϸ�\n", (*head)->age, mage);
				(*head)->age = mage;
				break;
			case 3:
				printf("���� �ּ� : %s\n", (*head)->address);
				printf("������ �ּ� : ");
				scanf("%s", maddress);
				printf("======================================\n");
				printf("%s -> %s�� �ּ� ���� �Ϸ�\n", (*head)->address, maddress);
				strcpy((*head)->address, maddress);
				break;
			case 4:
				printf("���� ����\n");
				printf("���� : %d ���� : %d ���� : %d\n", (*head)->kor, (*head)->eng, (*head)->math);
				printf("======================================\n");
				printf("������ ���� ���� : ");
				scanf("%d", &(*head)->kor);
				printf("������ ���� ���� : ");
				scanf("%d", &(*head)->eng);
				printf("������ ���� ���� : ");
				scanf("%d", &(*head)->math);
				break;
			case 5:
				//while���� ���������� cwhile�� 0�� ����
				cwhile = 0;
				break;
			default:
				printf("======================================\n");
				printf("�߸��� ��ȣ�� �Է��ϼ̽��ϴ�\n");
				break;
			}
			system("pause");
			system("cls");
		}
	}
	else
		modify(&(*head)->link, mname);
}

int del(Linkedlist** head, char* dname[20])
{
	Linkedlist* tmp = *head;
	if (tmp == EMPTY) {
		printf("�����ϰ��� �ϴ� �л��� �������� �ʽ��ϴ�.\n");
		return;
	}
	else if (!strcmp((*head)->name, dname)) {
		printf("�����Ǿ����ϴ�.\n");
		*head = tmp->link;
		free(tmp);
	}
	else
		del(&(*head)->link, dname);
}

int search(Linkedlist** head, char sname[20]) {
	if (*head == EMPTY) {
		printf("�˻��ϰ��� �ϴ� �л��� �������� �ʽ��ϴ�.\n");
	}
	//name, sname : �迭�� �����ּ�
	//name == sname => �ּҰ� ���İ� �������
	//strcmp(name,sname) => ������ 0, �ٸ��� 1, -1�� ��ȯ
	//!�� ����ָ� 0�� 1�� 1�� 0���� �˴ϴ�.
	else if (!strcmp((*head)->name, sname)) {
		int sum = (*head)->kor + (*head)->eng + (*head)->math;
		double avg = sum / 3.0;
		char grade;
		printf("�л��̸� : %s\n", (*head)->name);
		printf("�л����� : %d��\n", (*head)->age);
		printf("�л��ּ� : %s\n", (*head)->address);
		printf("�������� : %d��\n", (*head)->kor);
		printf("�������� : %d��\n", (*head)->eng);
		printf("�������� : %d��\n", (*head)->math);
		printf("�հ����� : %d��\n", sum);
		printf("������� : %.2f��\n", avg);
		if (avg > 90 && avg < 101)
			grade = 'A';
		else if (avg > 80 && avg < 91)
			grade = 'B';
		else if (avg > 70 && avg < 81)
			grade = 'C';
		else if (avg > 60 && avg < 71)
			grade = 'D';
		else
			grade = 'F';
		printf("�л���� : %c\n", grade);
	}
	else
		search(&(*head)->link, sname);
}


void print_list(Linkedlist** head) 
{
	Linkedlist* tmp = *head;//tmp�� *head�� ����
	printf("<<<=====information=====>>>\n\n");
	printf("%12s%12s%12s\n", "�л��̸�", "�л�����", "�л��ּ�");
	while (tmp != EMPTY) {//tmp�� �� ���� �ƴѰ��� ����Ű�� �ݺ�
		printf("%12s%12d%12s\n", tmp->name, tmp->age, tmp->address);
		tmp = tmp->link; //�����ּҷ� �Ѿ
	}
	printf("***��ü ����� �Ϸ��߽��ϴ�***\n");
}
//�˻�� ����Ʈ ����Ʈ �Լ�
void main() 
{
	Linkedlist* head = EMPTY;
	int number;

	char sname[20], dname[20], mname[20];

	puts("\n * linked list test * \n");

	while (1)
	{
		printf("********�޴� ���� ȭ���Դϴ�.*********\n");
		printf("======================================\n");
		printf("1. �л����(insert)\n");
		printf("2. �л��˻�(search)\n");
		printf("3. �л����(print_list)\n");
		printf("4. �л�����(modify)\n");
		printf("5. �л�����(del)\n");
		printf("======================================\n");
		printf(" ��ȣ�� �����ϼ���[����-> 0] : ");
		scanf("%d", &number);

		if (number == 0)
			return;

		switch (number)
		{
		case 1:
			printf("======================================\n");
			printf("1.�л���� �޴��Դϴ�.\n");
			printf("======================================\n");

			enroll(&head);

			printf("======================================\n");
			printf("������ �Է��� �Ϸ��߽��ϴ�.\n");
			break;

		case 2:
			printf("======================================\n");
			printf("2.�л��˻� �޴��Դϴ�.\n");
			printf("======================================\n");

			printf("�˻��ϰ��� �ϴ� �л� �̸��� �Է��ϼ��� : ");
			scanf("%s", sname);

			search(&head, sname);

			printf("======================================\n");
			printf("������ �˻��� ���������� �Ϸ��߽��ϴ�.\n");
			break;

		case 3:
			printf("======================================\n");
			printf("3.�л���� �޴��Դϴ�.\n");
			printf("======================================\n");

			print_list(&head);

			break;

		case 4:
			printf("======================================\n");
			printf("4.�л����� �޴��Դϴ�.\n");
			printf("======================================\n");

			printf("�����ϰ��� �ϴ� �л� �̸��� �Է��ϼ��� : ");
			scanf("%s", mname);

			modify(&head, mname);

			printf("======================================\n");
			printf("������ ������ ���������� �Ϸ��߽��ϴ�.\n");
			break;

		case 5:
			printf("======================================\n");
			printf("5.�л����� �޴��Դϴ�.\n");
			printf("======================================\n");

			printf("�����ϰ��� �ϴ� �л� �̸��� �Է��ϼ��� : ");
			scanf("%s", dname);

			del(&head, dname);

			printf("======================================\n");
			printf("������ ������ ���������� �Ϸ��߽��ϴ�.\n");
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
