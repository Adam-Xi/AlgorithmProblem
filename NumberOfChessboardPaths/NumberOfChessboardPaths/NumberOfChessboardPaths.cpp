/*
��Ŀ����
	���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ����������Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�
��������:
	��������������

�������:
	���ؽ��

ʾ��1
����
	2
	2
���
	6
*/
#include <iostream>
using namespace std;

int Func(int m, int n)
{
	int res = 0;
	if (m == 0 || n == 0)
	{
		res = 1;
	}
	else
	{
		res = Func(m - 1, n) + Func(m, n - 1);
	}
	return res;
	
}

int main()
{
	int row, col;
	cin >> row >> col;
	cout << Func(row, col) << endl;
	return 0;
}