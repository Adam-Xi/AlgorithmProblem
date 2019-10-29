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



#include <iostream>
#include<cmath>
using namespace std;

int n;
int m[9][9];
int blackPos[9];
int whitePos[9];
int ans = 0;

// 判断当前能否放置皇后 
bool isSafe(int pos[], int row) 
{
	for (int i = 0; i < row; i++) 
	{
		if (pos[i] == pos[row] || abs(pos[i] - pos[row]) == abs(i - row)) 
		{
			return false;
		}
	}
	return true;
}

// 对黑皇后的放置进行深搜 
void blackDfs(int row) 
{
	if (row == n) 
	{
		// 如果已经放置完成了n个黑皇后, 那么摆放的方法加1 
		ans++;
		return;
	}
	else 
	{
		for (blackPos[row] = 0; blackPos[row] < n; blackPos[row]++) 
		{
			// 如果当前位置没有与其他黑皇后发生冲突, 当前可以放置黑皇后而且当前的位置没有放置白皇后 
			if (isSafe(blackPos, row) && m[row][blackPos[row]] == 1 & blackPos[row] != whitePos[row]) 
			{
				blackDfs(row + 1);
			}
		}
	}
}

// 对白皇后的放置进行深搜 
void whiteDfs(int row) 
{
	if (row == n) 
	{
		// 如果已经放置完成了n个白皇后, 则进行放置黑皇后 
		blackDfs(0);
		return;
	}
	else 
	{
		for (whitePos[row] = 0; whitePos[row] < n; whitePos[row]++) 
		{
			// 当前位置没有与其他白皇后冲突且当前位置能放置 
			if (isSafe(whitePos, row) && m[row][whitePos[row]] == 1) 
			{
				whiteDfs(row + 1);
			}
		}
	}
}


int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> m[i][j];
		}
	}
	whiteDfs(0);
	cout << ans << endl;

	return 0;
}

