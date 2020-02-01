#include<stdio.h>
#include<stdlib.h>

//#define TRUE 1
//#define FALSE 0
#define LIST_LEN 5

typedef int LData;
//저장할 대상의 자료형 변경을 위한 typedef 선언

typedef struct ArrayList
{
	LData arr[LIST_LEN];	//리스트 저장소로 배열 사용
	int data_num;	//저장되는 데이터의 수
	int position;	//데이터 참조위치 기록
}ArrayList;
//배열기반 리스트 정의 구조체

typedef ArrayList List;
//리스트의 변경을 용이하게 하기 위한 typedef 선언

void Init(List * plist)
{
	plist->data_num = 0;
}
//초기화할 리스트의 주소값을 인자로 전달한다

void Insert(List* plist, LData data)
{
	if (plist->data_num >= LIST_LEN)
	{
		printf("저장할 공간이 없습니다\n");
		return;
	}

	plist->arr[plist->data_num] = data; //데이터 저장
	plist->data_num++; //저장된 데이터의 개수 증가
}
//리스트에 데이터를 저장하며 매개변수 data에 연결된 값을 저장한다

/*

int First(List* plist, LData* data)
{
	if (plist->data_num == 0)
		return FALSE;
	//저장된 데이터가 하나도 없다면 f를 반환한다

	(plist->position) = 0;	//참조 위치의 초기화
	*data = plist->arr[0];	//data가 가리키는 공간에 데이터 저장
	return TRUE;
}
//첫번째 참조에 관한 함수

int Next(List* plist, LData* data)
{
	if(plist->position >= (plist->data_num) - 1)
		return FALSE;
	//더이상 참조할 데이터가 없다면 f를 반환한다

	(plist->position)++;	//현재위치에 1을 증가시킨다
	*data = plist->arr[plist->position];
	//값의 반환은 매개변수로 진행하며 함수의 반환은 성공여부를 반환한다

	return TRUE;
}
//다음 참조에 관한 함수

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
		printf("찾는 데이터가 없습니다.\n");
		return;
	}
}
//데이터를 삭제한다. 삭제된 데이터는 반환된다.
//마지막 반환 데이터를 삭제하므로 연속된 반복 호출을 하지 않는다.

void PrintAll(List* plist)
{
	if (plist->data_num == 0)
		printf("데이터가 없습니다.\n");

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
//함수를 호출하는 시점에 연결리스트에 저장된 모든 값을 출력한다

int main()
{
	/*** ArrayArrayList의 생성 및 초기화 ***/
	List list;
	int data;
	Init(&list);

	/*** 5개의 데이터 저장 ***/
	Insert(&list, 11);
	Insert(&list, 11);
	Insert(&list, 22);
	Insert(&list, 33);
	Insert(&list, 33);


	/*** 저장된 데이터의 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", list.data_num);
	PrintAll(&list);
	printf("\n\n");

	/*** 숫자 탐색하여 삭제 ***/
	printf("삭제할 데이터를 입력 : ");
	scanf("%d", &data);
	Del(&list, data);
	printf("\n\n");

	/*** 삭제 후 저장된 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", list.data_num);
	PrintAll(&list);


}