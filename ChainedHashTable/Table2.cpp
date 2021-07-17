#include "Table2.h"
#include <iostream>
using namespace std;

Table::Table(HashFunc f)
{
	// 해쉬 함수 등록
	hf = f;
}

void Table::TBLInsert(Key k, Value v)
{
	// 좁은 범위의 키 값
	int hv = hf(k);
	Slot ns(k, v);		// 슬롯 생성

	if (TBLSearch(k) != NULL)	// 키가 중복되었는지 검사(키는 유일해야 함)
	{
		cout << "키 중복 오류 발생" << endl;
		return;
	}
	else
		tbl[hv].LInsert(ns);	// 해당 테이블 인덱스의 연결리스트에 노드 추가
}

Value Table::TBLDelete(Key k)
{
	// 좁은 범위의 키 값
	int hv = hf(k);
	Slot cSlot;

	// 탐색 진행
	if (tbl[hv].LFirst(&cSlot))
	{
		if (cSlot.key == k)		// 첫 번째 노드의 키가 찾는 키가 맞다면
		{
			tbl[hv].LRemove();	// 노드 삭제
			return cSlot.val;	// 값 반환
		}
		else					// 아니라면 계속 탐색
		{
			while (tbl[hv].LNext(&cSlot))
			{
				if (cSlot.key == k)
				{
					tbl[hv].LRemove();
					return cSlot.val;
				}
			}
		}
	}

	return NULL;	// 탐색 실패하면 NULL 반환
}

Value Table::TBLSearch(Key k)
{
	// 좁은 범위의 키 값
	int hv = hf(k);
	Slot cSlot;

	// 탐색 진행
	if (tbl[hv].LFirst(&cSlot))
	{
		if (cSlot.key == k)		// 첫 번째 노드의 키가 찾는 키가 맞다면
			return cSlot.val;	// 값 반환
		else					// 아니라면 계속 탐색
		{
			while (tbl[hv].LNext(&cSlot))
			{
				if (cSlot.key == k)
					return cSlot.val;
			}
		}
	}

	return NULL;	// 탐색 실패하면 NULL 반환
}