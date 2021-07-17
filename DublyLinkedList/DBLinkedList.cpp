#include <iostream>
#include "DBLinkedList.h"

// 생성자
DBLinkedList::DBLinkedList(void) : head(NULL), numOfData(0)
{	}

// 삽입
void DBLinkedList::LInsert(Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = head;
	if (head != NULL)	// 첫 번째 노드가 아니면
		head->prev = newNode;

	newNode->prev = NULL;
	head = newNode;

	numOfData++;
}

// 첫 번째 노드 참조
int DBLinkedList::LFirst(Data* pdata)
{
	if (head == NULL)
		return FALSE;

	cur = head;
	*pdata = cur->data;
	return TRUE;
}

// 두 번째 이후 노드 참조
int DBLinkedList::LNext(Data* pdata)
{
	if (cur->next == NULL)
		return FALSE;

	cur = cur->next;
	*pdata = cur->data;
	return TRUE;
}

// LNext의 반대 방향으로 참조
int DBLinkedList::LPrevious(Data* pdata)
{
	if (cur->prev == NULL)
		return FALSE;

	cur = cur->prev;
	*pdata = cur->data;
	return TRUE;
}

int DBLinkedList::LCount()
{
	return numOfData;
}