#include "func.h"

int add(int* a_p, int* b_p)
{
	int sum = *a_p + *b_p;
	return sum;
}

int* add_p(int* a_p, int* b_p)
{
	int sum= *a_p + *b_p;
	return &sum;
}