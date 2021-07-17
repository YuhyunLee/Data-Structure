#include "ALGraph.h"
#include <iostream>
using namespace std;

int WhoIsPrecede(int data1, int data2) 
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}
/*
반환값 = 0	n1이 우선순위가 더 높음
반환값 = 1	우선순위가 같거나 n2가 더 높음
*/

ALGraph::ALGraph(int nv)
{
	numV = nv;
	numE = 0;

	// 리스트 배열 동적할당
	adjList = new List[nv];

	for (int i = 0; i < nv; i++)
		adjList[i].SetSortRule(WhoIsPrecede);
}

/*
void ALGraph::GraphDestroy(void)	----> C++이기 때문에 소멸자에서 해줄거임
{
	// 동적할당한 리스트 객체 배열 소멸
	if(adjList != NULL)
		delete(adjList);
}
*/

void ALGraph::ShowGraphEdgeInfo(void)
{
	int vx;		// 반환 데이터를 담을 공간

	for (int i = 0; i < numV; i++)
	{
		cout << char(i + 65) << "와 연결된 정점 : ";

		if (adjList[i].LFirst(&vx))
		{
			cout << char(vx + 65) << " ";

			while (adjList[i].LNext(&vx))
				cout << char(vx + 65) << " ";
		}
		cout << endl;
	}
}

void ALGraph::AddEdge(int fromV, int toV)
{
	// 무방향이기 때문에 한번 간선을 추가할때 두 개의 정점에 모두 노드를 추가해줘야 함
	adjList[fromV].LInsert(toV);
	adjList[toV].LInsert(fromV);

	numE++;		// 간선 개수 + 1
}

ALGraph::~ALGraph(void)
{
	// 동적할당한 리스트 객체 배열 소멸
	if (adjList != NULL)
		delete(adjList);
}