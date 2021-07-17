#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

class BTreeNode
{
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
};

#endif // !__BINARY_TREE_H__

