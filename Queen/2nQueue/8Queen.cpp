#include<iostream>
#include<cmath>
using namespace std;

int queen[8] = { 0 };
int res = 0;

// 检测冲突，若冲突返回真
//    行 -------- 列
// point_r ---- point_c   要检测的行和列（确定的点）
//    i ------- queen[i]  前n行已经找出来的点，看point是否与之前找出来的行列冲突
bool IsAttack(int point_r, int point_c)  
{
	for (int i = 0; i < point_r; ++i)
	{
		//由于是在把前n-1行中确定的每个点 与 第n行中的point点进行比较，所以不需要进行同一行的判断，肯定不相等
		//只需检测 point点 是否与 前n-1行中的每个点 列号相等   或者斜率相等，即在同一对角线上
		if (point_c == queen[i] || (abs(point_c - queen[i]) == point_r - i))  
		{
			return true;
		}
	}
	return false;
}

//找点，递归，回溯
void find_queen(int n)  //n为行号
{
	for (int i = 0; i < 8; ++i)  //遍历第n行中的每一列，确定当前的选中点
	{
		if (!IsAttack(n, i))  //不起冲突时
		{
			queen[n] = i;
			if (n == 7)  //已经进行到第7行，且第7行中的点已经确定时，代表一种组合已经确定，计数器++；回溯，返回第6层找其他的组合
			{
				res++;
				return;
			}
			find_queen(n + 1);  //递归，没在尾行，且已经确定当前行的具体点，进入下一行的查找
		}
	}
	return;  //最内层的循环确定，回溯到其他层，继续查找其他组合
}

int main()
{
	find_queen(0);
	cout << res << endl;

	return 0;
}