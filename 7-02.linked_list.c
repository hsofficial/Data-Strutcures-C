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
//메인 함수에서 list를 만들고 그 주소를 init()에 넘겨준다
//count와 head를 초기화

void insert(list* list_pointer, int data)
{
	printf("insert 작업을 수행합니다.\n");
	printf("input data is %d.\n", data);
	printf("-----------------------------------------------\n");

	node_pointer new_nptr = (node*)malloc(sizeof(node));
	new_nptr->data = data;
	//new_nptr 노드포인터에 node 사이즈만큼의 메모리를 동적할당
	//data변수를 설정

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
	//적정 위치 도달하면 삽입한 후 리스트의 카운터를 1 증가
}
//※재귀함수로 구성
//메인의 head값이 EMPTY일때 와 아닐때로 나눠서 구성
//head값이 EMPTY일때 동적할당된 주소를 반환받아 넣어주고 return
//아닐 시에는 head가 가르키고 있는 구조체의 link의 주소로 재귀함수 호출

//※재귀함수 없이 구현
//메인의 head값이 EMPTY일때 와 아닐때로 나눠서 구성
//아닐시에는 메인의 head값을 통해 link 안에 있는 값이 EMPTY인 것을 검색 후 
//찾았을 시 그 안에 동적할당된 주소를 넣어줌



void add(list* list_pointer, int data, int pos)
{
	printf("add 작업을 수행합니다.\n");
	printf("input data is %d, input position is %d.\n", data, pos);
	printf("-----------------------------------------------\n");

	if (pos<1 || pos>(list_pointer->count) + 1)
	{
		printf("위치값이 적절하지 않습니다\n");
		return;
	}
	//position 값이 적절한지 체크

	node_pointer new_nptr = (node*)malloc(sizeof(node));
	new_nptr->data = data;
	//new_nptr 노드포인터에 node 사이즈만큼의 메모리를 동적할당
	//data변수를 설정

	if (pos == 1)
	{
		new_nptr->next = list_pointer->head;
		list_pointer->head = new_nptr;
	}
	//pos==1일때 head 포인터가 바뀌어야 함

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
	//pos가 1이 아닐때
	//head 포인터 값을 tmp에 복사
	//for문을 이용해 의도한 위치에 도달할때까지 next로 탐색

	list_pointer->count++;
	//적정 위치 도달하면 삽입한 후 리스트의 카운터를 1 증가
}
//노드 삽입 함수. 리스트형 포인터 변수와 값, 위치를 인수로 받는다.

void delete(list* list_pointer, int pos) 
{
	printf("delete 작업을 수행합니다.\n");
	printf("input position is %d.\n", pos);
	printf("-----------------------------------------------\n");
	if (pos<1 || pos>(list_pointer->count))
	{
		printf("위치값이 적절하지 않습니다\n");
		return;
	}
	//position 값이 적절한지 체크
	//삽입의 경우 맨 뒤에도 삽입 가능
	//기존에 존재하는 노드들의 position만 받아야 하는 삭제 함수와는 범위가 1 차이

	node_pointer tmp = list_pointer->head;
	//head 포인터 값을 tmp에 복사

	if (pos == 1)
	{
		list_pointer->head = tmp->next;
		free(tmp);
	}
	//pos == 1일때 head 노드 바꿔준다

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
	//삭제될 노드의 앞 노드를 tmp
	//그 다음 노드를 tmp2
	//tmp2 다음 노드가 tmp 다음 노드가 되도록 함

	list_pointer->count--;
}
//삭제 함수. 리스트형 포인터변수와 위치를 인수로 받는다.

void modify(list* list_pointer, int data, int pos)
{
	printf("insert 작업을 수행합니다.\n");
	printf("input data is %d, input position is %d.\n",data,pos);
	printf("-----------------------------------------------\n");
	if (pos<1 || pos>(list_pointer->count))
	{
		printf("위치값이 적절하지 않습니다\n");
		return;
	}
	//position 값이 적절한지 체크

	node_pointer tmp = list_pointer->head;
	//head 포인터 값을 tmp에 복사

	int i;
	for (i = 1; i < pos; i++)
	{
		tmp = tmp->next;
	}

	tmp->data = data;
}
//수정 함수. 리스트형 포인터 변수와 값, 위치를 인수로 받는다.
//해당 위치의 노드만 찾아서 값을 바꿔주면 된다.

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
//검사용 리스트 프린트 함수

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