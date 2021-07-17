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
	int numV;		// 정점 개수
	int numE;		// 간선 개수
	List* adjList;	// 간선 정보 담을 배열 포인터
	int* visitInfo;	// 방문 여부 저장
	PQueue* pqueue;	// 간선의 가중치 정보 저장(및 정렬)할 우선 순위 큐
public:
	ALGraph(int nv);
	void GraphDestroy(void);			// 동적할당한 리소스 해제
	void ShowGraphEdgeInfo(void);		// 그래프의 모든 간선의 정보 출력
	int VisitVertex(int visitV);		// 정점 방문
	void DFShowGraphVertex(int startV);	// DFS 탐색
	void AddEdge(int fromV, int toV, int weight);	// 간선 추가
	~ALGraph(void);

	// 새로 추가된 함수
	void ConKruskalMST(void);			// 최소비용신장트리 구현
	void ShowGraphEdgeWeightInfo(void);	// 모든 간선의 가중치 정보 출력
	void RemoveEdge(int fromV, int toV);	// 그래프에서 간선을 삭제
	void RemoveWayEdge(int fromV, int toV);	// 한쪽 방향 간선 소멸
	int IsConnVertex(int v1, int v2);	// 두 정점이 연결되어 있는지 확인
	void RecoverEdge(int fromV, int toV);		// 삭제된 간선 다시 삽입
};

#endif // !__ALGRAPH_H__
