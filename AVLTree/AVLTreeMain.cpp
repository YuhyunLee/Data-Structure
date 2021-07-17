#include <iostream>
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"
using namespace std;

int main(void)
{
	BTreeNode* avlRoot;
	BTreeNode* clNode;		// current left node
	BTreeNode* crNode;		// current right node
	BSTMakeAndInit(&avlRoot);

	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);

	cout << "루트노드 : " << avlRoot->GetData() << endl;

	clNode = avlRoot->GetLeftSubTree();
	crNode = avlRoot->GetRightSubTree();
	cout << "왼쪽 1: " << clNode->GetData() << ", 오른쪽 1: " << crNode->GetData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "왼쪽 2: " << clNode->GetData() << ", 오른쪽 2: " << crNode->GetData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "왼쪽 3: " << clNode->GetData() << ", 오른쪽 3: " << crNode->GetData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "왼쪽 4: " << clNode->GetData() << ", 오른쪽 4: " << crNode->GetData() << endl;

	return 0;
}