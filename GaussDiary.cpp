/*
@Adam-Xi
2019-09-21
������Ŀ�����ű����Ľ�ʡ��AB���һ�⣨����⣩
����˸����𰸣���Ҫ�������˼·���ر�������ھ����������ô����

[��������]
����ѧ�Ҹ�˹�и���ϰ�ߣ�������ζ�Ҫ���ռǡ�
�����ռ��и����ڲ�ͬ�ĵط������Ӳ�ע�������գ�������һ���������棬���磺4210
��������֪�����Ǹ������������ڣ�����ʾ��һ���Ǹ�˹������ĵڼ��졣
�����Ҳ�Ǹ���ϰ�ߣ���ʱʱ�̿����������ˣ������ֹ�ȥһ�죬���ж���ʱ����������˷��أ�
��˹�����ڣ�1777��4��30�ա�
�ڸ�˹���ֵ�һ����Ҫ������ռ��ϱ�ע�ţ�5343����˿���������ǣ�1791��12��15�ա�
��˹��ò�ʿѧλ�������ռ��ϱ��ţ�8113
���������˹��ò�ʿѧλ�������ա�
�ύ�𰸵ĸ�ʽ�ǣ�yyyy-mm-dd, ���磺1980-03-21
*/
#include<iostream>
using namespace std;

class Date
{
public:
	//�������⣬�ɵ�����ռ��ϱ�ע 1����Ϊ1777-04-30.��Ϊ��˹����������Ϊһ�죡
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