#ifndef __TABLE_H__
#define __TABLE_H__
#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL		100
typedef int (*HashFunc)(Key k);

class Table
{
	List tbl[MAX_TBL];
	HashFunc hf;
public:
	Table(HashFunc f);
	void TBLInsert(Key k, Value v);		// ����
	Value TBLDelete(Key k);				// ����
	Value TBLSearch(Key k);				// Ž��
};

#endif // !__TABLE_H__
