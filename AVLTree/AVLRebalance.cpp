#include "AVLRebalance.h"
#include <iostream>

// Ʈ���� ���̸� ����Ͽ� ��ȯ
int GetHeight(BTreeNode* bst)
{
	int leftH;		// ���� ����
	int rightH;		// ������ ����

	if (bst == NULL)
		return 0;

	leftH = GetHeight(bst->GetLeftSubTree());
	rightH = GetHeight(bst->GetRightSubTree());

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

// �� ���� Ʈ���� ���� �� = ���� �μ��� ��ȯ
int GetHeightDiff(BTreeNode* bst)
{
	int lsh;		// ���� ����Ʈ�� ����
	int rsh;		// ������ ����Ʈ�� ����

	if (bst == NULL)
		return 0;

	lsh = GetHeight(bst->GetLeftSubTree());
	rsh = GetHeight(bst->GetRightSubTree());

	return lsh - rsh;
}

BTreeNode* RotateLL(BTreeNode* bst)
{
	BTreeNode* pNode;	// �θ� ���
	BTreeNode* cNode;	// �ڽ� ���

	pNode = bst;
	cNode = pNode->GetLeftSubTree();

	// LLȸ��
	pNode->ChangeLeftSubTree(cNode->GetRightSubTree());
	cNode->ChangeRightSubTree(pNode);

	return cNode;	// LLȸ������ ���� ����� ��Ʈ����� �ּ� �� ��ȯ
}

BTreeNode* RotateRR(BTreeNode* bst)
{
	BTreeNode* pNode;	// �θ� ���
	BTreeNode* cNode;	// �ڽ� ���

	pNode = bst;
	cNode = pNode->GetRightSubTree();

	// RRȸ��
	pNode->ChangeRightSubTree(cNode->GetLeftSubTree());
	cNode->ChangeLeftSubTree(pNode);

	return cNode;	// LLȸ������ ���� ����� ��Ʈ����� �ּ� �� ��ȯ
}

BTreeNode* RotateLR(BTreeNode* bst)
{
	BTreeNode* pNode;	// �θ� ���
	BTreeNode* cNode;	// �ڽ� ���

	pNode = bst;
	cNode = pNode->GetLeftSubTree();

	// �κ��� RRȸ��
	pNode->ChangeLeftSubTree(RotateRR(cNode));
	// LLȸ��
	return RotateLL(pNode);		// ����� ��Ʈ����� �ּ� �� ��ȯ
}

BTreeNode* RotateRL(BTreeNode* bst)
{
	BTreeNode* pNode;	// �θ� ���
	BTreeNode* cNode;	// �ڽ� ���

	pNode = bst;
	cNode = pNode->GetRightSubTree();

	// �κ��� LLȸ��
	pNode->ChangeRightSubTree(RotateLL(cNode));
	// RRȸ��
	return RotateRR(pNode);		// ����� ��Ʈ����� �ּ� �� ��ȯ
}

BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);		// ���� �μ� ���

	// ���� �μ��� +2 �̻��̸� LL �Ǵ� LR����
	if (hDiff > 1)
	{
		if (GetHeightDiff((*pRoot)->GetLeftSubTree()) > 0)	// LL���¶��
			*pRoot = RotateLL(*pRoot);						// LLȸ��
		else												// LR���¶��
			*pRoot = RotateLR(*pRoot);						// LRȸ��
	}

	// ���� �μ��� -2 �����̸� RR �Ǵ� RL����
	if (hDiff < -1)
	{
		if (GetHeightDiff((*pRoot)->GetLeftSubTree()) < 0)	// RR���¶��
			*pRoot = RotateRR(*pRoot);						// RRȸ��
		else												// RL���¶��
			*pRoot = RotateRL(*pRoot);						// RLȸ��
	}

	return *pRoot;
}