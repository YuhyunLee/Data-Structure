#include "BinarySearchTree2.h"
#include <iostream>
using namespace std;

// ���� Ž�� Ʈ�� ����
void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;		// ��Ʈ��带 NULL�� �ʱ�ȭ
}

// Ʈ�� ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst)
{
	return bst->GetData();
}

// ���� Ž�� Ʈ�� ����
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL;	// �������� �θ���
	BTreeNode* cNode = *pRoot;	// ���� ��� - ó���� ��Ʈ ���� �ʱ�ȭ
	BTreeNode* nNode = NULL;	// ���� ������ ���

	// �� ��带 �߰��� ��ġ ã��
	while (cNode != NULL)
	{
		// Ű �� �������� �ߺ� �˻�
		if (cNode->GetData() == data)
			return;		// �Լ� ���� (�ߺ� ��� �Ұ��ϱ� ������)

		pNode = cNode;

		if (cNode->GetData() > data)
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	// �� ��� �����ϰ� ������ ����
	nNode = MakeBTreeNode();
	nNode->SetData(data);

	// �� ��� Ʈ���� �߰�
	if (pNode != NULL)		// �� ��尡 ��Ʈ ��尡 �ƴ� ��
	{
		if (pNode->GetData() > data)
			pNode->MakeLeftSubTree(nNode);
		else
			pNode->MakeRightSubTree(nNode);
	}
	else					// �� ��尡 ��Ʈ ����� ��
	{
		*pRoot = nNode;
	}
}

// ���� Ž�� Ʈ�� Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst;
	BSTData cd;

	while (cNode != NULL)	// �� �̻� �̵��� �ڽ� ��尡 ���� ������
	{
		cd = cNode->GetData();

		if (target == cd)
			return cNode;		// ã������ �� ����� �ּ� �� ��ȯ
		else if (target < cd)
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	return NULL;		// Ž�� ����
}

// ���� Ž�� Ʈ�� ����
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode();	// ���� ��Ʈ ���
	BTreeNode* pNode = pVRoot;				// ���� ����� �θ� ���
	BTreeNode* cNode = *pRoot;				// ���� ���
	BTreeNode* dNode;						// ���� ��� ���

	// ���� ��Ʈ ����� ������ �ڽ� = ��¥ ��Ʈ ���
	pVRoot->ChangeRightSubTree(*pRoot);

	// ���� ����� ��带 Ž��
	while (cNode != NULL && cNode->GetData() != target)
	{
		pNode = cNode;

		if (cNode->GetData() > target)
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	// Ž�� �����ߴٸ�
	if (cNode == NULL)
		return NULL;			// �Լ� ����

	// �ƴ϶�� ��� ����
	dNode = cNode;				// ���� ����� ��尡 cNode�� ������� �ű� ������

	// �ܸ� ����� ���
	if (dNode->GetLeftSubTree() == NULL && dNode->GetRightSubTree() == NULL)
	{
		// 1. ���� ��� ��尡 �θ� ����� ���� �ڽ����� ������ �ڽ����� ����
		if (pNode->GetLeftSubTree() == dNode)
			pNode->RemoveLeftSubTree();
		else
			pNode->RemoveRightSubTree();
	}
	// �ڽ� ��尡 �ϳ��� ���
	else if (dNode->GetLeftSubTree() == NULL || dNode->GetRightSubTree() == NULL)
	{
		BTreeNode* dcNode;		// �ڽ� ��带 ����Ű�� ������

		// 1. �ڽ� ��� �ּ� �� �־��ְ�
		if (dNode->GetLeftSubTree() == NULL)
			dcNode = dNode->GetRightSubTree();
		else
			dcNode = dNode->GetLeftSubTree();

		// 2. ���� ��� ��尡 �θ� ����� ���� �ڽ����� ������ �ڽ����� �����ϰ� �θ� ���� �ڽ� ��� ����
		if (pNode->GetLeftSubTree() == dNode)
			pNode->ChangeLeftSubTree(dcNode);
		else
			pNode->ChangeRightSubTree(dcNode);
	}
	// �ڽ� ��尡 ���� ���
	else
	{
		BTreeNode* mNode = dNode->GetRightSubTree();		// ��ü ���
		BTreeNode* mpNode = dNode;							// ��ü ����� �θ� ���
		int delData;
		
		// 1. ��ü ��� ã��
		// ���� ��� ����� ������ ����Ʈ������ ���� ���� �� ã��
		while (mNode->GetLeftSubTree() != NULL)
		{
			mpNode = mNode;
			mNode = mNode->GetLeftSubTree();
		}

		// 2. ���� ��� ��忡 ��ü ����� �� ����
		delData = dNode->GetData();							// ���� ������ ���
		dNode->SetData(mNode->GetData());					// ����

		// 3. (��ü �����)�θ� ���� �ڽ� ��� ���� ==> ��ü ��� ����
		if (mpNode->GetLeftSubTree() == mNode)
			mpNode->ChangeLeftSubTree(mNode->GetRightSubTree());
		else
			mpNode->ChangeRightSubTree(mNode->GetRightSubTree());

		// dNode �ٽ� ���� (���� �����Ǵ� �� ��ü ���)
		dNode = mNode;
		dNode->SetData(delData);
	}

	// ������ ��尡 ��Ʈ����� ��쿡 ���� �߰����� ó��
	if (pVRoot->GetRightSubTree() != *pRoot)
		*pRoot = pVRoot->GetRightSubTree();

	// ���� ��Ʈ ��� �Ҹ�
	delete(pVRoot);

	// ���� ��� ��� �ּ� ��ȯ
	return dNode;
}

// ��� �湮 ���� �Լ�
void ShowIntData(int data)
{
	cout << data << " ";
}

// ���� Ž�� Ʈ�� ��� ����� �����͸� ������ȸ�Ͽ� ���
void BSTShowAll(BTreeNode* bst)
{
	InOrderTraverse(bst, ShowIntData);
}