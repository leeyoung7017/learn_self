#include <iostream>
#include <string>

using namespace std;

#define IF_ELSE 0
#define SWITCH 1
#define THREE 0

int main()
{
#if IF_ELSE
	int a = 0;
	cout << "IF_ELSE" << endl;
	if (a)
		cout << "a的值不为零" << endl;
	else
		cout << "a的值为零" << endl;
#endif
#if SWITCH
	int a = 0;
	cout << "SWITCH" << endl;
	switch (a == 0)
	{
	case 0:
		cout << "a != 0" << endl;
		break;
	case 1:
		cout << "a = 0" << endl;
		break;
	default:
		break;
	}
#endif
#if THREE
	int num1 = 1, num2 = 3;
	int max = 0, min = 0;
	cout << "THREE" << endl;
	num1 > num2 ? max = num1 : max = num2;
	cout << "max = " << max << endl;
	min = (num1 > num2 ? num2 : num1);
	cout << "min = " << min << endl;
#endif

	system("pause");//系统暂停命令
	return 0;
}