#include <iostream>

using namespace std;

#define WHILE 0
#define DO_WHILE 0
#define FOR 1

int main()
{

#if WHILE
	int i = 0;
	int sum = 2;
	while (i != 5)
	{
		sum *= 2;
		i++;
	}
	cout << "WHILE" << endl;
	cout << "sum = " << sum << endl;
#endif 

#if DO_WHILE
	int i = 0;
	int sum = 2;
	do
	{
		sum *= 2;
		i++;
	} while (i != 5);
	cout << "DO_WHILE" << endl;
	cout << "sum = " << sum << endl;

#endif 

#if FOR
	int i = 0;
	int sum = 2;
	for (;i != 5;i++)
	{
		sum *= 2;
	}
	cout << "FOR" << endl;
	cout << "sum = " << sum << endl;

#endif 

	system("pause");//ÏµÍ³ÔÝÍ£ÃüÁî
	return 0;
}