//************************ n皇后问题

#if 0

//************递归 + 回溯
#include<iostream>
using namespace std;
#include<cmath>

int n = 0;  //n个皇后
int queen[10] = { -1 };
int _count = 0;

bool IsAttack(int point_r, int point_c)
{
	for (int row = 0; row < point_r; row++)
	{
		if (point_c == queen[row] || abs(point_c - queen[row]) == point_r - row)
		{
			return true;
		}
	}
	return false;
}

void find(int row)
{
	for (int col = 0; col < n; col++)
	{
		if (!IsAttack(row, col))
		{
			if (row == n - 1)
			{
				_count++;
				return;
			}
			queen[row] = col;
			find(row + 1);
		}
	}
}

int main()
{
	cin >> n;
	find(0);
	cout << _count << endl;

	return 0;
}


#endif


#if 0
// *********************迭代+回溯
#include<iostream>
using namespace std;
#include<cmath>

int n = 0;  //n个皇后
int queen[10] = { -1 };
int _count = 0;

bool IsAttack(int point_r, int point_c)
{
	for (int row = 0; row < point_r; row++)
	{
		if (point_c == queen[row] || abs(point_c - queen[row]) == point_r - row)
		{
			return true;
		}
	}
	return false;
}

void find()
{
	int row = 0, col = 0;
	while (row < n)
	{
		while (col < n)
		{
			if (!IsAttack(row, col))
			{
				queen[row] = col;
				if (row == n - 1)
				{
					_count++;
					col++;
				}
				else
				{
					col = 0;
					break;
				}
			}
			else
			{
				col++;
			}
		}
		if (col == 8)
		{
			row--;
			if (row < 0)
			{
				return;
			}
			col = queen[row];
			col++;
			continue;
		}
		row++;
	}
}

int main()
{
	cin >> n;
	find();
	cout << _count << endl;

	return 0;
}

#endif