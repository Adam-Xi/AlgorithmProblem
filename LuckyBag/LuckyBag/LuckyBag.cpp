/*
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。

输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)


输出描述:
输出可以产生的幸运的袋子数
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int _count = 0;
vector<int> v;

void One_Count(int cur_pos, int sum, int mul)
{
	for (int i = cur_pos; i < v.size(); i++)
	{
		sum += v[i];
		mul *= v[i];
		if (sum <= mul)
		{
			return;
		}
		else
		{
			_count++;
		}
		One_Count(i + 1, sum, mul);
		sum -= v[i];
		mul /= v[i];
		while (v[i] == v[i + 1] && i < v.size())
		{
			i++;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int one_num = 0;
	int val;
	while(n--)
	{
		cin >> val;
		if (val > 1)
		{
			v.push_back(val);
		}
		else
		{
			one_num++;
		}
	}
	_count = one_num - 1; //1的个数也满足条件，有one_num - 1中情况
	if (!v.empty())
	{
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			One_Count(i, i, 1);
		}
	}
	cout << _count << endl;
	return 0;
}