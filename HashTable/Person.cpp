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
	cout << "�ֹε�Ϲ�ȣ: " << ssn << endl;
	cout << "�̸�: " << name << endl;
	cout << "�ּ�: " << addr << endl;
	cout << endl;
}