#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#include "ALEdge.h"

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	100

typedef Edge HData;
typedef int (*PriorityComp)(HData d1, HData d2);	// �Լ������� ��Ī ����

class Heap
{
	PriorityComp comp;			// �켱���� �� �Լ� ������ ����
	int numOfData;				// ���� �ִ� ������ ����
	HData heapArr[HEAP_LEN];	// �迭�� ����
public:
	Heap(PriorityComp pc);		// ������
	int HIsEmpty(void);

	int GetHiPriChildIDX(int idx);
	void HInsert(HData data);
	HData HDelete(void);
};

#endif // !__USEFUL_HEAP_H__

