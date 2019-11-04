/*
问题描述
　　给定一个N阶矩阵A，输出A的M次幂（M是非负整数）
  　例如：
	A =
	1 2
	3 4
A的2次幂
	7 10
	15 22
输入格式
	第一行是一个正整数N、M（1<=N<=30, 0<=M<=5），表示矩阵A的阶数和要求的幂数
	接下来N行，每行N个绝对值不超过10的非负整数，描述矩阵A的值
输出格式
	输出共N行，每行N个整数，表示A的M次幂所对应的矩阵。相邻的数之间用一个空格隔开
样例输入
	2 2
	1 2
	3 4
样例输出
	7 10
	15 22

*/

#include<iostream>
using namespace std;

int main()
{
	int n = 0;
	int mod = 0;
	cin >> n >> mod;
	int arr[30][30] = { 0 };
	int tmp[30][30] = { 0 };
	int i, j, m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (m = 0; m < n; m++)
			{
				tmp[i][j] += arr[i][m] * arr[m][j];
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << tmp[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}