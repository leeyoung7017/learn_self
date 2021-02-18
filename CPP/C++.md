# C++基本框架

```c++
#include <iostream>
using namespace std;
int main()
{
	system("pause");//系统暂停命令
	return 0;
}
```

# 1. 输出

:star:注意：“endl”表示换行

## 1.1. 直接输出

`cout << "hello world" <<endl;`

## 1.2. 变量输出

`cout << "i = " << i << endl;`

`cout << "一周一共有" << day << "天" << endl;`

# 2. 输入

`cin >> a;`

# 3. 变量与常量

## 3.1. 变量

| 数据类型     | 变量          | 所占内存(sizeof查询占用内存大小) |
| ------------ | ------------- | -------------------------------- |
| 整型数据     | int           | 4字节                            |
|              | short         | 2字节                            |
|              | long          | 4字节                            |
|              | long long     | 8字节                            |
| 实型(浮点型) | float         | 4字节(7位有效数字)               |
|              | double        | 8字节(15~16位有效数字)           |
| 字符型       | char          | 1字节(单引号，单字符)            |
|              |               | ASCII码                          |
| 转义字符     | \n   \\\   \t | 换行 反斜线字符 tab键(占八位)    |
| 字符串型     | 字符数组      | 字符个数+1(双引号)               |
|              | string        | #include <string>                |
| 布尔类型     | true          | 1                                |
| 1字节        | false         | 0                                |

## 3.2. 常量

:star:注意：用于记录程序中不可更改的数据

### 3.2.1. define

`#define LENGTH 1024`

### 3.2.2. const

`const int i = 0；`

## 3.3. 变量名与常量名

* 不可以是关键字
* 有字母、数字、下划线组成
* 数字不能做为第一个字符
* 区分大小写

# 4. 运算符

## 4.1. 算术运算符

| +    | -    | *        |
| ---- | ---- | -------- |
| /    | %    | ++（--） |

## 4.2. 赋值运算符

| =    | +=   | -=   |
| ---- | ---- | ---- |
| *=   | /=   | %=   |

## 4.3. 比较运算符

| ==   | >=   | <=   |
| ---- | ---- | ---- |
| !=   | >    | <    |

## 4.4. 逻辑运算符

| ！   | &&   | \|\| |
| ---- | ---- | ---- |
| 非   | 与   | 或   |

# [应用1](https://github.com/leeyoung7017/learn_self/tree/Lee/CPP/hello_world/)

# 5. 程序流程

## 5.1.顺序结构

略；

## 5.2. 选择结构

### 5.2.1. if_else

### 5.2.2. switch 

### 5.2.3. ? : 

返回值为“：”的前后的内容；

`min = (num1 > num2 ? num2 : num1);`

`(num1 > num2 ? num2 : num1) = 100;`

### [应用2](https://github.com/leeyoung7017/learn_self/tree/Lee/CPP/struct_choise/)

## 5.3. 循环结构

### 5.3.1. while

### 5.3.2. do_while

### 5.3.3. for

### 5.3.4. 嵌套循环

### [应用3](https://github.com/leeyoung7017/learn_self/tree/Lee/CPP/hello_world/struct_choise/)

## 5.4. 跳转语句

### 5.4.1. break

### 5.4.2. continue

### 5.4.3. goto

# 6. 数组

## 6.1. 一维数组

### 6.1.1. 定义

`int arr[5] = {0,1,2,3,4};`

`int arr[] = {0,1,2,3,4};`

`int arr[5];`

### 6.1.2. 使用

`arr[0];arr[1];arr[2];arr[3];arr[4];`

`for(int i = 0;i<;i++){}`

## 6.2. 二维数组

### 6.2.1. 定义

```c++
int score[3][3] = {	{100,100,100},
						{90 ,50		},
						{60 ,70 ,80	} };
```

### 6.2.2. 使用

`for (i = 0;i < 3;i++)	{for (j = 0;j < 3;j++){}}`

## 6.3. 冒泡排序

略；

[应用4](https://github.com/leeyoung7017/learn_self/tree/Lee/CPP/array/)

# 7.函数

## 7.1. 定义

```c++
/*函数的定义*/
int add(int num1, int num2)
{
	int sum;
	sum = num1 + num2;
	return sum;
}
```

## 7.2. 声明

```c++
/*函数的声明*/
int add(int num1, int num2);
```

## 7.3. 调用

```c++
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
```

## 7.4. 分文件编写

### 7.4.1. 头文件

一般习惯导致这么写，灵活应用

```c++
#ifndef _FUNC_H

#include <iostream>
#include <string>

int add(int num1, int num2);

#endif // !_FUNC_H
#pragma once
```

### 7.4.2. 源文件

* 源文件是将函数写入，同函数的定义，但是不要忘记#include的命令
* 写完之后需要将头文件目录包含进去，网上查找即可；

[应用5](https://github.com/leeyoung7017/learn_self/tree/Lee/CPP/func/)

# 8. 指针

## 8.1. 定义

[应用6](https://github.com/leeyoung7017/learn_self/tree/Lee/CPP/pointer/)