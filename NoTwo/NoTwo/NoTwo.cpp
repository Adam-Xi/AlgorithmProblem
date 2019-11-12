/*
����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
����������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������

��������:
ÿ������������񳤿�W,H���ÿո�ָ�.(1 �� W��H �� 1000)


�������:
���һ�������Էŵĵ�����
ʾ��1
����
3 2
���
4
*/


# if 0

#include<iostream>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;

	int evenICount = (n / 4) * 2 + (n % 4 < 2 ? n % 4 : 2);
	int oddICount = ((n - 2) / 4) * 2 + ((n - 2) % 4 < 2 ? (n - 2) % 4 : 2);
	int ans = m / 4 * (evenICount + oddICount) * 2;
	if (m % 4 > 0)
	{
		ans += evenICount;
	}
	if (m % 4 > 1)
	{
		ans += evenICount;
	}
	if (m % 4 > 2)
	{
		ans += oddICount;
	}

	cout << ans << endl;

	return 0;
}
#endif


#include<iostream>
using namespace std;

int a[1000][1000] = { 0 };

int main()
{
	int w, h, res = 0;
	cin >> w >> h;

	for (int i = 0; i<w; i++)
	{
		for (int j = 0; j<h; j++)
		{
			if (a[i][j] == 0)
			{
				res++;
				if ((i + 2)<w) a[i + 2][j] = -1;
				if ((j + 2)<h) a[i][j + 2] = -1;
			}
		}
	}

	cout << res;
	
	return 0;
}