//Calender
//written by Lizhi
//date 2018.3.16

#include "stdafx.h"
#include "CCalender.h"
#include <iostream>
#include <string>
using namespace std;

char cJudge(string str);

int main()
{
	cout << "______________________________________" << endl; //输出界面 
	cout << "         Perpetual Calendar" << endl;
	cout << "                  created by Lizhi" << endl;
	bool bExit = false;
	string com = "Y";
	CCalender Calender;
	while (!bExit)
	{
		if (cJudge(com) == 'Y')
		{
			cout << "Please set year and month:" << endl;
			cout << "(example: \"2018-3\" or \"2018,3\")" << endl;
			cin >> Calender;
			cout << Calender;
			cout << " Continue(Y/N)? ";
			cin >> com;
		}
		else if (cJudge(com) == 'N')
		{
			bExit = true;
		}
		else if (cJudge(com) == false)
		{
			cout << " Continue(Y/N)? ";
			cin >> com;
		}
	}
	return 0;
}

char cJudge(string str)
{
	string pArray[10] = { "Y","y","YES","Yes","yes","N","n","NO","No","no" };
	for (int i = 0; i < 10; i++)
	{
		if (str == pArray[i])
		{
			return i < 5 ? 'Y' : 'N';
		}
	}
	return false;
}
