#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define TRUE	1
#define FALSE	0

#define QUE_LEN		100
typedef int Data;

class CQueue
{
	Data queArr[QUE_LEN];
	int front;
	int rear;
public:
	CQueue(void);
	int QIsEmpty(void);
	void Enqueue(Data data);
	Data Dequeue(void);
	Data QPeek(void);
};

typedef CQueue Queue;

#endif // !__CIRCULAR_QUEUE_H__
