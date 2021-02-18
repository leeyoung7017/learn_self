#include "func.h"

using namespace std;

int main()
{
	int a, b;
	cout << "请输入a,b的值：";
	cin >> a >> b;
	cout << "a = " << a << "\tb=" << b << endl;
	/*函数的调用*/
	cout << "两个值的和为：" << add(a, b) << endl;;
	system("pause");
	return 0;
}