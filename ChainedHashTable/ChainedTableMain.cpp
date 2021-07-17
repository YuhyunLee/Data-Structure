#include <iostream>
#include "Person.h"
#include "Table2.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTbl(MyHashFunc);
	Person* np;		// ���忡 ���� ������
	Person* sp;		// Ž���� ���� ������
	Person* rp;		// ������ ���� ������


	// ������ ����
	np = new Person(20120003, "Lee", "Seoul");
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(20130012, "Kim", "Jeju");
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(20170049, "Han", "Kangwon");
	myTbl.TBLInsert(np->GetSSN(), np);

	// ������ Ž��
	sp = myTbl.TBLSearch(20120003);
	if (sp != NULL)
		sp->ShowPerInfo();

	sp = myTbl.TBLSearch(20130012);
	if (sp != NULL)
		sp->ShowPerInfo();

	sp = myTbl.TBLSearch(20170049);
	if (sp != NULL)
		sp->ShowPerInfo();

	// ������ ����
	rp = myTbl.TBLDelete(20120003);
	if (rp != NULL)
		delete(rp);

	rp = myTbl.TBLDelete(20130012);
	if (rp != NULL)
		delete(rp);

	rp = myTbl.TBLDelete(20170049);
	if (rp != NULL)
		delete(rp);


	return 0;
}