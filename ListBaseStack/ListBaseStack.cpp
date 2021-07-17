#include "ListBaseStack.h"
#include <iostream>

#define TRUE	1
#define FALSE	0

void Node::SetData(Data data)
{
	this->data = data;
}
void Node::SetNext(Node* pnode)
{
	this->next = pnode;
}
Data Node::GetData(void)
{
	return data;
}
Node* Node::GetNext(void)
{
	return next;
}


Stack::ListStack(void)
{
	head = NULL;
}

int Stack::SIsEmpty(void)
{
	if (head == NULL)
		return TRUE;
	else
		return FALSE;
}

void Stack::SPush(Data data)
{
	Node* newNode = new Node;
	newNode->SetData(data);

	newNode->SetNext(head);
	head = newNode;
}

Data Stack::SPop(void)
{
	Node* rnode = head;
	Data rdata = head->GetData();

	head = head->GetNext();
	delete(rnode);
	return rdata;
}

Data Stack::SPeek(void)
{
	return head->GetData();
}