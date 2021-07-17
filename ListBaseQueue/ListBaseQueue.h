#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

class Node
{
public:
	Data data;
	Node * next;
};

class LQueue
{
	Node * front;
	Node * rear;
public:
	LQueue(void);
	int QIsEmpty(void);

	void Enqueue(Data data);
	Data Dequeue(void);
	Data QPeek(void);
};

typedef LQueue Queue;


#endif