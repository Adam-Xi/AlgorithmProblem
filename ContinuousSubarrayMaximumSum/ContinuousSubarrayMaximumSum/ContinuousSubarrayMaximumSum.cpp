#if 0
/*
һ�����������е�Ԫ�������и����ڸ��������ҳ�һ�����������飬
Ҫ��������������и�Ԫ�صĺ�����������������㱻����������������顣
��������{2,4,-7,5,2,-1,2,-4,3}���������������Ϊ{5,2,-1,2}��
�������������ĺ�Ϊ5+2-1+2=8��
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
		//����ۼӺͳ���С��0�������
		//������������п϶������ܰ���ǰ���Ԫ�أ�
		//��ʱ���ۼӺ���0�����¸�Ԫ�����¿�ʼ�ۼ�
		if (CurSum < 0)
			CurSum = 0;

	}
	cout << MaxSum << endl;
	return 0;
}
#endif

/*
��Ŀ����������
һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1, 2, 1]������������������Ϊ[2, 1]�����Ϊ 3

�������� :
	 ����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn��������ÿ��Ԫ��, ÿ����������32λint��Χ�ڡ��Կո�ָ���

������� :
	���������������к�����ֵ��
����
	3 - 1 2 1
���
	3
*/

#include <iostream>
#include <vector>
using namespace std;
//��̬�滮
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
		//max��ʼ�մ洢��ǰ���������������е���������
		int max = v[0];
		for (int i = 1; i < n; i++)
		{
			if (v[i - 1] > 0)  //ֻҪ��С��0����ǰ���ֵ����Ҫ����ǰһ�����ĺ�
			{
				v[i] += v[i - 1]; 
			}
			if (max < v[i])
			{
				max = v[i];  //����max
			}
		}
		cout << max << endl;
	}
	return 0;
}