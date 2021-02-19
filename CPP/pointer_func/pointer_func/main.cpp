#include <iostream>
#include <string>
#include "func.h"

using namespace std;

int main()
{
	int sum0,sum1;
	int* sum0_p = NULL;
	int* sum1_p = NULL;
	int a = 5;
	int b = 20;
	int* a_p = &a;
	int* b_p = &b;
	sum0 = add(a_p,b_p);
	sum1 = add(&a, &b);
	sum0_p = add_p(a_p,b_p);
	sum1_p = add_p(&a, &b);
	cout << "sum0:\t" << sum0 << endl;
	cout << "sum1:\t" << sum1 << endl;
	cout << "*sum0_p:" << *sum0_p << endl;
	cout << "*sum1_p:" << *sum1_p << endl;
	cout << "sum0_p:\t" << sum0_p << endl;
	cout << "sum1_p:\t" << sum1_p << endl;
	system("pause");
	return 0;
}