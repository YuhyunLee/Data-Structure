#include "Table.h"
#include <iostream>

Table::Table(HashFunc f)
{
	// 슬롯 상태 초기화
	for (int i = 0; i < MAX_TBL; i++)
		tbl[i].status = EMPTY;

	// 해쉬 함수 등록
	hf = f;
}

void Table::TBLInsert(Key k, Value v)
{
	// 좁은 범위의 키 값
	int hv = hf(k);

	// 저장
	tbl[hv].key = k;
	tbl[hv].val = v;
	tbl[hv].status = INUSE;
}

Value Table::TBLDelete(Key k)
{
	// 좁은 범위의 키 값
	int hv = hf(k);

	// 데이터가 있는지 검사
	if (tbl[hv].status != INUSE)
		return NULL;
	else
	{
		tbl[hv].status = DELETED;	// 상태 변경
		return tbl[hv].val;			// 소멸 대상 값 반환
	}
}

Value Table::TBLSearch(Key k)
{
	// 좁은 범위의 키 값
	int hv = hf(k);

	// 데이터가 있는지 검사
	if (tbl[hv].status != INUSE)
		return NULL;
	else
		return tbl[hv].val;			// 탐색 대상 값 반환
}