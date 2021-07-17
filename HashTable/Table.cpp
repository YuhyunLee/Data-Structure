#include "Table.h"
#include <iostream>

Table::Table(HashFunc f)
{
	// ���� ���� �ʱ�ȭ
	for (int i = 0; i < MAX_TBL; i++)
		tbl[i].status = EMPTY;

	// �ؽ� �Լ� ���
	hf = f;
}

void Table::TBLInsert(Key k, Value v)
{
	// ���� ������ Ű ��
	int hv = hf(k);

	// ����
	tbl[hv].key = k;
	tbl[hv].val = v;
	tbl[hv].status = INUSE;
}

Value Table::TBLDelete(Key k)
{
	// ���� ������ Ű ��
	int hv = hf(k);

	// �����Ͱ� �ִ��� �˻�
	if (tbl[hv].status != INUSE)
		return NULL;
	else
	{
		tbl[hv].status = DELETED;	// ���� ����
		return tbl[hv].val;			// �Ҹ� ��� �� ��ȯ
	}
}

Value Table::TBLSearch(Key k)
{
	// ���� ������ Ű ��
	int hv = hf(k);

	// �����Ͱ� �ִ��� �˻�
	if (tbl[hv].status != INUSE)
		return NULL;
	else
		return tbl[hv].val;			// Ž�� ��� �� ��ȯ
}