#include "BinaryTree.h"
#include <iostream>

// 생성자
BTreeNode::BTreeNode(void)
{
	left = NULL;
	right = NULL;
}

// 해당 노드의 데이터 반환
BTData BTreeNode::GetData(void)
{
	return data;
}

// 해당 노드의 데이터 저장
void BTreeNode::SetData(BTData data)
{
	this->data = data;
}

// 해당 노드의 왼쪽 서브트리의 주소 값 반환
BTreeNode* BTreeNode::GetLeftSubTree(void)
{
	return left;
}

// 해당 노드의 오른쪽 서브트리의 주소 값 반환
BTreeNode* BTreeNode::GetRightSubTree(void)
{
	return right;
}

// 해당 노드의 왼쪽에 서브트리 연결
void BTreeNode::MakeLeftSubTree(BTreeNode* sub)
{
	if (left != NULL)
		free(left);


	left = sub;
}

// 해당 노드의 오른쪽에 서브트리 연결
void BTreeNode::MakeRightSubTree(BTreeNode* sub)
{
	if (right != NULL)
		free(right);

	right = sub;
}

// 새로운 노드(= 이진트리) 생성
BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = new BTreeNode;
	return nd;
}

