#include "CircularQueue.h"
#include <iostream>
using namespace std;

int main(void)
{
	//// Queue의 생성 및 초기화 ////
	Queue q;

	//// 데이터 넣기 ////
	q.Enqueue(1); q.Enqueue(2);
	q.Enqueue(3); q.Enqueue(4);
	q.Enqueue(5);

	//// 데이터 꺼내기 ////
	while (!q.QIsEmpty())
		cout << q.Dequeue() << " ";

	return 0;
}