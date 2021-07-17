#include "Deque.h"
#include <iostream>
using namespace std;

int main(void)
{
	Deque deq;

	// 머리에 추가
	deq.DQAddFirst(3);
	deq.DQAddFirst(2);
	deq.DQAddFirst(1);
	// 꼬리에 추가
	deq.DQAddLast(4);
	deq.DQAddLast(5);
	deq.DQAddLast(6);

	// 머리에서 삭제
	while (!deq.DQIsEmpty())
		cout << deq.DQRemoveFirst() << " ";

	cout << endl;


	// 머리에 추가
	deq.DQAddFirst(3);
	deq.DQAddFirst(2);
	deq.DQAddFirst(1);
	// 꼬리에 추가
	deq.DQAddLast(4);
	deq.DQAddLast(5);
	deq.DQAddLast(6);
	
	// 꼬리에서 삭제
	while (!deq.DQIsEmpty())
		cout << deq.DQRemoveLast() << " ";

	return 0;
}