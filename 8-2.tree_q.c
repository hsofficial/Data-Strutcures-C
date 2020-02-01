#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

#define EMPTY 0

typedef struct node Tree;
struct node 
{
	int age;
	char name[20];
	Tree* left;
	Tree* right;
};

Tree* GetNode() 
{
	Tree* tmp;
	tmp = (Tree*)malloc(sizeof(Tree));
	tmp->left = EMPTY;
	tmp->right = EMPTY;
	return tmp;
}

void insert(Tree** root, int age, char *name)
{
	if (*root == EMPTY)
	{
		*root = GetNode();
		(*root)->age = age;
		strcpy((*root)->name, name);
		return;
	}

	else if ((*root)->age > age)
	{
		insert(&(*root)->left, age, name);
	}

	else if ((*root)->age < age)
	{
		insert(&(*root)->right, age, name);
	}

}

void preorder(Tree** root)
{
		printf("%s �� : %d ��\n ", (*root)->name, (*root)->age);

		if ((*root)->left != EMPTY)
		{
			preorder(&(*root)->left);
		}

		if ((*root)->right != EMPTY)
		{
			preorder(&(*root)->right);
		}
	}

void inorder(Tree** root)
{

		if ((*root)->left != EMPTY)
		{
			inorder(&(*root)->left);
		}

		printf("%s �� : %d ��\n ", (*root)->name, (*root)->age);

		if ((*root)->right != EMPTY)
		{
			inorder(&(*root)->right);
		}

}

void postorder(Tree** root) 
	{
		if ((*root)->left != EMPTY)
		{
			postorder(&(*root)->left);
		}

		if ((*root)->right != EMPTY)
		{
			postorder(&(*root)->right);
		}

		printf("%s �� : %d ��\n ", (*root)->name, (*root)->age);
	}

Tree* minTree(Tree* root) {
	if (root->left != EMPTY) {
		return minTree(root->left);
	}
	else {
		return root;
	}
}

void del(Tree * *root, int age) {

	if ((*root)->age > age)
		{
			del(&(*root)->left, age);
		}

	else if ((*root)->age < age)
		{
			del(&(*root)->right, age);
		}

	else if ((*root)->age == age)
		{
			Tree* tmp = *root;

		if (tmp->left != EMPTY && tmp->right != EMPTY)
			{
				Tree* min = minTree(tmp->right);
				(*root)->age = min->age;
				strcpy((*root)->name, min->name);
				del(&tmp->right, min->age, min->name);
			}

		else
			{
				if (tmp->left == EMPTY && tmp->right == EMPTY)
					*root = EMPTY;
				if (tmp->left != EMPTY)
					*root = tmp->left;
				if (tmp->right != EMPTY)
					*root = tmp->right;

				free(tmp);
			}
		}

	}

void main()
{
	Tree* root = EMPTY;

	int number;
	int iage;
	char iname[20];

	puts("\n * tree test * \n");

	while (1)
	{
		printf("********�޴� ���� ȭ���Դϴ�.*********\n");
		printf("======================================\n");
		printf("1. �Է�(insert)\n");
		printf("2. inorder\n");
		printf("3. postorder\n");
		printf("4. preorder\n");
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

			printf("�Է��ϰ��� �ϴ� ���� �̸��� �Է��ϼ��� : ");
			scanf("%s", iname);

			printf("���̸� �Է��ϼ��� : ");
			scanf("%d", &iage);

			insert(&root, iage, iname);

			printf("======================================\n");
			printf("������ �Է��� �Ϸ��߽��ϴ�.\n");
			break;

		case 2:
			printf("======================================\n");
			printf("2.inorder �޴��Դϴ�.\n");
			printf("======================================\n");

			inorder(&root);

			printf("======================================\n");
			printf("������ ����� ���������� �Ϸ��߽��ϴ�.\n");
			break;

		case 3:
			printf("======================================\n");
			printf("3.postorder �޴��Դϴ�.\n");
			printf("======================================\n");

			postorder(&root);

			printf("======================================\n");
			printf("������ ����� ���������� �Ϸ��߽��ϴ�.\n");

			break;

		case 4:
			printf("======================================\n");
			printf("4.preorder �޴��Դϴ�.\n");
			printf("======================================\n");

			preorder(&root);

			printf("======================================\n");
			printf("������ ����� ���������� �Ϸ��߽��ϴ�.\n");

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