#include<iostream>
using namespace std;
#include<string>

int main()
{
	int m, n;
	cin >> m >> n;
	string str;
	string str1;
	cin >> str;
	cin >> str1;

	if (m != n)
	{
		cout << "NO" << endl;
		return 0;
	}
	int count1[256] = { 0 };
	int count2[256] = { 0 };
	int i;
	for (i = 0; i < m; ++i)
	{
		count1[str[i]] += 1;
		count2[str1[i]] += 1;
	}
	int flag = 1;
	for (i = 0; i < m; ++i)
	{
		if (count1[str[i]] != count2[str[i]])
		{
			cout << "NO" << endl;
			flag = 0;
			break; 
		}
	}
	if (flag == 1)
	{
		cout << "YES" << endl;
	}

	return 0;
}