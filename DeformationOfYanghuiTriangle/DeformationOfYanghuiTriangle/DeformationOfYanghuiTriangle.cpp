/*
1

1  1  1

1  2  3  2  1

1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。

求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。



输入n(n <= 1000000000)

输入描述:
输入一个int整数



输出描述:
输出返回的int值

示例1
输入
4
输出
3
*/
#if 0

//题解有误，若输入为66，则存在问题
#include <iostream>
#include <vector>
using namespace std;

int Func(int n)
{
	vector<vector<int>> vv;
	vv.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		vv[i].resize(i + 1);
	}
	vv[1][1] = 1;
	vv[2][1] = 1, vv[2][2] = 1;
	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				vv[i][j] = 1;
			}
			else if (j == 2)
			{
				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
			}
			else if (j == i)
			{
				vv[i][j] = 2 * vv[i - 1][j - 1] + vv[i - 1][j - 2];
			}
			else
			{
				vv[i][j] = vv[i - 1][j - 2] + vv[i - 1][j - 1] + vv[i - 1][j];
			}
			if (i == n && ((vv[i][j] & 1) == 0))
			{
				return j;
			}
		}
	}
	return -1;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << Func(n) << endl;
	}
	return 0;
}

#endif

#include <iostream>
#include <vector>
using namespace std;

//找规律：
//前两行绝对不满足条件
//奇数行的第一个偶数在第2位
//4的倍数行的第一个偶数在第3位
//不为4的倍数行的第一个偶数在第4位


int main()
{
	int n;
	while (cin >> n)
	{
		if (n <= 2)
		{
			cout << -1 << endl;
		}
		else if (n % 2 == 1)
		{
			cout << 2 << endl;
		}
		else
		{
			if (n % 4 == 0)
			{
				cout << 3 << endl;
			}
			else
			{
				cout << 4 << endl;
			}
		}
	}
	return 0;
}