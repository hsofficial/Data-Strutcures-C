#include<stdio.h>
#include<string.h>

typedef struct student{
char name[10];
int age;
char address[20];
}Student;

void info(Student s) {
	printf("%s %d\n", s.name, s.age);
}

void main() {
	Student s1;
	Student* p1 = &s1;
		p1 -> age = 20;
	strcpy(p1->name,"dlwlrma");
	info(s1);
}