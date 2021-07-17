#include "ALGraphKruscal.h"
#include "ArrayBaseStack.h"
#include <iostream>
using namespace std;

// 연결리스트 삽입에서 사용
/*
반환값 = 0	n1이 우선순위가 더 높음
반환값 = 1	우선순위가 같거나 n2가 더 높음
*/
int WhoIsPrecede(int data1, int data2) 
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

// 우선순위큐 삽입에서 사용
/*
반환값 > 0	n1이 우선순위가 더 높음
반환값 < 0	n2가 우선순위가 더 높음
반환값 = 0	우선순위가 같거나 n2가 더 높음
*/
int PQWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}


// 생성자
ALGraph::ALGraph(int nv)
{
	numV = nv;
	numE = 0;

	// 리스트 배열 동적할당
	adjList = new List[nv];
	for (int i = 0; i < nv; i++)
		adjList[i].SetSortRule(WhoIsPrecede);

	// int 배열 동적할당
	visitInfo = new int[nv];
	memset(visitInfo, 0, sizeof(int) * numV);	// visitInfo 배열 다 0으로 초기화

	// 가중치 정보 담을 우선순위 큐 할당
	pqueue = new PQueue(PQWeightComp);
}

/*
void ALGraph::GraphDestroy(void)	----> C++이기 때문에 소멸자에서 해줄거임
{
	// 동적할당한 리스트 객체 배열 소멸
	if(adjList != NULL)
		delete(adjList);
}
*/

// 그래프 모든 간선의 정보 출력
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

// 간선 추가
void ALGraph::AddEdge(int fromV, int toV, int weight)
{
	Edge edge(fromV, toV, weight);		// 간선의 가중치 정보 담음
	pqueue->PEnqueue(edge);				// 우선순위큐에 저장

	// 무방향이기 때문에 한번 간선을 추가할때 두 개의 정점에 모두 노드를 추가해줘야 함
	adjList[fromV].LInsert(toV);
	adjList[toV].LInsert(fromV);
	numE++;		// 간선 개수 + 1
}


// 정점 방문 함수(탐색 중 쓰임)
int ALGraph::VisitVertex(int visitV)
{
	if (visitInfo[visitV] == 0)
	{
		visitInfo[visitV] = 1;
		// cout << char(visitV + 65) << " ";
		return TRUE;
	}
	return FALSE;
}


// 크루스칼 알고리즘을 사용한 최소비용신장트리 구현
/*
간선을 내림차순으로 정렬하고 우선순위가 높은 간선부터 삭제하는 방식
(:본문의 크루스칼 알고리즘2)
*/

// ConKruskalMST함수 구현을 돕는 서브 함수들
void RemoveEdge(int fromV, int toV);	// 그래프에서 간선을 삭제
int IsConnVertex(int v1, int v2);	// 두 정점이 연결되어 있는지 확인
void RecoverEdge(int fromV, int toV);		// 삭제된 간선 다시 삽입

// 최소비용신장트리 구현 함수
void ALGraph::ConKruskalMST(void)
{
	Edge recoveryEdge[20];	// 복원할 간선의 정보 저장
	int eidx = 0;

	Edge edge;

	// MST를 형성할 때까지 아래의 while문 반복
	while (numE + 1 > numV)							// 간선의 수 + 1 = 정점의 수  ==>  MST 형성
	{
		edge = pqueue->PDequeue();
		RemoveEdge(edge.v1, edge.v2);	// 일단 삭제

		if (!IsConnVertex(edge.v1, edge.v2))	// 이 두 정점을 연결하는 다른 간선이 없다면
		{
			// 간선 다시 복구
			RecoverEdge(edge.v1, edge.v2);
			recoveryEdge[eidx++] = edge;
		}
	}

	// 우선순위 큐에서 삭제된 간선의 정보 회복
	for (int i = 0; i < eidx; i++)
		pqueue->PEnqueue(recoveryEdge[i]);
}

void ALGraph::RemoveEdge(int fromV, int toV)		// 그래프에서 간선을 삭제
{
	RemoveWayEdge(fromV, toV);
	RemoveWayEdge(toV, fromV);
	numE--;
}

void ALGraph::RemoveWayEdge(int fromV, int toV)		// 한쪽 방향 간선 소멸
{
	int edge;

	if (adjList[fromV].LFirst(&edge))
	{
		if (edge == toV)
		{
			adjList[fromV].LRemove();	// 노드 삭제
			return;
		}

		while (adjList[fromV].LNext(&edge))
		{
			if (edge == toV)
			{
				adjList[fromV].LRemove();	// 노드 삭제
				return;
			}
		}
	}
}

int ALGraph::IsConnVertex(int v1, int v2)	// 두 정점이 연결되어 있는지 확인
												// DFShowGraphVertex 함수의 변형!
{
	Stack stack;			// 스택 생성
	int visitV = v1;
	int nextV;

	VisitVertex(visitV);	// 시작 정점 방문

	while (adjList[visitV].LFirst(&nextV) == true)
	{
		int visitFlag = FALSE;		// 방문 성공 여부

		if (nextV == v2)	// 목표를 찾는다면 바로 true 반환과 함께 함수 종료!
		{
			memset(visitInfo, 0, sizeof(int) * numV);	// 함수가 반환되기 전에 초기화 진행
			return true;
		}	

		if (VisitVertex(nextV) == true)
		{
			stack.SPush(visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (adjList[visitV].LNext(&nextV) == true)
			{
				if (nextV == v2)	// 목표를 찾는다면 바로 true 반환과 함께 함수 종료!
				{
					memset(visitInfo, 0, sizeof(int) * numV);
					return true;
				}

				if (VisitVertex(nextV) == true)
				{
					stack.SPush(visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (stack.SIsEmpty() == true)		// 스택이 비었다면 시작점으로 되돌아온 것!
				break;
			else
				visitV = stack.SPop();
		}
	} // while문의 끝

	// 이후의 탐색을 위해서 탐색 정보 초기화
	memset(visitInfo, 0, sizeof(int) * numV);

	return false;	// 여기까지 왔다는 것은 목표를 찾지 못했다는 것! ==> v1과 v2가 연결되어있지 않다!
}

void ALGraph::RecoverEdge(int fromV, int toV)		// 삭제된 간선 다시 삽입
{
	adjList[fromV].LInsert(toV);
	adjList[toV].LInsert(fromV);
	numE++;
}

// 모든 간선의 가중치 정보 출력
void ALGraph::ShowGraphEdgeWeightInfo(void)
{
	PQueue copyPQ = *pqueue;	// 우선순위 큐 복사
	Edge edge;

	while (!copyPQ.PQIsEmpty())
	{
		edge = copyPQ.PDequeue();
		cout << char(edge.v1 + 65) << " - " << char(edge.v2 + 65) << " : " << edge.weight << endl;
	}
}


// 소멸자
ALGraph::~ALGraph(void)
{
	// 동적할당한 리스트 객체 배열 소멸
	if (adjList != NULL)
		delete[] adjList;

	// 동적할당한 int형 배열 소멸
	if (visitInfo != NULL)
		delete[] visitInfo;

	// 동적할당한 우선순위 큐 소멸
	delete pqueue;
}