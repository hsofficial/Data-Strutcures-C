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
		printf("%s 님 : %d 세\n ", (*root)->name, (*root)->age);

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

		printf("%s 님 : %d 세\n ", (*root)->name, (*root)->age);

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

		printf("%s 님 : %d 세\n ", (*root)->name, (*root)->age);
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
		printf("********메뉴 선택 화면입니다.*********\n");
		printf("======================================\n");
		printf("1. 입력(insert)\n");
		printf("2. inorder\n");
		printf("3. postorder\n");
		printf("4. preorder\n");
		printf("======================================\n");
		printf(" 번호를 선택하세요[종료-> 0] : ");
		scanf("%d", &number);

		if (number == 0)
			return;

		switch (number)
		{
		case 1:
			printf("======================================\n");
			printf("1.학생등록 메뉴입니다.\n");
			printf("======================================\n");

			printf("입력하고자 하는 자의 이름을 입력하세요 : ");
			scanf("%s", iname);

			printf("나이를 입력하세요 : ");
			scanf("%d", &iage);

			insert(&root, iage, iname);

			printf("======================================\n");
			printf("데이터 입력을 완료했습니다.\n");
			break;

		case 2:
			printf("======================================\n");
			printf("2.inorder 메뉴입니다.\n");
			printf("======================================\n");

			inorder(&root);

			printf("======================================\n");
			printf("데이터 출력을 정상적으로 완료했습니다.\n");
			break;

		case 3:
			printf("======================================\n");
			printf("3.postorder 메뉴입니다.\n");
			printf("======================================\n");

			postorder(&root);

			printf("======================================\n");
			printf("데이터 출력을 정상적으로 완료했습니다.\n");

			break;

		case 4:
			printf("======================================\n");
			printf("4.preorder 메뉴입니다.\n");
			printf("======================================\n");

			preorder(&root);

			printf("======================================\n");
			printf("데이터 출력을 정상적으로 완료했습니다.\n");

			break;

		
		default:
			printf("======================================\n");
			printf(" 경고! %d 는 메뉴에 없는 번호입니다. \n", number);

		}
		system("pause");
		system("cls");
	}

	return 0;

}