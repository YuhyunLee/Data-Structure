#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

typedef int Data;

class Node 
{
	Data data;
	Node* next;
public:
	void SetData(Data data);
	void SetNext(Node* pnode);
	Data GetData(void);
	Node* GetNext(void);
};

class ListStack 
{
	Node* head;
public:
	ListStack(void);
	int SIsEmpty(void);
	void SPush(Data data);
	Data SPop(void);
	Data SPeek(void);
};

typedef ListStack Stack;

#endif // !__LIST_BASE_STACK_H__

