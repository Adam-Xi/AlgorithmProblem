/*
@Adam-Xi
2019-09-21
本周题目是蓝桥杯第四届省赛AB组第一题（填空题）
请除了给出答案，还要给出你的思路，特别是如果在竞赛中你会怎么做？

[问题描述]
大数学家高斯有个好习惯：无论如何都要记日记。
他的日记有个与众不同的地方，他从不注明年月日，而是用一个整数代替，比如：4210
后来人们知道，那个整数就是日期，它表示那一天是高斯出生后的第几天。
这或许也是个好习惯，它时时刻刻提醒着主人：日子又过去一天，还有多少时光可以用于浪费呢？
高斯出生于：1777年4月30日。
在高斯发现的一个重要定理的日记上标注着：5343，因此可算出那天是：1791年12月15日。
高斯获得博士学位的那天日记上标着：8113
请你算出高斯获得博士学位的年月日。
提交答案的格式是：yyyy-mm-dd, 例如：1980-03-21
*/
#include<iostream>
using namespace std;

class Date
{
public:
	//依据题意，可得如果日记上标注 1，则为1777-04-30.因为高斯把他出生算为一天！
	Date(int year = 1777, int month = 4, int day = 29)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	Date operator+(int day)
	{
		Date tmp(*this);
		int CurMonthDay = 0;
		day += tmp._day;
		while (day > (CurMonthDay = GetDaysOfMonth(tmp._year, tmp._month)))
		{
			tmp._month++;
			day -= CurMonthDay;
			if (tmp._month > 12)
			{
				tmp._year++;
				tmp._month = 1;
			}
		}
		tmp._day = day;
		return tmp;
	}
	int GetDaysOfMonth(int year, int month)
	{
		int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (IsLeapYear(year))
		{
			days[2]++;
		}
		return days[month];
	}
	bool IsLeapYear(int year)
	{
		if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
		{
			return true;
		}
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date birth;
	birth = birth + 8113;
	return 0;
}
//1799.7.16