#include "stdafx.h"
#include "CCalender.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool CCalender::IsLeapYear(int ILYyear) const//判断闰年
{
	return (ILYyear % 400 == 0 || (ILYyear % 100 != 0 && ILYyear % 4 == 0)) ? true : false;
}

int CCalender::DayOfMonth(int DOMyear, unsigned DOMmon) const//判断每个月的天数
{
	if (DOMmon < 8)
	{
		if (DOMmon == 2)
		{
			return IsLeapYear(DOMyear) ? 29 : 28;
		}
		return DOMmon % 2 ? 31 : 30;
	}
	else if (DOMmon < 13)
	{
		return DOMmon % 2 ? 30 : 31;
	}
	else
	{
		cerr << "The month is illegal!" << endl;
		exit(0);
	}
}

int CCalender::FirstDate(int FDyear, unsigned FDmon) const //判断这一年中每个月第一天的星期 
{
	int sum1 = 0; //推算每年1月1日星期 
	if (FDyear > 0)
	{
		while (FDyear > 1) //从公元1年开始 
		{
			FDyear--;
			sum1 += IsLeapYear(FDyear) ? 366 : 365;
		}
	}
	else if (FDyear < 0)
	{
		while (FDyear < 0) //从公元前1年开始
		{
			sum1 += IsLeapYear(FDyear) ? 366 : 365;
			FDyear++;
		}
	}
	int sum2 = 0; //推算每月1日的星期 
	while (FDmon > 1)
	{
		FDmon--;
		sum2 += DayOfMonth(FDyear, FDmon);
	}
	return ((sum1 % 7 + 1) % 7 + sum2) % 7;
}

void CCalender::Print(ostream& os) const //输出函数 
{
	if (year != 0)
	{
		os << "            " << year << "-" << mon << "\n" << endl;
		os << " | SUN MON TUE WEN THU FRI STA |\n |"; //表头 
		for (int i = 0; i < FirstDate(year, mon); i++) //起始空格 
		{
			os << "    ";
		}
		for (int i = 1; i <= DayOfMonth(year, mon); i++) //输入数字 
		{
			if ((i + FirstDate(year, mon)) % 7 == 0)
			{
				os << setw(4) << i << " |\n |";
			}
			else
			{
				os << setw(4) << i;
			}
		}
		for (int i = 0; i < (7 - (FirstDate(year, mon) + DayOfMonth(year, mon)) % 7); i++) //末尾空格 
		{
			os << "    ";
		}
	}
	else //公元0年处理 
	{
		os << "The year is illegal!" << endl;
	}
}

istream& operator>> (istream& is, CCalender& r) //输入运算符重载
{
	is >> r.year;
	is.ignore();
	is >> r.mon;
	return is;
}

ostream& operator<< (ostream& os, const CCalender& r) //输出运算符重载
{
	r.Print(os);
	return os;
}
