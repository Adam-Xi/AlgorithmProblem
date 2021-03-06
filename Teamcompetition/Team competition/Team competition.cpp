/*
题目：牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.现在要将这些选手进行组队,
一共组成n个队伍,即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。

例如:
一个队伍三个队员的水平值分别是3,3,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是3,2,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是1,5,2.那么队伍的水平值是2
为了让比赛更有看点,牛牛想安排队伍使所有队伍的水平值总和最大。
如样例所示:
如果牛牛把6个队员划分到两个队伍
如果方案为:
team1:{1,2,5}, team2:{5,5,8}, 这时候水平值总和为7.
而如果方案为:
team1:{2,5,8}, team2:{1,5,5}, 这时候水平值总和为10.
没有比总和为10更大的方案,所以输出10.
输入描述：
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10^9),表示每个参赛选手的水平值.
输出描述：
输出一个整数表示所有队伍的水平值总和最大值.
示例1:
输入
2
5 2 8 5 1 5
输出
10
*/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v;

		int i = 0;
		int cur;
		for (; i< n * 3; i++)
		{
			cin >> cur;
			v.push_back(cur);
		}
		int size = v.size();
		//排序，减去n个最大值后的n个次大值即为结果
		sort(v.begin(), v.end());  //默认从小到大
		int sum1 = 0;
		for (i = n; i < 3 * n - 1; i += 2)
		{
			sum1 += v[i];
		}
		int sum2 = 0;
		for (i = size - 2 * n; i < size - n; i++)
		{
			sum2 += v[i];
		}

		cout << (sum1 > sum2 ? sum1 : sum2) << endl;

	}
	return 0;
}