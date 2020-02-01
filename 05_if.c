#include<stdio.h>
#define ELEENTARY 650
#define MIDDLE_AND_HIGH 800
#define ADULT 1200

void main() {
	int card = 10000;
	int regi = 20001016;
	int today = 20180712;
	int age = today / 10000 - regi / 10000 + 1;

	if (age >= 7 && age <= 12)
		card -= ELEENTARY;

	else if (age < 19)
		card -= MIDDLE_AND_HIGH;

	else if (age >= 19)
		card -= ADULT;

	printf("your age is %d\n", age);
	printf("bal is %d now\n", card);
}