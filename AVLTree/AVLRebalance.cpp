#include "AVLRebalance.h"
#include <iostream>

// 트리의 높이를 계산하여 반환
int GetHeight(BTreeNode* bst)
{
	int leftH;		// 왼쪽 높이
	int rightH;		// 오른쪽 높이

	if (bst == NULL)
		return 0;

	leftH = GetHeight(bst->GetLeftSubTree());
	rightH = GetHeight(bst->GetRightSubTree());

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

// 두 서브 트리의 높이 차 = 균형 인수를 반환
int GetHeightDiff(BTreeNode* bst)
{
	int lsh;		// 왼쪽 서브트리 높이
	int rsh;		// 오른쪽 서브트리 높이

	if (bst == NULL)
		return 0;

	lsh = GetHeight(bst->GetLeftSubTree());
	rsh = GetHeight(bst->GetRightSubTree());

	return lsh - rsh;
}

BTreeNode* RotateLL(BTreeNode* bst)
{
	BTreeNode* pNode;	// 부모 노드
	BTreeNode* cNode;	// 자식 노드

	pNode = bst;
	cNode = pNode->GetLeftSubTree();

	// LL회전
	pNode->ChangeLeftSubTree(cNode->GetRightSubTree());
	cNode->ChangeRightSubTree(pNode);

	return cNode;	// LL회전으로 인해 변경된 루트노드의 주소 값 반환
}

BTreeNode* RotateRR(BTreeNode* bst)
{
	BTreeNode* pNode;	// 부모 노드
	BTreeNode* cNode;	// 자식 노드

	pNode = bst;
	cNode = pNode->GetRightSubTree();

	// RR회전
	pNode->ChangeRightSubTree(cNode->GetLeftSubTree());
	cNode->ChangeLeftSubTree(pNode);

	return cNode;	// LL회전으로 인해 변경된 루트노드의 주소 값 반환
}

BTreeNode* RotateLR(BTreeNode* bst)
{
	BTreeNode* pNode;	// 부모 노드
	BTreeNode* cNode;	// 자식 노드

	pNode = bst;
	cNode = pNode->GetLeftSubTree();

	// 부분적 RR회전
	pNode->ChangeLeftSubTree(RotateRR(cNode));
	// LL회전
	return RotateLL(pNode);		// 변경된 루트노드의 주소 값 반환
}

BTreeNode* RotateRL(BTreeNode* bst)
{
	BTreeNode* pNode;	// 부모 노드
	BTreeNode* cNode;	// 자식 노드

	pNode = bst;
	cNode = pNode->GetRightSubTree();

	// 부분적 LL회전
	pNode->ChangeRightSubTree(RotateLL(cNode));
	// RR회전
	return RotateRR(pNode);		// 변경된 루트노드의 주소 값 반환
}

BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);		// 균형 인수 계산

	// 균형 인수가 +2 이상이면 LL 또는 LR상태
	if (hDiff > 1)
	{
		if (GetHeightDiff((*pRoot)->GetLeftSubTree()) > 0)	// LL상태라면
			*pRoot = RotateLL(*pRoot);						// LL회전
		else												// LR상태라면
			*pRoot = RotateLR(*pRoot);						// LR회전
	}

	// 균형 인수가 -2 이하이면 RR 또는 RL상태
	if (hDiff < -1)
	{
		if (GetHeightDiff((*pRoot)->GetLeftSubTree()) < 0)	// RR상태라면
			*pRoot = RotateRR(*pRoot);						// RR회전
		else												// RL상태라면
			*pRoot = RotateRL(*pRoot);						// RL회전
	}

	return *pRoot;
}