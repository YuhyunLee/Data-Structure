#include "BinaryTree3.h"
#include "BinarySearchTree2.h"
#include <iostream>
using namespace std;

int main(void)
{
	BTreeNode* bstRoot;		// 루트노드 가리킴
	BTreeNode* sNode;		// 탐색노드 가리킴

	// 이진탐색트리 생성
	BSTMakeAndInit(&bstRoot);

	// 삽입
	BSTInsert(&bstRoot, 5); BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 1); BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4); BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 3); BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7);

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 3);
	delete(sNode);

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 8);
	delete(sNode);

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 1);
	delete(sNode);

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 6);
	delete(sNode);

	BSTShowAll(bstRoot); printf("\n");

	return 0;
}