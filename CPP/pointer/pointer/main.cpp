#include <iostream>
#include <string>
using namespace std;

#define POINTER_VALUE 0		/*��ֵ��ָ��*/
#define POINTER_CHAR 0		/*char����ָ��*/
#define ARRAY_POINTER_CHAE 1		/*������ָ��*//*char����*/
#define ARRAY_POINTER_INT 0		/*������ָ��*//*int����*/
#define SPACE_POINTER 0		/*������ָ����ռ�ո�*/
#define CONST_POINTER 0		/*const����ָ��*/

int main()
{
#if POINTER_VALUE
	int a = 10;
	int* a_p;
	a_p = &a;
	cout << "��ַ��\t" << a_p << endl;
	cout << "���ݣ�\t" << *a_p << endl;


#endif // POINTER_VALUE

#if POINTER_CHAR
	char c = 97;
	char* c_p;
	c_p = &c;
	cout << "��ַ��\t" << c_p << endl;/*����*/
	cout << "���ݣ�\t" << *c_p << endl;

#endif // POINTER_CHAR


#if ARRAY_POINTER_CHAE
	char word[] = "hello_world";
	char* word_p;
	word_p = word;
	cout << "word_p��" << word_p << endl;
	cout << "*word_p��" << *word_p << endl;
#endif // ARRAY_POINTER

#if ARRAY_POINTER_INT
	int num[] = { 0,1,2,3,4,5 };
	int* num_p;
	num_p = num;
	cout << "num_p��\t" << num_p << endl;
	cout << "*num_p��" << *num_p << endl;
#endif // ARRAY_POINTER_INT


#if SPACE_POINTER
	cout << "int*��\t" << sizeof(int*) << endl;
	cout << "char*��\t" << sizeof(char*) << endl;
	cout << "float*��" << sizeof(float*) << endl;
	cout << "double*:" << sizeof(double*) << endl;

#endif // SPACE_POINTER

#if CONST_POINTER
	int a = 10;
	int b = 20;
	const int* a_p = &a;	/*����ָ��*//*��ָ��������ǳ���*/
	int* const p = &b;		/*ָ�볣��*//*��������������ָ��*/

#endif // CONST_POINTER


	
	system("pause");//ϵͳ��ͣ����
	return 0;
}
