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