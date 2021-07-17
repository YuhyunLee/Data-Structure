#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "UsefulHeap.h"

typedef HData PQData;

class PQueue : public Heap
{
public:
	PQueue(PriorityComp pc);
	int PQIsEmpty(void);

	void PEnqueue(PQData data);
	PQData PDequeue(void);
};


#endif // !__PRIORITY_QUEUE_H__