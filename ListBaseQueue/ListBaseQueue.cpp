#include <iostream>
#include <stdlib.h>
#include "ListBaseQueue.h"

LQueue::LQueue(void)
{
	front = NULL;
	rear = NULL;
}

int LQueue::QIsEmpty(void)
{
	if (front == NULL)
		return TRUE;
	else
		return FALSE;
}

void LQueue::Enqueue(Data data)
{
	Node* newNode = new Node;
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty())		// ù ��° ������ ����
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
}

Data LQueue::Dequeue(void)
{
	Node* delNode;
	Data retData;

	if (QIsEmpty())
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = front;
	retData = delNode->data;
	front = front->next;

	free(delNode);
	return retData;
}

Data LQueue::QPeek(void)
{
	if (QIsEmpty())
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return front->data;
}