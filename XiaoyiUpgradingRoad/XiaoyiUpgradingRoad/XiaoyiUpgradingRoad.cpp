/*
С�׾���������������Ϸ.
��һ��,������һ�������������Ϸ,���Ľ�ɫ�ĳ�ʼ����ֵΪ a.
�ڽ�������һ��ʱ����,��������������n������,ÿ������ķ�����Ϊb1,b2,b3...bn. 
��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,��ô���������ɴ�ܹ���,�� ��ʹ���Լ�������ֵ����bi;
���bi����c,����Ҳ�ܴ�ܹ���,����������ֵֻ������bi ��c�����Լ��.��ô��������,��һϵ�еĶ�����,С�׵���������ֵΪ����?

��������:
����ÿ������,��һ������������n(1��n<100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ.
�ڶ���n������,b1,b2...bn(1��bi��n)��ʾÿ������ķ�����


�������:
����ÿ������,���һ��.ÿ�н�����һ������,��ʾС�׵���������ֵ
ʾ��1
����
3 50
50 105 200
5 20
30 20 15 40 100
���
110
205
*/

#include <iostream>
#include <vector>
using namespace std;

int Common_divisor(int x, int y)
{
	while ((x*y) != 0){
		if (x > y){
			x %= y;
		}
		else if (y > x){
			y %= x;
		}
		else{
			break;
		}
	}
	return y;
}


int main()
{
	int n, a;
	while (cin >> n >> a)
	{
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		for (int i = 0; i < n; i++)
		{
			if (v[i] <= a)
			{
				a += v[i];
			}
			else
			{
				a += Common_divisor(a, v[i]);
			}
		}
		cout << a << endl;
	}
	return 0;
}

