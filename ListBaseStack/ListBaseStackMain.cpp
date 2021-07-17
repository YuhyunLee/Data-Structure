#include "ListBaseStack.h"
#include <iostream>
using namespace std;

int main(void)
{
	//// 스택 생성 및 초기화 ////
	Stack stack;

	//// 데이터 넣기 ////
	stack.SPush(1); stack.SPush(2);
	stack.SPush(3); stack.SPush(4);
	stack.SPush(5);

	//// 데이터 꺼내기 ////
	while (!stack.SIsEmpty())
		cout << stack.SPop() << " ";
	return 0;
}