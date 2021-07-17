#include "Deque.h"
#include <iostream>
using namespace std;

Deque::DLDeque(void)
{
	head = NULL;
	tail = NULL;
}

int Deque::DQIsEmpty(void)
{
	if (head == NULL)
		return TRUE;
	else
		return FALSE;
}

void Deque::DQAddFirst(Data data)		// 머리에 추가
{
	Node* newNode = new Node;
	newNode->data = data;

	if (DQIsEmpty())		// 첫 번째 노드면
		tail = newNode;
	else
		head->prev = newNode;

	newNode->prev = NULL;
	newNode->next = head;
	head = newNode;
}

void Deque::DQAddLast(Data data)		// 꼬리에 추가
{
	Node* newNode = new Node;
	newNode->data = data;

	if (DQIsEmpty())		// 첫 번째 노드면
		head = newNode;
	else
		tail->next = newNode;
	
	newNode->next = NULL;
	newNode->prev = tail;
	tail = newNode;
}

Data Deque::DQRemoveFirst(void)			// 머리에서 삭제
{
	if (DQIsEmpty())
	{
		cout << "Deque Memory Error!" << endl;
		exit(-1);
	}

	Node* rDeque = head;
	Data rdata = rDeque->data;
	
	head = head->next;
	delete(rDeque);

	if (head == NULL)
		tail = NULL;
	else
		head->prev = NULL;

	return rdata;	
}

Data Deque::DQRemoveLast(void)			// 꼬리에서 삭제
{
	if (DQIsEmpty())
	{
		cout << "Deque Memory Error!" << endl;
		exit(-1);
	}

	Node* rDeque = tail;
	Data rdata = rDeque->data;

	tail = tail->prev;
	delete(rDeque);

	if (tail == NULL)
		head = NULL;
	else
		tail->next = NULL;
	
	return rdata;
}

Data Deque::DQGetFirst(void)			// 머리에서 참조
{
	if (DQIsEmpty())
	{
		cout << "Deque Memory Error!" << endl;
		exit(-1);
	}

	return head->data;
}

Data Deque::DQGetLast(void)				// 꼬리에서 참조
{
	if (DQIsEmpty())
	{
		cout << "Deque Memory Error!" << endl;
		exit(-1);
	}

	return tail->data;
}