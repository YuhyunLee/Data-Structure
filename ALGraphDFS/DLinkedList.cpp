#include "DLinkedList.h"
#include <iostream>

//**������**//
LinkedList::LinkedList(void)
{
	head = new Node;		// ���� ��� ����
	head->next = NULL;
	comp = NULL;
	numOfData = 0;
}

//**�Է�**//
void LinkedList::FInsert(LData data)		// ����Ʈ�� �Ӹ��� ��� �߰�
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = head->next;
	head->next = newNode;

	numOfData++;
}

void LinkedList::SInsert(LData data)		// ���ı������� ���İ�� �� ��� �߰�
{
	Node* newNode = new Node;
	Node* pred = head;				// ���� �� ã�� �ڸ��� �� �ڸ�
	newNode->data = data;

	while (pred->next != NULL &&				// (���� ��� ��) ù ��° ����� �����Ͷ� �߰��� ����� ������ ��
		comp(data, pred->next->data) != 0)		// 0 �̸� ù ��° �Ű������� ���� ���� �ռ�, �ƴϸ� �� ��°�� �ռ�
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	numOfData++;
}

void LinkedList::LInsert(LData data)
{
	if (comp == NULL)		// ���� ������ ���� ���� �ʾҴٸ�
		FInsert(data);
	else
		SInsert(data);
}

//**Ž��**//
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

//**����**//
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