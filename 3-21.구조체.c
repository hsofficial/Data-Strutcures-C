#include<stdio.h>

struct student
{
	char name[10];
	int age;
	char address[20];
};

void main() {
	struct student s1 = { "������", 27, "����" };
	printf("%s %d %s\n", s1.name, s1.age, s1.address);
}