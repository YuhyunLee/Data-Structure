#include "UsefulHeap.h"
#include <iostream>

Heap::Heap(PriorityComp pc)
{
	numOfData = 0;
	comp = pc;
}

int Heap::HIsEmpty(void)
{
	if (numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx / 2;		// 정수형으로 반환
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

// 두 개의 자식 노드 중 우선 순위가 높은 자식 노드의 인덱스 값을 반환
int Heap::GetHiPriChildIDX(int idx)		// 부모노드의 인덱스 값 인자로 전달
{
	if (GetLChildIDX(idx) > numOfData)
		return 0;
	else if (GetLChildIDX(idx) == numOfData)
		return GetLChildIDX(idx);
	else
	{
		if (comp(heapArr[GetLChildIDX(idx)], heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void Heap::HInsert(HData data)
{
	// 1. 들어온 데이터는 마지막 노드에 저장
	// 2. 부모노드와 비교하며 우선순위가 높으면 바꾸기
	// 3. 제자리를 찾으면 데이터 넣어주기
	int idx = numOfData + 1;

	while (idx != 1)
	{
		if (comp(data, heapArr[GetParentIDX(idx)]) > 0)
		{
			heapArr[idx] = heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	heapArr[idx] = data;
	numOfData += 1;
}

HData Heap::HDelete(void)
{
	// 1. 루트 노드의 데이터 삭제
	// 2. 마지막 노드와 자식 노드들 비교하며 우선순위가 높으면 바꾸기
	// 3. 제자리를 찾으면 마지막 노드의 데이터 넣어주기
	HData retdata = heapArr[1];				// 루트 노드의 데이터
	HData lastElem = heapArr[numOfData];	// 마지막 노드의 데이터

	int parentIdx = 1;		// 마지막 노드가 위치할 인덱스 정보를 담고 있는 변수
	int childIdx;

	while (childIdx = GetHiPriChildIDX(parentIdx))	// 자식노드가 없으면 0 반환해서 빠져나감
	{
		if (comp(lastElem, heapArr[childIdx]) < 0)
		{
			heapArr[parentIdx] = heapArr[childIdx];		// 실제로 옮김
			parentIdx = childIdx;	// 인덱스 정보만 변경
		}
		else
			break;
	}

	heapArr[parentIdx] = lastElem;
	numOfData -= 1;
	return retdata;
}