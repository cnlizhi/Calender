#pragma once
#include <iostream>
using namespace std;

#ifndef _CCALENDER_H
#define _CCALENDER_H

class CCalender
{
public:
	CCalender() : year(0), mon(0) {} //构造函数
	~CCalender() {} //析构函数 
	void Print(ostream& os) const; //输出函数
	friend istream& operator>> (istream& is, CCalender& r); //输入运算符重载
	friend ostream& operator<< (ostream& os, const CCalender& r); //输出运算符重载
protected:
	bool IsLeapYear(int ILYyear) const; //判断闰年 
	int DayOfMonth(int DOMyear, unsigned DOMmon) const; //判断每个月的天数 
	int FirstDate(int FDyear, unsigned FDmon) const; //判断这一年中每个月第一天的星期 
private:
	int year;
	unsigned mon;
};

#endif //_CCALENDER_H
