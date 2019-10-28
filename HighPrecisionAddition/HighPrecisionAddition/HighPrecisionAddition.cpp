/*
问题描述
	输入两个整数a和b，输出这两个整数的和。a和b都不超过100位。
算法描述
	由于a和b都比较大，所以不能直接使用语言中的标准数据类型来存储。对于这种问题，一般使用数组来处理。
	定义一个数组A，A[0]用于存储a的个位，A[1]用于存储a的十位，依此类推。同样可以用一个数组B来存储b。
	计算c = a + b的时候，首先将A[0]与B[0]相加，如果有进位产生，则把进位（即和的十位数）存入r，把和的个位数存入C[0]，即C[0]等于(A[0]+B[0])%10。然后计算A[1]与B[1]相加，这时还应将低位进上来的值r也加起来，即C[1]应该是A[1]、B[1]和r三个数的和．如果又有进位产生，则仍可将新的进位存入到r中，和的个位存到C[1]中。依此类推，即可求出C的所有位。
	最后将C输出即可。
输入格式
	输入包括两行，第一行为一个非负整数a，第二行为一个非负整数b。两个整数都不超过100位，两数的最高位都不是0。
输出格式
	输出一行，表示a + b的值。
样例输入
	20100122201001221234567890
	2010012220100122
样例输出
	20100122203011233454668012

*/


#if 0

#pragma warning (disable:4996)
#include<iostream>
using namespace std;
#include<cstring>

//思想：
//输入处理：
//由于一次输入一行的数据，但是并不知道数据的具体长度，没办法通过for循环来控制整形数组的大小，
//所以另辟蹊径，将一次的输入看做一个字符数组，回车就是终止条件，然后在给字符数组求长度就是一次输入的整型个数
//然后将字符数组的每一项减去字符0的ASCII码即48，就是他们分别对应的整数大小，并且由于输入的字符串逆序，要使整型数组从左向右，位数依次增大

//加法处理：
//先判断两个整型数组的大小，让结果数组的长度等于最长的操作数数组的长度，然后以该长度为基准，从最低位开始按位相加，即从整形数组的0号下标开始，往最大下标进行

//输出处理
//逆序输出
int main()
{
	int a[401] = { 0 }, alen;
	int b[401] = { 0 }, blen;
	int c[400] = { 0 }, clen;
	char s[400];
	int i;
	scanf("%s", s);
	alen = strlen(s);
	for (i = 1; i <= alen; ++i)
	{
		a[i] = s[alen - i] - 48;
	}
	scanf("%s", s);
	blen = strlen(s);
	for (i = 1; i <= blen; ++i)
	{
		b[i] = s[blen - i] - 48;
	}
	if (alen > blen)
	{
		clen = alen;
	}
	else
	{
		clen = blen;
	}
	for (i = 1; i <= clen; ++i)
	{
		c[i] = a[i] + b[i];
	}
	for (i = 1; i <= clen; ++i)
	{
		if (c[i] >= 10)
		{
			c[i + 1] += (c[i] / 10);
			c[i] %= 10;
		}
	}
	if (c[clen + 1] > 0)
	{
		clen++;
	}
	for (i = clen; i >= 1; --i)
	{
		printf("%d", c[i]);
	}
	printf("\n");

	return 0;
}

#endif


#pragma warning (disable:4996)
#include<iostream>
using namespace std;
#include<cstring>

int main()
{
	int a[401] = { 0 }, alen;
	int b[401] = { 0 }, blen;
	int c[401] = { 0 }, clen;
	char s[400] = { 0 };
	int i;

	scanf("%s", s);  //s数组从0号下标开始存放整型数值,从左到右，从高位到低位
	alen = strlen(s);
	for (i = 1; i <= alen; ++i)
	{
		a[i] = s[alen - i] - '0';  //a数组从1号下标开始存放整型数值，从左到右，从低位到高位
	}

	scanf("%s", s);
	blen = strlen(s);
	for (i = 1; i <= blen; ++i)
	{
		b[i] = s[blen - i] - '0';  //b数组从1号下标开始存放整型数值，从左到右，从低位到高位
	}
	
	if (alen > blen)
	{
		clen = alen;
	}
	else
	{
		clen = blen;
	}

	for (i = 1; i <= clen; ++i)
	{
		c[i] = a[i] + b[i];  //加法处理，两个相加放入c中
		if (c[i] >= 10)  //检测是否需要进位
		{
			c[i] = c[i] + c[i] % 10;
			c[i + 1] = c[i] / 10;
		}
	}
	for (i = clen; i > 0; --i)
	{
		cout << c[i];
	}
	cout << endl;

	return 0;
}