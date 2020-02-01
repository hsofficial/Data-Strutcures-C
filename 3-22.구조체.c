#include <stdio.h>

struct student
{
	char name[10];
	int age;
	char address[20];
};

void pointer_info(struct student * s) {
	printf("%s %d %s\n", s->name, s->age, s->address);
}

void main() {
	struct student s1 = { "dlwlrma", 27, "seoul" };
	pointer_info(&s1);
}