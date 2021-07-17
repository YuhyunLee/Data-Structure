#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

// ���
class Node {
public:
	Data data;
	Node* next;
	Node* prev;
};

// ����� ���Ḯ��Ʈ
class DBLinkedList {
	Node* head;
	Node* cur;
	int numOfData;
public:
	DBLinkedList();				// ������
	void LInsert(Data data);	// ����
	int LFirst(Data* pdata);	// ù ��° ��� ����
	int LNext(Data* pdata);		// �� ��° ���� ��� ����
	int LPrevious(Data* pdata);	// LNext�� �ݴ� �������� ����
	int LCount();
};

typedef DBLinkedList List;

#endif // !__DB_LINKED_LIST_H__

