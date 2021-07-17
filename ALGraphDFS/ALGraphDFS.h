#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

#include "DLinkedList.h"

enum { A, B, C, D, E, F, G, H, I, J };

class ALGraph
{
	int numV;		// ���� ����
	int numE;		// ���� ����
	List* adjList;	// ���� ���� ���� ����Ʈ�� �迭 ������
	int* visitInfo;	// �湮 ���� ���� int�� �迭 ������
public:
	ALGraph(int nv);
	void GraphDestroy(void);			// �����Ҵ��� ���ҽ� ����
	void ShowGraphEdgeInfo(void);		// ������ ���� ���
	void AddEdge(int fromV, int toV);	// ���� �߰�
	int VisitVertex(int visitV);		// ���� �湮 �Լ�
	void DFShowGraphVertex(int startV);	// DFS Ž�� �Լ�
	~ALGraph(void);
};

#endif // !__ALGRAPH_H__
