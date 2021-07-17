#include "BinaryTree.h"
#include <iostream>
using namespace std;


int main(void)
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	bt1->SetData(1);
	bt2->SetData(2);
	bt3->SetData(3);
	bt4->SetData(4);

	bt1->MakeLeftSubTree(bt2);
	bt1->MakeRightSubTree(bt3);
	bt2->MakeLeftSubTree(bt4);

	// bt1의 왼쪽 자식 노드의 데이터 출력
	cout << bt1->GetLeftSubTree()->GetData() << endl;

	// bt1의 왼쪽 자식 노드의 왼쪽 자식 노드의 데이터 출력
	cout << bt1->GetLeftSubTree()->GetLeftSubTree()->GetData() << endl;

	return 0;
}