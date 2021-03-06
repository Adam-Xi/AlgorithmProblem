/*
在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。

给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。

测试样例：
4,[0,7,1,6],[1,5,0,6]
返回：10(解释：可以左手手套取2只，右手手套取8只)
*/

//思路：假设有一序列 a1<a2<a3<a4<...<an，s选出多少个能够保证覆盖n种颜色？
//答案是 sum(a1...an)-a1+1，类似鸽巢原理
//所以先求出左手套和右手套哪边能够覆盖n种颜色，而且还能少拿手套？
//答案是 min(leftSum-leftMin+1,rightSum-rightMin+1)，这个确定以后，
//只需要在另一边随便选择一个就能够保证至少有一种颜色匹配了
//另外要注意某种颜色手套数为0的情况

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int sum = 0;
		int leftSum = 0, rightSum = 0;
		int leftMin = 30, rightMin = 30;
		for (int i = 0; i<n; i++)
		{
			if (left[i] * right[i] == 0)sum += (left[i] + right[i]);
			else{
				leftSum += left[i];
				rightSum += right[i];
				leftMin = min(leftMin, left[i]);
				rightMin = min(rightMin, right[i]);
			}
		}
		return sum + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;
	}
};

int main()
{
	int n;
	cin >> n;
	vector<int> left(n, 0);
	vector<int> right(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> left[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> right[i];
	}

	Gloves g;
	cout << g.findMinimum(n, left, right) << endl;

	return 0;
}