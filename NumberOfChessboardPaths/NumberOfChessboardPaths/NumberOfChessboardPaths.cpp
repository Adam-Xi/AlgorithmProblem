/*
题目描述
	请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。
输入描述:
	输入两个正整数

输出描述:
	返回结果

示例1
输入
	2
	2
输出
	6
*/
#include <iostream>
using namespace std;

int Func(int m, int n)
{
	int res = 0;
	if (m == 0 || n == 0)
	{
		res = 1;
	}
	else
	{
		res = Func(m - 1, n) + Func(m, n - 1);
	}
	return res;
	
}

int main()
{
	int row, col;
	cin >> row >> col;
	cout << Func(row, col) << endl;
	return 0;
}