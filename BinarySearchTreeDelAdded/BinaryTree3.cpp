#include "BinaryTree3.h"
#include <iostream>

BTreeNode::BTreeNode(void)
{
	left = NULL;
	right = NULL;
}

BTData BTreeNode::GetData(void) { return data; }
void BTreeNode::SetData(BTData data) { this->data = data; }

BTreeNode* BTreeNode::GetLeftSubTree(void) { return left; }
BTreeNode* BTreeNode::GetRightSubTree(void) { return right; }

void BTreeNode::MakeLeftSubTree(BTreeNode* sub)
{
	if (left != NULL)
		delete(left);

	left = sub;
}

void BTreeNode::MakeRightSubTree(BTreeNode* sub)
{
	if (right != NULL)
		delete(right);

	right = sub;
}

void PreOrderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	action(bt->GetData());
	PreOrderTraverse(bt->GetLeftSubTree(), action);
	PreOrderTraverse(bt->GetRightSubTree(), action);
}

void InOrderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	InOrderTraverse(bt->GetLeftSubTree(), action);
	action(bt->GetData());
	InOrderTraverse(bt->GetRightSubTree(), action);
}

void PostOrderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
	
	PostOrderTraverse(bt->GetLeftSubTree(), action);
	PostOrderTraverse(bt->GetRightSubTree(), action);
	action(bt->GetData());
}

BTreeNode* BTreeNode::RemoveLeftSubTree(void)
{
	BTreeNode* delNode;

	delNode = left;
	left = NULL;

	return delNode;
}

BTreeNode* BTreeNode::RemoveRightSubTree(void)
{
	BTreeNode* delNode;

	delNode = right;
	right = NULL;

	return delNode;
}

void BTreeNode::ChangeLeftSubTree(BTreeNode* sub) { left = sub; }

void BTreeNode::ChangeRightSubTree(BTreeNode* sub) { right = sub; }

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = new BTreeNode;
	return nd;
}