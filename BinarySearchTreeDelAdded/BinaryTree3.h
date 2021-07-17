#ifndef __BINARY_TREE_3_H__
#define __BINARY_TREE_3_H__

typedef int BTData;
typedef void (*VisitFuncPtr)(BTData data);

class BTreeNode {
	BTData data;
	BTreeNode* left;
	BTreeNode* right;
public:
	BTreeNode(void);

	BTData GetData(void);
	void SetData(BTData data);

	BTreeNode* GetLeftSubTree(void);
	BTreeNode* GetRightSubTree(void);

	void MakeLeftSubTree(BTreeNode* sub);
	void MakeRightSubTree(BTreeNode* sub);

	BTreeNode* RemoveLeftSubTree(void);
	BTreeNode* RemoveRightSubTree(void);
	void ChangeLeftSubTree(BTreeNode* sub);
	void ChangeRightSubTree(BTreeNode* sub);
};

void PreOrderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InOrderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostOrderTraverse(BTreeNode* bt, VisitFuncPtr action);

BTreeNode* MakeBTreeNode(void);

#endif // !__BINARY_TREE_3_H__

