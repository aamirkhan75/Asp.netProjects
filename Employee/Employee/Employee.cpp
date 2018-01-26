#include <iostream>
#include <string>
using namespace std;

class Employee{
private:
	string name;
	string empId;
	string employer;
	double salary;

public:
	Employee();
	Employee(string name, string empId, string employer, double salary);
	void showDetails();
};

Employee::Employee()
{
	this->name = "";
	this->empId = "";
	this->employer = "";
	this->salary = 0;
}
Employee::Employee(string name, string empId, string employer, double salary)
{
	this->name = name;
	this->empId = empId;
	this->employer = employer;
	this->salary = salary;
}

void Employee:: showDetails()
{
	cout << name << endl;
	cout << empId << endl;
	cout << employer << endl;
	cout << salary << endl;
}

class FullTimeEmp :public Employee
{
private:
	string timing;
	string insuranceNum;
public:
	FullTimeEmp();
	FullTimeEmp(string name, string empId, string employer, double salary, string timing, string insuranceNum);
	void showFullTimeDetails();
};
FullTimeEmp::FullTimeEmp()
{
	this->timing = "";
	this->insuranceNum = "";

}
FullTimeEmp::FullTimeEmp(string name, string empId, string employer, double salary, string timing, string insuranceNum)
	:Employee(name, empId, employer, salary)
{
	this->timing = timing;
	this->insuranceNum = insuranceNum;

}
void FullTimeEmp::showFullTimeDetails()
{
	showDetails();
	cout << "Inside show full time details" << endl;
	cout << timing << endl;
	cout << insuranceNum << endl;
}
int main()
{
	Employee emp("Jhon", "JT124596", "MBCI", 20150);
	emp.showDetails();
	FullTimeEmp fte("Jhon", "JT124596", "MBCI", 20150,"9 to 5", "pa457934g");
	cout << "priting show full time details" << endl;
	fte.showFullTimeDetails();

	return 0;
}