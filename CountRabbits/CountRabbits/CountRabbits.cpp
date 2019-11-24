/*
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子
假如兔子都不死，问每个月的兔子总数为多少？

输入描述:
输入int型表示month

输出描述 :
输出兔子总数int型

示例1
输入
9
输出
34
*/
#if 0
//本质上是斐波那契数列
#include <iostream>
using namespace std;

int Func(int n)
{
	int first = 1;
	int second = 0, third = 0;
	while (n--)
	{
		third = first + second;
		first = second;
		second = third;
	}
	return third;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << Func(n) << endl;
	}
	return 0;
}

#endif

#include <iostream>
using namespace std;

int main(){
	int m;
	while (cin >> m){
		int a = 1, b = 0, c = 0;//a:一个月兔子数，b：两个月兔子数，c：三个月兔子个数
		while (--m){//每过一个月兔子数变化
			c += b;
			b = a;
			a = c;
		}
		cout << a + b + c << endl;
	}
	return 0;
}