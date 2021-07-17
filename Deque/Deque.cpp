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

void Deque::DQAddFirst(Data data)		// �Ӹ��� �߰�
{
	Node* newNode = new Node;
	newNode->data = data;

	if (DQIsEmpty())		// ù ��° ����
		tail = newNode;
	else
		head->prev = newNode;

	newNode->prev = NULL;
	newNode->next = head;
	head = newNode;
}

void Deque::DQAddLast(Data data)		// ������ �߰�
{
	Node* newNode = new Node;
	newNode->data = data;

	if (DQIsEmpty())		// ù ��° ����
		head = newNode;
	else
		tail->next = newNode;
	
	newNode->next = NULL;
	newNode->prev = tail;
	tail = newNode;
}

Data Deque::DQRemoveFirst(void)			// �Ӹ����� ����
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

Data Deque::DQRemoveLast(void)			// �������� ����
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

Data Deque::DQGetFirst(void)			// �Ӹ����� ����
{
	if (DQIsEmpty())
	{
		cout << "Deque Memory Error!" << endl;
		exit(-1);
	}

	return head->data;
}

Data Deque::DQGetLast(void)				// �������� ����
{
	if (DQIsEmpty())
	{
		cout << "Deque Memory Error!" << endl;
		exit(-1);
	}

	return tail->data;
}