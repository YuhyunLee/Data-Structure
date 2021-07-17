#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

class Node
{
public:
	Data data;
	Node* prev;
	Node* next;
};

class DLDeque
{
	Node* head;
	Node* tail;
public:
	DLDeque(void);
	int DQIsEmpty(void);
	void DQAddFirst(Data data);
	void DQAddLast(Data data);
	Data DQRemoveFirst(void);
	Data DQRemoveLast(void);
	Data DQGetFirst(void);
	Data DQGetLast(void);
};

typedef DLDeque Deque;

#endif // !__DEQUE_H__

