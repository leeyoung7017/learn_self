#include <iostream>
#include <string>

using namespace std;


#define ONE_ARRAY	0		/*һά����*/
#define TWO_ARRAY	1		/*��ά����*/
#define BUBBLE_SORT 0		/*ð������*/

int main()
{
#if ONE_ARRAY
	int arr0[5] = { 0,1,2,3,4 };
	int max = arr0[0];
	for (int i = 0;i < 5;i++)
	{
		if (max < arr0[i]) 
		{
			max = arr0[i];	
		}
	}
	cout << "max = " << max << endl;

#endif // ONE_ARRAY

#if BUBBLE_SORT  //���� n*(n-1)/2 ��

	int arr0[5] = { 7,6,5,4,9 };
	int num;
	int i, j;
	int time = 0;
	for (i = 0;i < 4;i++)
	{
		for (j = 4-i;j > 0;j--)
		{
			time++;
			if (arr0[j] < arr0[j - 1])
			{
				num = arr0[j];
				arr0[j] = arr0[j - 1];
				arr0[j - 1] = num;
			}
		}
	}
	for (i = 0;i < 5;i++)
	{
		cout << arr0[i] << endl;
	}
	cout << "ð�������ѭ������" << time << "��" << endl;

#endif // BUBBLE_SORT


#if TWO_ARRAY

	int score[3][3] = {	{100,100,100},
						{90 ,50		},
						{60 ,70 ,80	} };
	int i, j;
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			if (score[i][j] == 0) goto ZERO;
		}
	}
ZERO:
	cout << "����ֵ�λ��Ϊ(" << i << "," << j << ")" << endl;

#endif // TWO_ARRAY

	
	system("pause");
	return 0;
}