#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__
#include "Slot2.h"

#define TRUE	1
#define FALSE	0

typedef Slot LData;

class Node
{
public:
	LData data;
	Node* next;
};

class LinkedList
{
public:
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
	int (*comp)(LData d1, LData d2);

	LinkedList(void);

	void LInsert(LData data);
	void FInsert(LData data);
	void SInsert(LData data);

	int LFirst(LData* pdata);
	int LNext(LData* pdata);

	LData LRemove(void);
	int LCount(void);

	void SetSortRule(int (*comp)(LData d1, LData d2));
};


typedef LinkedList List;


#endif