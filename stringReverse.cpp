#include<iostream>
using namespace std;
#include<string>

int main()
{
	int m, n;
	cin >> m >> n;
	string str;
	string str1;
	//getline(cin, str);
	//getline(cin, str1);
	cin >> str;
	cin >> str1;
	if (m != n)
	{
		cout << "NO" << endl;
		return 0;
	}

	str.append(str);
	int flag = 1;
	size_t start = str.find(str1[0]);
	if (start == string::npos)
	{
		cout << "NO" << endl;
		return 0;
	}
	str = str.substr(start);
	while (flag == 1 && str.size() > m)
	{
		start = str.find(str1[0]);
		if (0 == str1.compare(str.substr(start, n)))
		{
			flag = 0;
			cout << "YES" << endl;
		}
		else
		{
			str = str.substr(start + 1);
		}
	}
	if (flag == 1)
	{
		cout << "NO" << endl;
	}
	return 0;
}