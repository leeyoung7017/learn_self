#include <iostream>
#include <string>

/*命名空间*/
using namespace std;

/*常量*/
#define LENGTH 1024

int main()
{
	/*常量*/
	const int i = 10;
	
	/*变量*/
	/*整型*/
	int a = 0;
	/*字符串*/
	char array0[] = "hello,my honey";
	string array1 = "hello,my dear";
	/*布尔类型*/
	bool flag = false;
	
	/*输入*/
	cout << "INPUT a:";//没有endl表示不需要进行换行
	cin >> a;
	
	/*输出*/
	/*endl代表换行*/
	cout << "hello world" << endl;
	cout << array0 << endl;
	cout << array1 << endl;
	cout << "i = " << i << endl;
	cout << "a = " << a << endl;
	cout << flag << endl;
	cout << "short所占内存为：\t" << sizeof(short) << "字节" << endl;
	cout << "int所占内存为：\t\t" << sizeof(int) << "字节" << endl;
	cout << "long所占内存为：\t" << sizeof(long) << "字节" << endl;
	cout << "float所占内存为：\t" << sizeof(float) << "字节" << endl;
	cout << "double所占内存为：\t" << sizeof(double) << "字节" << endl;
	cout << "char所占内存为：\t" << sizeof(char) << "字节" << endl;
	cout << "bool所占内存为：\t" << sizeof(bool) << "字节" << endl;
	
	/*系统暂停命令，按任意键结束*/
	system("pause");
	return 0;
}