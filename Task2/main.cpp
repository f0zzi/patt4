#include <iostream>
#include "Bridge.h"
using namespace std;

int main()
{
	CPP cpp;
	Java java;
	cout << "Freelance:" << endl;
	Freelance prog("Al", &cpp);
	cout << "C++: " << prog.CalcSalary(100) << endl;
	prog.SetLanguage(&java);
	cout << "Java: " << prog.CalcSalary(100) << endl;	
	
	cout << "Office:" << endl;
	Office prog1("Al", &cpp);
	cout << "C++: " << prog1.CalcSalary(100) << endl;
	prog1.SetLanguage(&java);
	cout << "Java: " << prog1.CalcSalary(100) << endl;
	system("pause");
	return 0;
}