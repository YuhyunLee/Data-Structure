#include "BinarySearchTree3.h"
#include "AVLRebalance.h"
#include <iostream>
using namespace std;

// 이진 탐색 트리 생성
void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;		// 루트노드를 NULL로 초기화
}

// 트리 노드의 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst)
{
	return bst->GetData();
}

// 이진 탐색 트리 삽입 (모든 노드의 균형적인 리밸런싱을 위해 재귀함수로 구현)
BTreeNode* BSTInsert(BTreeNode** pRoot, BSTData data)
{
	if (*pRoot == NULL)
	{
		*pRoot = MakeBTreeNode();
		(*pRoot)->SetData(data);
	}
	else if (data < (*pRoot)->GetData())
	{
		BSTInsert(&((*pRoot)->GetLeftSubTree()), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > (*pRoot)->GetData())
	{
		BSTInsert(&((*pRoot)->GetRightSubTree()), data);
		*pRoot = Rebalance(pRoot);
	}
	else
	{
		return NULL; // 키의 중복을 허용하지 않는다.
	}
	return *pRoot;
}

// 이진 탐색 트리 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst;
	BSTData cd;

	while (cNode != NULL)	// 더 이상 이동할 자식 노드가 없을 때까지
	{
		cd = cNode->GetData();

		if (target == cd)
			return cNode;		// 찾았으면 그 노드의 주소 값 반환
		else if (target < cd)
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	return NULL;		// 탐색 실패
}

// 이진 탐색 트리 삭제
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode();	// 가상 루트 노드
	BTreeNode* pNode = pVRoot;				// 현재 노드의 부모 노드
	BTreeNode* cNode = *pRoot;				// 현재 노드
	BTreeNode* dNode;						// 삭제 대상 노드

	// 가상 루트 노드의 오른쪽 자식 = 진짜 루트 노드
	pVRoot->ChangeRightSubTree(*pRoot);

	// 삭제 대상인 노드를 탐색
	while (cNode != NULL && cNode->GetData() != target)
	{
		pNode = cNode;

		if (cNode->GetData() > target)
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	// 탐색 실패했다면
	if (cNode == NULL)
		return NULL;			// 함수 종료

	// 아니라면 계속 진행
	dNode = cNode;				// 삭제 대상인 노드가 cNode에 담겨있을 거기 때문에

	// 단말 노드인 경우
	if (dNode->GetLeftSubTree() == NULL && dNode->GetRightSubTree() == NULL)
	{
		// 1. 삭제 대상 노드가 부모 노드의 왼쪽 자식인지 오른쪽 자식인지 구분
		if (pNode->GetLeftSubTree() == dNode)
			pNode->RemoveLeftSubTree();
		else
			pNode->RemoveRightSubTree();
	}
	// 자식 노드가 하나인 경우
	else if (dNode->GetLeftSubTree() == NULL || dNode->GetRightSubTree() == NULL)
	{
		BTreeNode* dcNode;		// 자식 노드를 가리키는 포인터

		// 1. 자식 노드 주소 값 넣어주고
		if (dNode->GetLeftSubTree() == NULL)
			dcNode = dNode->GetRightSubTree();
		else
			dcNode = dNode->GetLeftSubTree();

		// 2. 삭제 대상 노드가 부모 노드의 왼쪽 자식인지 오른쪽 자식인지 구분하고 부모 노드와 자식 노드 연결
		if (pNode->GetLeftSubTree() == dNode)
			pNode->ChangeLeftSubTree(dcNode);
		else
			pNode->ChangeRightSubTree(dcNode);
	}
	// 자식 노드가 둘인 경우
	else
	{
		BTreeNode* mNode = dNode->GetRightSubTree();		// 대체 노드
		BTreeNode* mpNode = dNode;							// 대체 노드의 부모 노드
		int delData;
		
		// 1. 대체 노드 찾기
		// 삭제 대상 노드의 오른쪽 서브트리에서 가장 작은 값 찾기
		while (mNode->GetLeftSubTree() != NULL)
		{
			mpNode = mNode;
			mNode = mNode->GetLeftSubTree();
		}

		// 2. 삭제 대상 노드에 대체 노드의 값 대입
		delData = dNode->GetData();							// 삭제 데이터 백업
		dNode->SetData(mNode->GetData());					// 대입

		// 3. (대체 노드의)부모 노드와 자식 노드 연결 ==> 대체 노드 삭제
		if (mpNode->GetLeftSubTree() == mNode)
			mpNode->ChangeLeftSubTree(mNode->GetRightSubTree());
		else
			mpNode->ChangeRightSubTree(mNode->GetRightSubTree());

		// dNode 다시 설정 (실제 삭제되는 건 대체 노드)
		dNode = mNode;
		dNode->SetData(delData);
	}

	// 삭제된 노드가 루트노드인 경우에 대한 추가적인 처리
	if (pVRoot->GetRightSubTree() != *pRoot)
		*pRoot = pVRoot->GetRightSubTree();

	// 가상 루트 노드 소멸
	delete(pVRoot);

	// 리밸런싱
	*pRoot = Rebalance(pRoot);

	// 삭제 대상 노드 주소 반환
	return dNode;
}

// 노드 방문 목적 함수
void ShowIntData(int data)
{
	cout << data << " ";
}

// 이진 탐색 트리 모든 노드의 데이터를 중위순회하여 출력
void BSTShowAll(BTreeNode* bst)
{
	InOrderTraverse(bst, ShowIntData);
}