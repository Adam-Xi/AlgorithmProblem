/*
��������
����ƽ�������������Σ����ǵı�ƽ����ֱ������ϵ��X���Y�ᡣ
	����ÿ�����Σ����Ǹ�������һ����Զ�������꣬����������������εĽ��������
�����ʽ
  ��������������У�ÿ������һ�����Ρ�
	��ÿ���У��������ε�һ����Զ�������꣬ÿ��������궼����������ֵ������10^7��ʵ����ʾ��
�����ʽ
	���������һ��ʵ����Ϊ���������������С������λ��
��������
	1 1 3 3
	2 2 4 4
�������
	1.00

*/
#include<iostream>
using namespace std;
#include<algorithm>
#include<cmath>

int main()
{
	double x1, y1, x2, y2;
	double x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	double pos1 = min(max(x1, x2), max(x3, x4));
	double pos2 = max(min(x1, x2), min(x3, x4));
	double pos3 = min(max(y1, y2), max(y3, y4));
	double pos4 =  max(min(y1, y2), min(y3, y4));

	if (pos1 > pos2 && pos3 > pos4)
	{
		printf("%.2f\n", (pos1 - pos2) * (pos3 - pos4));
	}
	else
	{
		cout << "0.00" << endl;
	}

	return 0;
}