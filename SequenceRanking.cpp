/*
@Adam-Xi
2019-09-19
问题描述:
　　给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
输入格式:
  　第一行为一个整数n。
	第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
输出格式:
	输出一行，按从小到大的顺序输出排序后的数列。
样例输入:
	5
	8 3 6 4 9
样例输出:
	3 4 6 8 9
*/
#include<iostream>
using namespace std;

void sort(int *a, int max)
{
	int m, n;
	for (m = 0; m < max; m++)
	{
		for (n = m + 1; n < max; m++)
		{
			if (a[m] > a[n])
			{
				int tmp = a[m];
				a[m] = a[n];
				a[n] = tmp;
			}
		}
	}
}

int main()
{
	int n = 0;
	int array[201] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
//	sort(array, n);
	int m, j;
	for (m = 0; m < n; m++)
	{
		for (j = m + 1; j < n; j++)
		{
			if (array[m] > array[j])
			{
				int tmp = array[m];
				array[m] = array[j];
				array[j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}

	return 0;
}
