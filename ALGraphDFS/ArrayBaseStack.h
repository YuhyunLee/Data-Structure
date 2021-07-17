#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE	1
#define FALSE	0
#define STACK_LEN	100

typedef int Data;

class ArrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
public:
	ArrayStack(void);
	int SIsEmpty(void);

	void SPush(Data data);
	Data SPop(void);
	Data SPeek(void);
};

typedef ArrayStack Stack;


#endif