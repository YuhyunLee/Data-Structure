#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(int s, const char* n, const char* a)
{
	ssn = s;
	strcpy(name, n);
	strcpy(addr, a);
}

int Person::GetSSN(void)
{
	return ssn;
}

void Person::ShowPerInfo(void)
{
	cout << "주민등록번호: " << ssn << endl;
	cout << "이름: " << name << endl;
	cout << "주소: " << addr << endl;
	cout << endl;
}