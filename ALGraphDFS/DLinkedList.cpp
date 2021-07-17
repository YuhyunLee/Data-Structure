#include "DLinkedList.h"
#include <iostream>

//**생성자**//
LinkedList::LinkedList(void)
{
	head = new Node;		// 더미 노드 생성
	head->next = NULL;
	comp = NULL;
	numOfData = 0;
}

//**입력**//
void LinkedList::FInsert(LData data)		// 리스트의 머리에 노드 추가
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = head->next;
	head->next = newNode;

	numOfData++;
}

void LinkedList::SInsert(LData data)		// 정렬기준으로 정렬계산 후 노드 추가
{
	Node* newNode = new Node;
	Node* pred = head;				// 정렬 후 찾은 자리의 앞 자리
	newNode->data = data;

	while (pred->next != NULL &&				// (더미 노드 뒤) 첫 번째 노드의 데이터랑 추가할 노드의 데이터 비교
		comp(data, pred->next->data) != 0)		// 0 이면 첫 번째 매개변수가 정렬 순서 앞섬, 아니면 두 번째가 앞섬
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	numOfData++;
}

void LinkedList::LInsert(LData data)
{
	if (comp == NULL)		// 정렬 기준이 마련 되지 않았다면
		FInsert(data);
	else
		SInsert(data);
}

//**탐색**//
int LinkedList::LFirst(LData* pdata)
{
	if (head->next == NULL)
		return FALSE;

	before = head;
	cur = head->next;

	*pdata = cur->data;
	return TRUE;
}

int LinkedList::LNext(LData* pdata)
{
	if (cur->next == NULL)
		return FALSE;

	before = cur;
	cur = cur->next;

	*pdata = cur->data;
	return TRUE;
}

//**삭제**//
LData LinkedList::LRemove(void)
{
	Node* rpos = cur;
	LData rdata = rpos->data;

	before->next = cur->next;
	cur = before;

	delete(rpos);
	numOfData--;
	return rdata;
}


int LinkedList::LCount(void)
{
	return numOfData;
}

void LinkedList::SetSortRule(int (*comp)(LData d1, LData d2))
{
	this->comp = comp;
}