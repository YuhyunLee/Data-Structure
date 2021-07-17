#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

// 노드
class Node {
public:
	Data data;
	Node* next;
	Node* prev;
};

// 양방향 연결리스트
class DBLinkedList {
	Node* head;
	Node* cur;
	int numOfData;
public:
	DBLinkedList();				// 생성자
	void LInsert(Data data);	// 삽입
	int LFirst(Data* pdata);	// 첫 번째 노드 참조
	int LNext(Data* pdata);		// 두 번째 이후 노드 참조
	int LPrevious(Data* pdata);	// LNext의 반대 방향으로 참조
	int LCount();
};

typedef DBLinkedList List;

#endif // !__DB_LINKED_LIST_H__

