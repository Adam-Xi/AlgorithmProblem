/*
@Adam-Xi
2019-09-16
��Ŀ������
X�������С����¥��ȫ��һ���ģ����Ұ�������ʽ���С���¥���ı��Ϊ1,2,3...

������һ��ʱ������һ�����ڵ�¥���������źš�

���磺��С���źſ��Ϊ6ʱ����ʼ�������£�

1  2  3  4  5  6

12 11 10 9  8  7

13 14 15 .....

���ǵ������ǣ���֪������¥��m��n����Ҫ�������֮�������ƶ����루����б�߷����ƶ���

����Ϊ3������w m n���ո�ֿ�������1��10000��Χ��

Ҫ�����һ����������ʾm n ��¥������ƶ����롣

*/


#include<iostream>
#include<cmath>
using namespace std;

int OKrow(int w, int num)  //ȷ���к�
{
	return num % w ? (num / w - 1) : (num / w);
}
int  OKcol(int w, int num)  //ȷ���к�
{
	if ((num & 1) == 1) {//��ż����,˳����

		return (w - num % w) % w;

	}
	else {//������

		return (num % w - 1 + w) % w;

	}
}
int ShortestPath(int w, int m, int n)
{
	int posR1 = OKrow(w, m);
	int posC1 = OKrow(w, m);
	int posR2 = OKrow(w, n);
	int posC2 = OKcol(w, n);

	return abs(posR1 - posR2) + abs(posC1 - posC2);
}
int main()
{
	int w, m, n;
	cin >> w >> m >> n;
	cout << ShortestPath(w, m, n) << endl;

	return 0;
}