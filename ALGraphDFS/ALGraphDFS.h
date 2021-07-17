#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

#include "DLinkedList.h"

enum { A, B, C, D, E, F, G, H, I, J };

class ALGraph
{
	int numV;		// 정점 개수
	int numE;		// 간선 개수
	List* adjList;	// 간선 정보 담을 리스트형 배열 포인터
	int* visitInfo;	// 방문 정보 담을 int형 배열 포인터
public:
	ALGraph(int nv);
	void GraphDestroy(void);			// 동적할당한 리소스 해제
	void ShowGraphEdgeInfo(void);		// 간선의 정보 출력
	void AddEdge(int fromV, int toV);	// 간선 추가
	int VisitVertex(int visitV);		// 정점 방문 함수
	void DFShowGraphVertex(int startV);	// DFS 탐색 함수
	~ALGraph(void);
};

#endif // !__ALGRAPH_H__
