/*
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”

输入描述:
每个测试输入包含2个字符串

输出描述:
输出删除后的字符串
示例：
输入
They are students. 
aeiou
输出
Thy r stdnts.
*/

#include<iostream>
using namespace std;
#include<string>

int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int i;
	for (i = 0; i < s2.size(); i++)
	{
		int index;
		while ((index = s1.find(s2[i])) != -1)
		{
			s1.erase(index, 1);
		}
	}
	cout << s1 << endl;

	return 0;
}
