#if 0
/*
一个整数数组中的元素有正有负，在该数组中找出一个连续子数组，
要求该连续子数组中各元素的和最大，这个连续子数组便被称作最大连续子数组。
比如数组{2,4,-7,5,2,-1,2,-4,3}的最大连续子数组为{5,2,-1,2}，
最大连续子数组的和为5+2-1+2=8。
*/
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int MaxSum = 0;
	int CurSum = 0;
	for (i = 0; i < n; i++)
	{
		CurSum += v[i];
		if (CurSum > MaxSum)
			MaxSum = CurSum;
		//如果累加和出现小于0的情况，
		//则和最大的子序列肯定不可能包含前面的元素，
		//这时将累加和置0，从下个元素重新开始累加
		if (CurSum < 0)
			CurSum = 0;

	}
	cout << MaxSum << endl;
	return 0;
}
#endif

/*
题目：连续最大和
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1, 2, 1]，和最大的连续子数组为[2, 1]，其和为 3

输入描述 :
	 输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素, 每个整数都在32位int范围内。以空格分隔。

输出描述 :
	所有连续子数组中和最大的值。
输入
	3 - 1 2 1
输出
	3
*/

#include <iostream>
#include <vector>
using namespace std;
//动态规划
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		//max中始终存储当前所遍历过的数组中的连续最大和
		int max = v[0];
		for (int i = 1; i < n; i++)
		{
			if (v[i - 1] > 0)  //只要不小于0，当前项的值都需要加上前一项代表的和
			{
				v[i] += v[i - 1]; 
			}
			if (max < v[i])
			{
				max = v[i];  //更新max
			}
		}
		cout << max << endl;
	}
	return 0;
}