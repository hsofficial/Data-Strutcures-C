#include<stdio.h>

void main() 
{
	int num;

	printf("switch select(1~3) : ");
	scanf("%d", &num);

	switch (num) 
	{
	case 1:
		printf("turn on lights\n");
		break;

	case 2:
		printf("turn off lights\n");
		break;

	case 3:
		printf("error of lights\n");
		break;

	default:
		printf("input error\n");
	}
}