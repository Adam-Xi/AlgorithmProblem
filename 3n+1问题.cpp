/*题目描述
考虑如下的序列生成算法：从整数 n 开始，如果 n 是偶数，把它除以 2；
                                       如果 n 是奇数，把它乘 3 加1。
    用新得到的值重复上述步骤，直到 n = 1 时停止。
    例如，n = 22 时该算法生成的序列是：22，11，34，17，52，26，13，40，20，10，5，16，8，4，2，1

人们猜想（没有得到证明）对于任意整数 n，该算法总能终止于 n = 1。这个猜想对于至少 1 000 000内的整数都是正确的。
对于给定的 n，该序列的元素（包括 1）个数被称为 n 的循环节长度。
在上述例子中，22 的循环节长度为 16。
输入两个数 i 和 j，你的任务是计算 i 到 j（包含 i 和 j）之间的整数中，循环节长度的最大值。
*/


//由于本题中给出的上限不算太大，int足可以解决，但是当上限到达一定值的时候，就需要考虑溢出问题，此时可选用long 或 long long 甚至大数数组来解决
#include<iostream>
using namespace std;

int Func(int i)
{
	if (i < 1)
	{
		return 0;
	}
	if (i == 1)
	{
		return 1;
	}
	if (i % 2) //奇数
	{
		i = 3 * i + 1;
	}
	else //偶数
	{
		i = i / 2;
	}
	return Func(i) + 1;
}

int choose(int i, int j)
{
	int max = 0;
	for (int m = i; m <= j; m++)
	{
		int tmp = Func(m);
		//cout << i << " " << tmp << endl;
		if (tmp > max)
		{
			max = tmp;
		}
	}
	return max;
}

int main()
{
	int i = 0, j = 0;
	cin >> i >> j;
	int res = choose(i, j);
	//int count = Func(i);
	cout << i << " " << j << " " << res << endl;

	return 0;
}