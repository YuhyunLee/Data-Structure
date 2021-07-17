#include "ALGraphKruscal.h"
#include "ArrayBaseStack.h"
#include <iostream>
using namespace std;

// ���Ḯ��Ʈ ���Կ��� ���
/*
��ȯ�� = 0	n1�� �켱������ �� ����
��ȯ�� = 1	�켱������ ���ų� n2�� �� ����
*/
int WhoIsPrecede(int data1, int data2) 
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

// �켱����ť ���Կ��� ���
/*
��ȯ�� > 0	n1�� �켱������ �� ����
��ȯ�� < 0	n2�� �켱������ �� ����
��ȯ�� = 0	�켱������ ���ų� n2�� �� ����
*/
int PQWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}


// ������
ALGraph::ALGraph(int nv)
{
	numV = nv;
	numE = 0;

	// ����Ʈ �迭 �����Ҵ�
	adjList = new List[nv];
	for (int i = 0; i < nv; i++)
		adjList[i].SetSortRule(WhoIsPrecede);

	// int �迭 �����Ҵ�
	visitInfo = new int[nv];
	memset(visitInfo, 0, sizeof(int) * numV);	// visitInfo �迭 �� 0���� �ʱ�ȭ

	// ����ġ ���� ���� �켱���� ť �Ҵ�
	pqueue = new PQueue(PQWeightComp);
}

/*
void ALGraph::GraphDestroy(void)	----> C++�̱� ������ �Ҹ��ڿ��� ���ٰ���
{
	// �����Ҵ��� ����Ʈ ��ü �迭 �Ҹ�
	if(adjList != NULL)
		delete(adjList);
}
*/

// �׷��� ��� ������ ���� ���
void ALGraph::ShowGraphEdgeInfo(void)
{
	int vx;		// ��ȯ �����͸� ���� ����

	for (int i = 0; i < numV; i++)
	{
		cout << char(i + 65) << "�� ����� ���� : ";

		if (adjList[i].LFirst(&vx))
		{
			cout << char(vx + 65) << " ";

			while (adjList[i].LNext(&vx))
				cout << char(vx + 65) << " ";
		}
		cout << endl;
	}
}

// ���� �߰�
void ALGraph::AddEdge(int fromV, int toV, int weight)
{
	Edge edge(fromV, toV, weight);		// ������ ����ġ ���� ����
	pqueue->PEnqueue(edge);				// �켱����ť�� ����

	// �������̱� ������ �ѹ� ������ �߰��Ҷ� �� ���� ������ ��� ��带 �߰������ ��
	adjList[fromV].LInsert(toV);
	adjList[toV].LInsert(fromV);
	numE++;		// ���� ���� + 1
}


// ���� �湮 �Լ�(Ž�� �� ����)
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


// ũ�罺Į �˰����� ����� �ּҺ�����Ʈ�� ����
/*
������ ������������ �����ϰ� �켱������ ���� �������� �����ϴ� ���
(:������ ũ�罺Į �˰���2)
*/

// ConKruskalMST�Լ� ������ ���� ���� �Լ���
void RemoveEdge(int fromV, int toV);	// �׷������� ������ ����
int IsConnVertex(int v1, int v2);	// �� ������ ����Ǿ� �ִ��� Ȯ��
void RecoverEdge(int fromV, int toV);		// ������ ���� �ٽ� ����

// �ּҺ�����Ʈ�� ���� �Լ�
void ALGraph::ConKruskalMST(void)
{
	Edge recoveryEdge[20];	// ������ ������ ���� ����
	int eidx = 0;

	Edge edge;

	// MST�� ������ ������ �Ʒ��� while�� �ݺ�
	while (numE + 1 > numV)							// ������ �� + 1 = ������ ��  ==>  MST ����
	{
		edge = pqueue->PDequeue();
		RemoveEdge(edge.v1, edge.v2);	// �ϴ� ����

		if (!IsConnVertex(edge.v1, edge.v2))	// �� �� ������ �����ϴ� �ٸ� ������ ���ٸ�
		{
			// ���� �ٽ� ����
			RecoverEdge(edge.v1, edge.v2);
			recoveryEdge[eidx++] = edge;
		}
	}

	// �켱���� ť���� ������ ������ ���� ȸ��
	for (int i = 0; i < eidx; i++)
		pqueue->PEnqueue(recoveryEdge[i]);
}

void ALGraph::RemoveEdge(int fromV, int toV)		// �׷������� ������ ����
{
	RemoveWayEdge(fromV, toV);
	RemoveWayEdge(toV, fromV);
	numE--;
}

void ALGraph::RemoveWayEdge(int fromV, int toV)		// ���� ���� ���� �Ҹ�
{
	int edge;

	if (adjList[fromV].LFirst(&edge))
	{
		if (edge == toV)
		{
			adjList[fromV].LRemove();	// ��� ����
			return;
		}

		while (adjList[fromV].LNext(&edge))
		{
			if (edge == toV)
			{
				adjList[fromV].LRemove();	// ��� ����
				return;
			}
		}
	}
}

int ALGraph::IsConnVertex(int v1, int v2)	// �� ������ ����Ǿ� �ִ��� Ȯ��
												// DFShowGraphVertex �Լ��� ����!
{
	Stack stack;			// ���� ����
	int visitV = v1;
	int nextV;

	VisitVertex(visitV);	// ���� ���� �湮

	while (adjList[visitV].LFirst(&nextV) == true)
	{
		int visitFlag = FALSE;		// �湮 ���� ����

		if (nextV == v2)	// ��ǥ�� ã�´ٸ� �ٷ� true ��ȯ�� �Բ� �Լ� ����!
		{
			memset(visitInfo, 0, sizeof(int) * numV);	// �Լ��� ��ȯ�Ǳ� ���� �ʱ�ȭ ����
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
				if (nextV == v2)	// ��ǥ�� ã�´ٸ� �ٷ� true ��ȯ�� �Բ� �Լ� ����!
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
			if (stack.SIsEmpty() == true)		// ������ ����ٸ� ���������� �ǵ��ƿ� ��!
				break;
			else
				visitV = stack.SPop();
		}
	} // while���� ��

	// ������ Ž���� ���ؼ� Ž�� ���� �ʱ�ȭ
	memset(visitInfo, 0, sizeof(int) * numV);

	return false;	// ������� �Դٴ� ���� ��ǥ�� ã�� ���ߴٴ� ��! ==> v1�� v2�� ����Ǿ����� �ʴ�!
}

void ALGraph::RecoverEdge(int fromV, int toV)		// ������ ���� �ٽ� ����
{
	adjList[fromV].LInsert(toV);
	adjList[toV].LInsert(fromV);
	numE++;
}

// ��� ������ ����ġ ���� ���
void ALGraph::ShowGraphEdgeWeightInfo(void)
{
	PQueue copyPQ = *pqueue;	// �켱���� ť ����
	Edge edge;

	while (!copyPQ.PQIsEmpty())
	{
		edge = copyPQ.PDequeue();
		cout << char(edge.v1 + 65) << " - " << char(edge.v2 + 65) << " : " << edge.weight << endl;
	}
}


// �Ҹ���
ALGraph::~ALGraph(void)
{
	// �����Ҵ��� ����Ʈ ��ü �迭 �Ҹ�
	if (adjList != NULL)
		delete[] adjList;

	// �����Ҵ��� int�� �迭 �Ҹ�
	if (visitInfo != NULL)
		delete[] visitInfo;

	// �����Ҵ��� �켱���� ť �Ҹ�
	delete pqueue;
}