#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN		50

class Person
{
	int ssn;	// �ֹε�Ϲ�ȣ
	char name[STR_LEN];
	char addr[STR_LEN];
public:
	Person(int s, const char* n, const char* a);
	int GetSSN(void);
	void ShowPerInfo(void);
};


#endif // !__PERSON_H__
