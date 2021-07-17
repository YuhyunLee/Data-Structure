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
	return idx / 2;		// ���������� ��ȯ
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

// �� ���� �ڽ� ��� �� �켱 ������ ���� �ڽ� ����� �ε��� ���� ��ȯ
int Heap::GetHiPriChildIDX(int idx)		// �θ����� �ε��� �� ���ڷ� ����
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
	// 1. ���� �����ʹ� ������ ��忡 ����
	// 2. �θ���� ���ϸ� �켱������ ������ �ٲٱ�
	// 3. ���ڸ��� ã���� ������ �־��ֱ�
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
	// 1. ��Ʈ ����� ������ ����
	// 2. ������ ���� �ڽ� ���� ���ϸ� �켱������ ������ �ٲٱ�
	// 3. ���ڸ��� ã���� ������ ����� ������ �־��ֱ�
	HData retdata = heapArr[1];				// ��Ʈ ����� ������
	HData lastElem = heapArr[numOfData];	// ������ ����� ������

	int parentIdx = 1;		// ������ ��尡 ��ġ�� �ε��� ������ ��� �ִ� ����
	int childIdx;

	while (childIdx = GetHiPriChildIDX(parentIdx))	// �ڽĳ�尡 ������ 0 ��ȯ�ؼ� ��������
	{
		if (comp(lastElem, heapArr[childIdx]) < 0)
		{
			heapArr[parentIdx] = heapArr[childIdx];		// ������ �ű�
			parentIdx = childIdx;	// �ε��� ������ ����
		}
		else
			break;
	}

	heapArr[parentIdx] = lastElem;
	numOfData -= 1;
	return retdata;
}