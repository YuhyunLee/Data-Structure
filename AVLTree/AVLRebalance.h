#ifndef __AVL_REBALANCE_H__
#define __AVL_REBALANCE_H__

#include "BinaryTree3.h"

// 불균형 여부 판단 도구
int GetHeight(BTreeNode* bst);		// 트리의 높이를 계산하여 반환
int GetHeightDiff(BTreeNode* bst);	// 두 서브 트리의 높이 차 = 균형 인수를 반환

// 회전 도구
BTreeNode* RotateLL(BTreeNode* bst);
BTreeNode* RotateRR(BTreeNode* bst);
BTreeNode* RotateLR(BTreeNode* bst);
BTreeNode* RotateRL(BTreeNode* bst);

// 사용순서 및 사용시기를 담은 도구
BTreeNode* Rebalance(BTreeNode** pRoot);

#endif // !__AVL_REBALANCE_H__
