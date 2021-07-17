#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

#include "DLinkedList.h"

enum { A, B, C, D, E, F, G, H, I, J };

class ALGraph
{
	int numV;		// ���� ����
	int numE;		// ���� ����
	List* adjList;	// ���� ���� ���� �迭 ������
public:
	ALGraph(int nv);
	void GraphDestroy(void);			// �����Ҵ��� ���ҽ� ����
	void ShowGraphEdgeInfo(void);		// ������ ���� ���
	void AddEdge(int fromV, int toV);	// ���� �߰�
	~ALGraph(void);
};

#endif // !__ALGRAPH_H__
