#include <iostream>
#include "DBLinkedList.h"
using namespace std;

int main(void)
{
	List list;
	Data data;

	// 8개의 노드 삽입
	list.LInsert(1); list.LInsert(2);
	list.LInsert(3); list.LInsert(4);
	list.LInsert(5); list.LInsert(6);
	list.LInsert(7); list.LInsert(8);

	// 조회하여 출력
	if (list.LFirst(&data))
	{
		cout << data << " ";

		while (list.LNext(&data))
		{
			cout << data << " ";
		}

		while (list.LPrevious(&data))
		{
			cout << data << " ";
		}
	}

	return 0;
}