/*@Adam-Xi
2019-09-17
问题描述:
  Fibonacci数列的递推公式为：Fn=F(n-1)+F(n-2)，其中F1=F2=1。
  当n比较大时，Fn也非常大，现在我们想知道，Fn除以10007的余数是多少。
输入格式:
  输入包含一个整数n。
输出格式:
  输出一行，包含一个整数，表示Fn除以10007的余数。
说明：
  在本题中，答案是要求Fn除以10007的余数，因此我们只要能算出这个余数即可，
  而不需要先计算出Fn的准确值，再将计算的结果除以10007取余数，直接计算余数往往比先算出原数再取余简单。
数据规模与约定:
  1 <= n <= 1,000,000。
*/

#include<iostream>
using namespace std;

/*
//需要注意：正如说明中所说的，本题由于n的增大，增长的速度很快，当n到达一定值时，int类型就会存储不下
//而本题只要求除以10007后的余数，所以在求fib数的时候应该尽可能的控制它的大小，所以，在每次求fib数时求它除以10007的余数即可
int Fibonacci(int n)
{
	int front = 1;
	int last = 1;
	int sum = 0;
	int i = 3;
	while (i <= n)
	{
		sum = front + last;
		last = front;
		front = sum;
		i++;
	}
	return sum;
}
*/

int Fib(int n)
{
	int fib1 = 1;
	int fib2 = 1;
	int fib = 1;
	int i = 3;
	while (i <= n)
	{
		fib = (fib1 + fib2) % 10007;
		fib2 = fib1;
		fib1 = fib;
		i++;
	}
	return fib;
}
int main()
{
	int n = 0;
	cin >> n;
	cout << Fib(n) << endl;
	return 0;
}