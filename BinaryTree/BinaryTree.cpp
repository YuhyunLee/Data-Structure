#include "BinaryTree.h"
#include <iostream>

// ������
BTreeNode::BTreeNode(void)
{
	left = NULL;
	right = NULL;
}

// �ش� ����� ������ ��ȯ
BTData BTreeNode::GetData(void)
{
	return data;
}

// �ش� ����� ������ ����
void BTreeNode::SetData(BTData data)
{
	this->data = data;
}

// �ش� ����� ���� ����Ʈ���� �ּ� �� ��ȯ
BTreeNode* BTreeNode::GetLeftSubTree(void)
{
	return left;
}

// �ش� ����� ������ ����Ʈ���� �ּ� �� ��ȯ
BTreeNode* BTreeNode::GetRightSubTree(void)
{
	return right;
}

// �ش� ����� ���ʿ� ����Ʈ�� ����
void BTreeNode::MakeLeftSubTree(BTreeNode* sub)
{
	if (left != NULL)
		free(left);


	left = sub;
}

// �ش� ����� �����ʿ� ����Ʈ�� ����
void BTreeNode::MakeRightSubTree(BTreeNode* sub)
{
	if (right != NULL)
		free(right);

	right = sub;
}

// ���ο� ���(= ����Ʈ��) ����
BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = new BTreeNode;
	return nd;
}

