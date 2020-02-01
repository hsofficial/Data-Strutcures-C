#include<stdio.h>
#include<stdlib.h>

typedef int Treedata;

typedef struct treenode
{
	Treedata data;
	struct treenode* left;
	struct treenode* right;
}treenode;

treenode* Maketreenode(void)
{
	treenode* nod = (treenode*)malloc(sizeof(treenode));
	nod->left = NULL;
	nod->right = NULL;
	return nod;
}

Treedata Getdata(treenode* bt)
{
	return bt->data;
}

void Setdata(treenode* bt, Treedata data)
{
	bt->data = data;
}

treenode* Getleftsubtree(treenode* bt)
{
	return bt->left;
}

treenode* Getrightsubtree(treenode* bt)
{
	return bt->right;
}

void Makeleftsubtree(treenode* main, treenode* sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void Makerightsubtree(treenode* main, treenode* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void DeleteTree(treenode* bt)
{
	if (bt == NULL)
		return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);

	printf("%d ����\n", bt->data);

	free(bt);
}

void InorderTraverse(treenode* bt) //���� Ʈ�� ��ü�� ���� ��ȸ�ϴ� �Լ�
{
	if (bt == NULL) //bt�� NULL�̸� ��� Ż��
		return;

	InorderTraverse(bt->left);       //1�ܰ� ���� ���� Ʈ���� ��ȸ
	printf("%d\n", bt->data);        //2�ܰ� ��Ʈ ��� �湮
	InorderTraverse(bt->right);      //3�ܰ� ������ ���� Ʈ���� ��ȸ
}
void PreorderTraverse(treenode* bt)   //���� ��ȸ �Լ�
{
	if (bt == NULL)
		return;

	printf("%d\n", bt->data);    //���� ��ȸ�̹Ƿ� ��Ʈ ��� ���� �湮
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}
void PostorderTraverse(treenode* bt)  //���� ��ȸ �Լ�
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d\n", bt->data);    //���� ��ȸ�̹Ƿ� ��Ʈ ��� ���� �湮
}

int main(void)
{
	treenode* bt1 = Maketreenode();
	treenode* bt2 = Maketreenode();
	treenode* bt3 = Maketreenode();
	treenode* bt4 = Maketreenode();
	treenode* bt5 = Maketreenode();

	Setdata(bt1, 1);
	Setdata(bt2, 2);
	Setdata(bt3, 3);
	Setdata(bt4, 4);
	Setdata(bt5, 5);

	Makeleftsubtree(bt1, bt2);
	Makerightsubtree(bt1, bt3);
	Makeleftsubtree(bt2, bt4);
	Makerightsubtree(bt3, bt5);

	InorderTraverse(bt1);
	printf("======================================\n");

	PostorderTraverse(bt1);
	printf("======================================\n");

	PreorderTraverse(bt1);
	printf("======================================\n");

	DeleteTree(bt1);

	return 0;
}