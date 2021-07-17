#ifndef __AVL_REBALANCE_H__
#define __AVL_REBALANCE_H__

#include "BinaryTree3.h"

// �ұ��� ���� �Ǵ� ����
int GetHeight(BTreeNode* bst);		// Ʈ���� ���̸� ����Ͽ� ��ȯ
int GetHeightDiff(BTreeNode* bst);	// �� ���� Ʈ���� ���� �� = ���� �μ��� ��ȯ

// ȸ�� ����
BTreeNode* RotateLL(BTreeNode* bst);
BTreeNode* RotateRR(BTreeNode* bst);
BTreeNode* RotateLR(BTreeNode* bst);
BTreeNode* RotateRL(BTreeNode* bst);

// ������ �� ���ñ⸦ ���� ����
BTreeNode* Rebalance(BTreeNode** pRoot);

#endif // !__AVL_REBALANCE_H__
