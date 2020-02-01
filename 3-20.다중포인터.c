#include <stdio.h>

void Swap(int** pp_n1, int** pp_n2) {
	int tmp;
	tmp = **pp_n1;
	**pp_n1 = **pp_n2;
	**pp_n2 = tmp;
}
void main() {
	int n1 = 10, n2 = 20;
	int* p_n1, * p_n2;
	p_n1 = &n1;
	p_n2 = &n2;
	Swap(&p_n1, &p_n2);
	printf("n1 : %d, n2 : %d \n", n1, n2);
}