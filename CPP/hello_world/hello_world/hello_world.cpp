#include <iostream>
#include <string>

/*�����ռ�*/
using namespace std;

/*����*/
#define LENGTH 1024

int main()
{
	/*����*/
	const int i = 10;
	
	/*����*/
	/*����*/
	int a = 0;
	/*�ַ���*/
	char array0[] = "hello,my honey";
	string array1 = "hello,my dear";
	/*��������*/
	bool flag = false;
	
	/*����*/
	cout << "INPUT a:";//û��endl��ʾ����Ҫ���л���
	cin >> a;
	
	/*���*/
	/*endl������*/
	cout << "hello world" << endl;
	cout << array0 << endl;
	cout << array1 << endl;
	cout << "i = " << i << endl;
	cout << "a = " << a << endl;
	cout << flag << endl;
	cout << "short��ռ�ڴ�Ϊ��\t" << sizeof(short) << "�ֽ�" << endl;
	cout << "int��ռ�ڴ�Ϊ��\t\t" << sizeof(int) << "�ֽ�" << endl;
	cout << "long��ռ�ڴ�Ϊ��\t" << sizeof(long) << "�ֽ�" << endl;
	cout << "float��ռ�ڴ�Ϊ��\t" << sizeof(float) << "�ֽ�" << endl;
	cout << "double��ռ�ڴ�Ϊ��\t" << sizeof(double) << "�ֽ�" << endl;
	cout << "char��ռ�ڴ�Ϊ��\t" << sizeof(char) << "�ֽ�" << endl;
	cout << "bool��ռ�ڴ�Ϊ��\t" << sizeof(bool) << "�ֽ�" << endl;
	
	/*ϵͳ��ͣ��������������*/
	system("pause");
	return 0;
}