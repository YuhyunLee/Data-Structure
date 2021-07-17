#include "Deque.h"
#include <iostream>
using namespace std;

int main(void)
{
	Deque deq;

	// �Ӹ��� �߰�
	deq.DQAddFirst(3);
	deq.DQAddFirst(2);
	deq.DQAddFirst(1);
	// ������ �߰�
	deq.DQAddLast(4);
	deq.DQAddLast(5);
	deq.DQAddLast(6);

	// �Ӹ����� ����
	while (!deq.DQIsEmpty())
		cout << deq.DQRemoveFirst() << " ";

	cout << endl;


	// �Ӹ��� �߰�
	deq.DQAddFirst(3);
	deq.DQAddFirst(2);
	deq.DQAddFirst(1);
	// ������ �߰�
	deq.DQAddLast(4);
	deq.DQAddLast(5);
	deq.DQAddLast(6);
	
	// �������� ����
	while (!deq.DQIsEmpty())
		cout << deq.DQRemoveLast() << " ";

	return 0;
}