/*
问题描述
　　平面上有两个矩形，它们的边平行于直角坐标系的X轴或Y轴。
	对于每个矩形，我们给出它的一对相对顶点的坐标，请你编程算出两个矩形的交的面积。
输入格式
  　输入仅包含两行，每行描述一个矩形。
	在每行中，给出矩形的一对相对顶点的坐标，每个点的坐标都用两个绝对值不超过10^7的实数表示。
输出格式
	输出仅包含一个实数，为交的面积，保留到小数后两位。
样例输入
	1 1 3 3
	2 2 4 4
样例输出
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