#ifndef __AL_GRAPH_KRUSCAL_H__
#define __AL_GRAPH_KRUSCAL_H__

#include "DLinkedList.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

#define TRUE	1
#define FALSE	0

enum { A, B, C, D, E, F, G, H, I, J };

class ALGraph
{
	int numV;		// ���� ����
	int numE;		// ���� ����
	List* adjList;	// ���� ���� ���� �迭 ������
	int* visitInfo;	// �湮 ���� ����
	PQueue* pqueue;	// ������ ����ġ ���� ����(�� ����)�� �켱 ���� ť
public:
	ALGraph(int nv);
	void GraphDestroy(void);			// �����Ҵ��� ���ҽ� ����
	void ShowGraphEdgeInfo(void);		// �׷����� ��� ������ ���� ���
	int VisitVertex(int visitV);		// ���� �湮
	void DFShowGraphVertex(int startV);	// DFS Ž��
	void AddEdge(int fromV, int toV, int weight);	// ���� �߰�
	~ALGraph(void);

	// ���� �߰��� �Լ�
	void ConKruskalMST(void);			// �ּҺ�����Ʈ�� ����
	void ShowGraphEdgeWeightInfo(void);	// ��� ������ ����ġ ���� ���
	void RemoveEdge(int fromV, int toV);	// �׷������� ������ ����
	void RemoveWayEdge(int fromV, int toV);	// ���� ���� ���� �Ҹ�
	int IsConnVertex(int v1, int v2);	// �� ������ ����Ǿ� �ִ��� Ȯ��
	void RecoverEdge(int fromV, int toV);		// ������ ���� �ٽ� ����
};

#endif // !__ALGRAPH_H__
