/*
1

1  1  1

1  2  3  2  1

1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����

���n�е�һ��ż�����ֵ�λ�á����û��ż���������-1����������3,�����2������4�����3��



����n(n <= 1000000000)

��������:
����һ��int����



�������:
������ص�intֵ

ʾ��1
����
4
���
3
*/
#if 0

//�������������Ϊ66�����������
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

//�ҹ��ɣ�
//ǰ���о��Բ���������
//�����еĵ�һ��ż���ڵ�2λ
//4�ı����еĵ�һ��ż���ڵ�3λ
//��Ϊ4�ı����еĵ�һ��ż���ڵ�4λ


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