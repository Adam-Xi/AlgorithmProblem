#if 0
#include <iostream>
#include <string>
using namespace std;
// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + " " + s2;
	cout << s2 << endl;
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<vector>
#include<string>

int main()
{
	vector<string> v;
	string s;
	while (cin >> s)
	{
		v.push_back(s);
	}
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			cout << v[i] << endl;
		}
		else
		{
			cout << v[i] << " ";
		}
	}
	return 0;
}

#endif

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		int length = str.length();
		string temp;
		vector<string> vec;
		for (int i = 0; i<length; i++)
		{
			if (str[i] != ' ')
				temp.push_back(str[i]);
			else
			{
				vec.push_back(temp);
				temp.clear();            //这里一定要清除
			}
		}
		vec.push_back(temp);        //需要把最后一个单词压入到vec中
		for (int j = vec.size() - 1; j>0; j--)  //倒序输出
			cout << vec[j] << ' ';
		cout << vec[0] << endl;
	}
}