/*
*********八皇后问题*********
八皇后问题，是一个古老而著名的问题，是回溯算法的典型案例。
该问题是国际西洋棋棋手马克斯·贝瑟尔于1848年提出：
	在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法。 
高斯认为有76种方案。1854年在柏林的象棋杂志上不同的作者发表了40种不同的解，后来有人用图论的方法解出92种结果。
计算机发明后，有多种计算机语言可以解决此问题。
*/

#if 0

//************递归+回溯

#include<iostream>
using namespace std;
#include<cmath>

int queen[8] = { 0 };  //用一维数组来维护皇后落子的点，例如，queen[1] = 5表示第2行第6列有一个落子点（从0开始）
int _count = 0;

// 检测冲突，若冲突返回真
//    行 --------- 列
// point_r ----- point_c   要检测的行和列（确定的点）
//   row ------- queen[row]  前n行已经找出来的点，看point是否与之前找出来的行列冲突
bool IsAttack(int point_r, int point_c)
{
	for (int row = 0; row < point_r; ++row)
	{
		//由于是在把前n-1行中确定的每个点 与 第n行中的point点进行比较，所以不需要进行同一行的判断，肯定不相等
		//只需检测 point点 是否与 前n-1行中的每个点 列号相等   或者  斜率相等，即在同一对角线上
		if (point_c == queen[row] || (abs(queen[row] - point_c) == point_r - row))
		{
			return true;
		}
	}
	return false;
}

//找点，递归，回溯
void find(int row)  //row为行号
{
	for (int col = 0; col < 8; ++col)  //遍历第row行中的每一列，确定当前的选中点
	{
		if (!IsAttack(row, col))  //不起冲突时
		{
			if (row == 7)  //已经进行到第7行，且第7行中的点已经确定时，代表一种组合已经确定，计数器++；回溯，返回第6层找其他的组合
			{
				_count++;
				return;
			}
			queen[row] = col;  
			find(row + 1);  //递归，没在尾行，且已经确定当前行的具体点，进入下一行的查找
		}
	}
	//最内层的循环确定，回溯到其他层，继续查找其他组合
}

int main()
{
	find(0);
	cout << _count << endl;

	return 0;
}

#endif

#if 0

//************迭代+回溯

#include<iostream>
using namespace std;
#include<cmath>

int queen[8] = { -1 };
int _count = 0;


bool IsAttack(int point_r, int point_c)
{
	for (int row = 0; row < point_r; ++row)
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
	while (row < 8)  //控制行
	{
		while (col < 8)  //控制列
		{
			if (!IsAttack(row, col))  //当前的点不起冲突时
			{
				queen[row] = col;  
				if (row == 7)  //检测当前点是否在尾行，即是否找到一组完整的解
				{
					_count++;  //计数器计数
					col++;  //循环自增到不满足条件，跳转到if(col==8)这一代码块中进行回溯处理，用时间换代码冗余量
//					queen[row] = -1;
				}
				else
				{
					col = 0;  //去下一行
					break;
				}
			}
			else
			{
				col++;  //当前点不满足，找当前行的下一个点
			}
		}
		//回溯
		if (col == 8)  //当前待检测的点越界
		{
			row--;  //回溯一行
			if (row < 0)  //若回溯出界，则程序运行结束
			{
				return;
			}
			else
			{
				col = queen[row];  
				col++;  //在上一行已确定的点之后继续找
//				queen[row] = -1;
				continue;
			}
		}
		row++;  
	}
}

int main()
{
	find();
	cout << _count << endl;

	return 0;
}


#endif