/*
问题描述
　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。一开始位于矩阵左上角，方向向下。
输入格式
  　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。
输出格式
	输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。
样例输入
	3 3
	1 2 3
	4 5 6
	7 8 9
样例输出
	1 4 7 8 9 6 3 2 5
样例输入
	3 2
	1 2
	3 4
	5 6
样例输出
	1 3 5 6 4 2

*/

#include<iostream>
using namespace std;

int m, n;
int arr[202][202];

int main()
{
	int count = 0;
	int i = 0, j = 0;
	cin >> m >> n;
	for (; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	i = -1, j = 0;
	while (count < m * n)
	{
		while (arr[i + 1][j])
		{
			cout << arr[++i][j] << " ";
			arr[i][j] = 0;
			count++;
		}
		while (arr[i][j + 1])
		{
			cout << arr[i][++j] << " ";
			arr[i][j] = 0;
			count++;
		}
		while (arr[i - 1][j])
		{
			cout << arr[--i][j] << " ";
			arr[i][j] = 0;
			count++;
		}
		while (arr[i][j - 1])
		{
			cout << arr[i][--j] << " ";
			arr[i][j] = 0;
			count++;
		}
	}
	return 0;
}