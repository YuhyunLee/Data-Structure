#include "CircularQueue.h"
#include <iostream>
using namespace std;

CQueue::CQueue(void)
{
	front = 0;
	rear = 0;
}

int CQueue::QIsEmpty(void)
{
	if (front == rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void CQueue::Enqueue(Data data)
{

	if (NextPosIdx(rear) == front)		// 큐가 꽉 차 있으면
	{
		cout << "Queue Memory Error!" << endl;
		exit(-1);
	}
	
	rear = NextPosIdx(rear);
	queArr[rear] = data;
}

Data CQueue::Dequeue(void)
{
	if (QIsEmpty())		// 큐가 텅 비어 있으면
	{
		cout << "Queue Memory Error!" << endl;
		exit(-1);
	}

	front = NextPosIdx(front);
	return queArr[front];
}

Data CQueue::QPeek(void)
{
	if (QIsEmpty())		// 큐가 텅 비어 있으면
	{
		cout << "Queue Memory Error!" << endl;
		exit(-1);
	}

	return queArr[NextPosIdx(front)];
}