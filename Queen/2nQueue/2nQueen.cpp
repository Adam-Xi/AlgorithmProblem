/*

问题描述
　　给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。
    现在要向棋盘中放入n个黑皇后和n个白皇后，
	使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一条对角线上。
	问总共有多少种放法？n小于等于8。
 输入格式
  　输入的第一行为一个整数n，表示棋盘的大小。
	接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后。
输出格式
	输出一个整数，表示总共有多少种放法。
样例输入
	4
	1 1 1 1
	1 1 1 1
	1 1 1 1
	1 1 1 1
样例输出
	2
样例输入
	4
	1 0 1 1
	1 1 1 1
	1 1 1 1
	1 1 1 1
样例输出
	0

*/
#include<iostream>
using namespace std;
#include<cmath>

int n = 0;  //2n皇后
int m[10][10];  //地图
int blackPos[10], whitePos[10];  //黑白皇后的选点集，下标表示行，通过下标访问的值为列
int _count = 0;  //方法计数器

bool IsAttack(int pos[], int point_r, int point_c)  //当前点是否冲突
{
	for (int row = 0; row < point_r; row++)
	{
		if (point_c == pos[row] || abs(point_c - pos[row]) == point_r - row)
		{
			return true;
		}
	}
	return false;
}

//黑皇后落子
void SetBlack(int row)
{
	if (row == n)
	{
		//黑皇后已落了n个子，计数器+1
		_count++;
		return;
	}
	//深度优先遍历搜索 黑皇后选定落子序列
	for (blackPos[row] = 0; blackPos[row] < n; blackPos[row]++)
	{
		if (!IsAttack(blackPos, row, blackPos[row]) && m[row][blackPos[row]] == 1 && blackPos[row] != whitePos[row])
		{
			SetBlack(row + 1);
		}
	}
}

//白皇后落子
void SetWhite(int row)
{
	if (row == n)
	{
		//白皇后已经落了n个子，即白皇后的一种序列已经确定，在此基础上对黑皇后的落子集合进行搜索
		SetBlack(0);
		return;
	}
	//深度优先遍历搜索，查找白皇后落子的序列
	for (whitePos[row] = 0; whitePos[row] < n; whitePos[row]++)
	{
		if (!IsAttack(whitePos, row, whitePos[row]) && m[row][whitePos[row]] == 1)
		{
			SetWhite(row + 1);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> m[i][j];
		}
	}
	SetWhite(0);
	cout << _count << endl;
	return 0;
}