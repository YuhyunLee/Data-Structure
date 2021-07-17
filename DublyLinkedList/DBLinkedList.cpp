#include <iostream>
#include "DBLinkedList.h"

// ������
DBLinkedList::DBLinkedList(void) : head(NULL), numOfData(0)
{	}

// ����
void DBLinkedList::LInsert(Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = head;
	if (head != NULL)	// ù ��° ��尡 �ƴϸ�
		head->prev = newNode;

	newNode->prev = NULL;
	head = newNode;

	numOfData++;
}

// ù ��° ��� ����
int DBLinkedList::LFirst(Data* pdata)
{
	if (head == NULL)
		return FALSE;

	cur = head;
	*pdata = cur->data;
	return TRUE;
}

// �� ��° ���� ��� ����
int DBLinkedList::LNext(Data* pdata)
{
	if (cur->next == NULL)
		return FALSE;

	cur = cur->next;
	*pdata = cur->data;
	return TRUE;
}

// LNext�� �ݴ� �������� ����
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