#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#include "ALEdge.h"

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	100

typedef Edge HData;
typedef int (*PriorityComp)(HData d1, HData d2);	// 함수포인터 별칭 선언

class Heap
{
	PriorityComp comp;			// 우선순위 비교 함수 포인터 변수
	int numOfData;				// 힙에 있는 데이터 개수
	HData heapArr[HEAP_LEN];	// 배열로 구현
public:
	Heap(PriorityComp pc);		// 생성자
	int HIsEmpty(void);

	int GetHiPriChildIDX(int idx);
	void HInsert(HData data);
	HData HDelete(void);
};

#endif // !__USEFUL_HEAP_H__

