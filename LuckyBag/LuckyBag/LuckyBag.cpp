/*
һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
���磺��������������ĺ�����{1, 1, 2, 3}��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��,���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�

��������:
��һ������һ��������n(n �� 1000)
�ڶ���Ϊn����������xi(xi �� 1000)


�������:
������Բ��������˵Ĵ�����
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
	_count = one_num - 1; //1�ĸ���Ҳ������������one_num - 1�����
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