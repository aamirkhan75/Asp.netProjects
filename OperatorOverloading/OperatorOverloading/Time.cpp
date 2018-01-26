#include <iostream>
using namespace std;

class Time
{
private:
	int hr;
	int min;
	int sec;

public:
	Time();
	Time(int hr, int min, int sec);
	void showTime();
	Time add(Time tm);
	Time operator+(Time tm);
	// My task for today is to implement these two funcation.
	// it has same structure as add function but little different.
	Time subs(Time tm);
	Time operator-(Time tm);
	
};

Time::Time()
{
	hr = 0;
	min = 0;
	sec = 0;
}

Time::Time(int hr, int min, int sec)
{
	this->hr = hr;
	this->min = min;
	this->sec = sec;

}

void Time::showTime()
{
	cout << hr << ":" << min << ":" << sec << endl;
}

Time Time::add(Time tm)
{
	int tempSec, tempMin, tempHr;
	/*
	this-> point always point to the current obecj, which in our case tm2 is curent object when we using
	tm2.add(tm3);
	*/
	tempSec = tm.sec + this->sec;
	tempMin = tempSec / 60;
	tempSec = tempSec % 60;

	tempMin = tm.min + this->min + tempMin;
	tempHr = tempMin / 60;
	tempMin = tempMin % 60;

	tempHr = tm.hr + this->hr + tempHr;
	//cout << tempHr << ":" << tempMin << ":" << tempSec << endl;
	//this->hr = tempHr;
	//this->min = tempMin;
	//this->sec = tempSec;

	return Time(tempHr, tempMin, tempSec);
}

Time Time::operator+(Time tm)
{
	int tempSec, tempMin, tempHr;
	/*
	this-> point always point to the current obecj, which in our case tm2 is curent object when we using
	tm2.add(tm3);
	*/
	tempSec = tm.sec + this->sec;
	tempMin = tempSec / 60;
	tempSec = tempSec % 60;

	tempMin = tm.min + this->min + tempMin;
	tempHr = tempMin / 60;
	tempMin = tempMin % 60;

	tempHr = tm.hr + this->hr + tempHr;
	//cout << tempHr << ":" << tempMin << ":" << tempSec << endl;
	//this->hr = tempHr;
	//this->min = tempMin;
	//this->sec = tempSec;
	return Time(tempHr, tempMin, tempSec);
}

Time Time:: subs(Time tm)
{
	int tempSec, tempMin, tempHr;
	int borrow = 0;
	int bottomMin = 0, bottomHr = 0;
	// calculating seconds 
	if (this->sec < tm.sec)
	{
		borrow = 1;

		tempSec = (this->sec + 60) - tm.sec;
	}
	else {
		tempSec = this->sec - tm.sec;
	}

	// calculating minutes

	if (borrow > 0)
	{
		bottomMin = tm.min + 1;
		borrow = 0;
	}
	else {
		bottomMin = tm.min;
	}

	if (this->min < bottomMin)
	{
		tempMin = (this->min + 60) - bottomMin;
		borrow = 1;
	}
	else {
		tempMin = this->min - bottomMin;

	}

	// calculating hour

	if (borrow > 0)
	{
		bottomHr = tm.hr + 1;
		borrow = 0;
	}
	else {
		bottomHr = tm.hr;
	}

	tempHr = this->hr - bottomHr;
	return Time(tempHr, tempMin, tempSec);

}

Time Time::operator-(Time tm)
{
	int tempSec, tempMin, tempHr;
	int borrow = 0;
	int bottomMin = 0, bottomHr = 0;
	// calculating seconds 
	if (this->sec < tm.sec)
	{
		borrow = 1;

		tempSec = (this->sec + 60) - tm.sec;
	}
	else {
		tempSec = this->sec - tm.sec;
	}

	// calculating minutes

	if (borrow > 0)
	{
		bottomMin = tm.min + 1;
		borrow = 0;
	}
	else {
		bottomMin = tm.min;
	}

	if (this->min < bottomMin)
	{
		tempMin = (this->min + 60) - bottomMin;
		borrow = 1;
	}
	else {
		tempMin = this->min - bottomMin;

	}

	// calculating hour

	if (borrow > 0)
	{
		bottomHr = tm.hr + 1;
		borrow = 0;
	}
	else {
		bottomHr = tm.hr;
	}

	tempHr = this->hr - bottomHr;
	return Time(tempHr, tempMin, tempSec);

}


int main()
{

	Time tm1;
	Time tm2(12, 25, 49);
	Time tm3(1, 55, 59);
	tm1.showTime();
	tm2.showTime();
	tm3.showTime();
	Time tm100 = tm2.add(tm3);
	tm100.showTime();
	
	
	/*
	operator overloading.
	*/
	// tm2.opeator+(tm3);
	
	Time adding = tm2 + tm3;
	cout << "adding tm2 + tm3" << endl;
	adding.showTime();
	cout << " substracting from adding - tm2" << endl;
	Time substraction = adding.subs(tm2);
	
	substraction.showTime();

	substraction = adding - tm3;
	cout << " substracting from adding - tm3" << endl;
	substraction.showTime();
	return 0;

}