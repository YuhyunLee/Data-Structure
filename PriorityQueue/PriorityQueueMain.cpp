#include "PriorityQueue.h"
#include <iostream>
using namespace std;

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;		// 아스키 코드 값으로 계산. 아스키 코드 값이 작을 수록 우선순위가 높음!
}

int main(void)
{
	PQueue pq(DataPriorityComp);

	pq.PEnqueue('A');
	pq.PEnqueue('B');
	pq.PEnqueue('C');
	cout << pq.PDequeue() << endl;

	pq.PEnqueue('A');
	pq.PEnqueue('B');
	pq.PEnqueue('C');
	cout << pq.PDequeue() << endl;

	while (!pq.PQIsEmpty())
		cout << pq.PDequeue() << endl;

	return 0;
}