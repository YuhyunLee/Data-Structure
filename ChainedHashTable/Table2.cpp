#include "Table2.h"
#include <iostream>
using namespace std;

Table::Table(HashFunc f)
{
	// �ؽ� �Լ� ���
	hf = f;
}

void Table::TBLInsert(Key k, Value v)
{
	// ���� ������ Ű ��
	int hv = hf(k);
	Slot ns(k, v);		// ���� ����

	if (TBLSearch(k) != NULL)	// Ű�� �ߺ��Ǿ����� �˻�(Ű�� �����ؾ� ��)
	{
		cout << "Ű �ߺ� ���� �߻�" << endl;
		return;
	}
	else
		tbl[hv].LInsert(ns);	// �ش� ���̺� �ε����� ���Ḯ��Ʈ�� ��� �߰�
}

Value Table::TBLDelete(Key k)
{
	// ���� ������ Ű ��
	int hv = hf(k);
	Slot cSlot;

	// Ž�� ����
	if (tbl[hv].LFirst(&cSlot))
	{
		if (cSlot.key == k)		// ù ��° ����� Ű�� ã�� Ű�� �´ٸ�
		{
			tbl[hv].LRemove();	// ��� ����
			return cSlot.val;	// �� ��ȯ
		}
		else					// �ƴ϶�� ��� Ž��
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

	return NULL;	// Ž�� �����ϸ� NULL ��ȯ
}

Value Table::TBLSearch(Key k)
{
	// ���� ������ Ű ��
	int hv = hf(k);
	Slot cSlot;

	// Ž�� ����
	if (tbl[hv].LFirst(&cSlot))
	{
		if (cSlot.key == k)		// ù ��° ����� Ű�� ã�� Ű�� �´ٸ�
			return cSlot.val;	// �� ��ȯ
		else					// �ƴ϶�� ��� Ž��
		{
			while (tbl[hv].LNext(&cSlot))
			{
				if (cSlot.key == k)
					return cSlot.val;
			}
		}
	}

	return NULL;	// Ž�� �����ϸ� NULL ��ȯ
}