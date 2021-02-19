#include <iostream>
#include <string>
using namespace std;

#define POINTER_VALUE 0		/*数值型指针*/
#define POINTER_CHAR 0		/*char类型指针*/
#define ARRAY_POINTER_CHAE 1		/*数组与指针*//*char类型*/
#define ARRAY_POINTER_INT 0		/*数组与指针*//*int类型*/
#define SPACE_POINTER 0		/*各类型指针所占空格*/
#define CONST_POINTER 0		/*const修饰指针*/

int main()
{
#if POINTER_VALUE
	int a = 10;
	int* a_p;
	a_p = &a;
	cout << "地址：\t" << a_p << endl;
	cout << "内容：\t" << *a_p << endl;


#endif // POINTER_VALUE

#if POINTER_CHAR
	char c = 97;
	char* c_p;
	c_p = &c;
	cout << "地址：\t" << c_p << endl;/*错误*/
	cout << "内容：\t" << *c_p << endl;

#endif // POINTER_CHAR


#if ARRAY_POINTER_CHAE
	char word[] = "hello_world";
	char* word_p;
	word_p = word;
	cout << "word_p：" << word_p << endl;
	cout << "*word_p：" << *word_p << endl;
#endif // ARRAY_POINTER

#if ARRAY_POINTER_INT
	int num[] = { 0,1,2,3,4,5 };
	int* num_p;
	num_p = num;
	cout << "num_p：\t" << num_p << endl;
	cout << "*num_p：" << *num_p << endl;
#endif // ARRAY_POINTER_INT


#if SPACE_POINTER
	cout << "int*：\t" << sizeof(int*) << endl;
	cout << "char*：\t" << sizeof(char*) << endl;
	cout << "float*：" << sizeof(float*) << endl;
	cout << "double*:" << sizeof(double*) << endl;

#endif // SPACE_POINTER

#if CONST_POINTER
	int a = 10;
	int b = 20;
	const int* a_p = &a;	/*常量指针*//*即指针的内容是常量*/
	int* const p = &b;		/*指针常量*//*即常量的内容是指针*/

#endif // CONST_POINTER


	
	system("pause");//系统暂停命令
	return 0;
}
