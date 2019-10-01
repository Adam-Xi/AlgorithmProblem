// 十六进制转八进制
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int arr[10000001]; // 记录八进制的数
 
int main()
{
	string str;
	int n,m,i,num,j;
	
	cin>>n;
	while(n--)
	{
		cin>>str;
		m=str.length();
		// 转换成十进制
		num=0;
		for(i=m-1;i>=0;--i)
		{
			if(str[i]>='0'&&str[i]<='9')
				num+=pow(16,m-1-i)*(str[i]-'0');
			else if(str[i]>='A'&&str[i]<='F')
				num+=pow(16,m-1-i)*(str[i]-'A'+10);
		}
		
		i=0;
		while(num/8!=0)
		{
			arr[i]=num%8;
			num/=8;
			++i;
		}
		arr[i]=num;
 
		for(j=i;j>=0;--j)
			cout<<arr[j];
		cout<<endl;
 
	}
	return 0;
}