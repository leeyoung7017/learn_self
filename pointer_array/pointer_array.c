
#include<stdio.h>

int main(void)
{
	int array[2];

	int *array1[2];
	
	char *array2[3]={"1","2","3"};

	int *p;

	array[0] = 7017;

	array[1] = 7018;

	p =  array;
	
	array1[0] = p;
	
	array1[1] = p + 1;
	
	printf("\n");
	
	printf("array = %p \n\n" , array);

	printf("*array = %d \n\n" , *array);

	printf("p = %p \n\n", p);
	
	printf("*p = %d \n\n", *p);
	
	printf("array1[0] = %p \n\n", array1[0]);

	printf("array1[1] = %p \n\n", array1[1]);	
	
	printf("*array1[0] = %d \n\n", *array1[0]);

	printf("*array1[1] = %d \n\n", *array1[1]);

	printf("array2[0] = %s \n\n",array2[0]);
	
	printf("*array2[0] = %c \n\n",*array2[0]);
	
	printf("\n");
	
	scanf("%d",array[1]);
}
// 指针数组即 *数组名[n] 指的是在数组中存放的是地址，他的本质是数组，只不过里边存放的的是指针；
// 数组指针即 数组名 + m  指的是该数组第 m 项所在的地址，其本质就是指针，只不过里面存放的是数组所在地址；
// & + 变量  指的是取该变量的地址；
// * + 指针变量  指的是在指针变量存放的地址的内容，而不是指针变量存放的内容；* 后只能+存放地址的变量。


// 《鬼灭之刃》、
// 《东京食尸鬼》、
// 《刀剑神域》、
// 《某科学的超电磁炮》、
// 《NO GAME NO LIFE 游戏人生》、
// 《Fate系列》、
// 《我的英雄学院》、
// 《K RETURN OF KINGS》、
// 《黑之契约者》、
// 《黑岩射手》、
// 《野良神》、
// 《一拳超人》、
// 《比宇宙更远的地方》、
// 《热诚传说X》、
// 《AIR》、
// 《游戏：崩坏3》、
// 《维度战记》
