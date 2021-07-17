#include "PriorityQueue.h"
#include <iostream>

PQueue::PQueue(PriorityComp pc) : Heap(pc)
{}

int PQueue::PQIsEmpty(void)
{
	return HIsEmpty();
}

void PQueue::PEnqueue(PQData data)
{
	HInsert(data);
}

PQData PQueue::PDequeue(void)
{
	return HDelete();
}