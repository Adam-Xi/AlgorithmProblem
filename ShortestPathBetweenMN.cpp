/*
@Adam-Xi
2019-09-16
题目描述：
X星球居民小区的楼房全是一样的，并且按矩阵样式排列。其楼房的编号为1,2,3...

当排满一行时，从下一行相邻的楼往反方向排号。

比如：当小区排号宽度为6时，开始情形如下：

1  2  3  4  5  6

12 11 10 9  8  7

13 14 15 .....

我们的问题是：已知了两个楼号m和n，需要求出它们之间的最短移动距离（不能斜线方向移动）

输入为3个整数w m n，空格分开，都在1到10000范围内

要求输出一个整数，表示m n 两楼间最短移动距离。

*/


#include<iostream>
#include<cmath>
using namespace std;

int OKrow(int w, int num)  //确定行号
{
	return num % w ? (num / w - 1) : (num / w);
}
int  OKcol(int w, int num)  //确定列号
{
	if ((num & 1) == 1) {//第偶数行,顺着走

		return (w - num % w) % w;

	}
	else {//奇数行

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