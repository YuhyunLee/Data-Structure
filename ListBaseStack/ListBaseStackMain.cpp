#include "ListBaseStack.h"
#include <iostream>
using namespace std;

int main(void)
{
	//// ���� ���� �� �ʱ�ȭ ////
	Stack stack;

	//// ������ �ֱ� ////
	stack.SPush(1); stack.SPush(2);
	stack.SPush(3); stack.SPush(4);
	stack.SPush(5);

	//// ������ ������ ////
	while (!stack.SIsEmpty())
		cout << stack.SPop() << " ";
	return 0;
}