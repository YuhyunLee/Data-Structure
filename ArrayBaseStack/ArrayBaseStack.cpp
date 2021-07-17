#include <iostream>
#include "ArrayBaseStack.h"

ArrayStack::ArrayStack(void)
{
	topIndex = -1;
}

int ArrayStack::SIsEmpty(void)
{
	if (topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void ArrayStack::SPush(Data data)
{
	topIndex += 1;
	stackArr[topIndex] = data;
}

Data ArrayStack::SPop(void)
{
	int rIdx;

	if (SIsEmpty())
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = topIndex;
	topIndex -= 1;

	return stackArr[rIdx];
}

Data ArrayStack::SPeek(void)
{
	if (SIsEmpty())
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return stackArr[topIndex];
}