#include<stdio.h>

typedef struct people{
char name[10];
int age;
struct people* link;
}People;

void main() {
	People p1 = { "송진우",30,NULL };
	People p2 = { "송동열",30,NULL };
	People p3 = { "송보민",22,NULL };

	p1.link = &p2;
	p2.link = &p3;
	p3.link = &p1;

	p2.link->link->age = 22;
	printf("%s %d\n", p1.name, p1.age);
	printf("%s %d\n", p2.name, p2.age);
	printf("%s %d\n", p3.name, p3.age);
}