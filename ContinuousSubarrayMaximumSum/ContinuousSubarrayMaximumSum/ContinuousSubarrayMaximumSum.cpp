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