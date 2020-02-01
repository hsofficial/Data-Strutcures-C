#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("원반 1 : %c에서 %c로 이동합니다.\n", from, to);
	}

	else
	{
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반 %d : %c에서 %c로 이동합니다.\n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main(void)
{
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}