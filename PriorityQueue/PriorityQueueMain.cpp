#include "PriorityQueue.h"
#include <iostream>
using namespace std;

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;		// �ƽ�Ű �ڵ� ������ ���. �ƽ�Ű �ڵ� ���� ���� ���� �켱������ ����!
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