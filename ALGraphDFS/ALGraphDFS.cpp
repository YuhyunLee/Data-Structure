#include "ALGraphDFS.h"
#include "ArrayBaseStack.h"
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
��ȯ�� = 0	n1�� �켱������ �� ����
��ȯ�� = 1	�켱������ ���ų� n2�� �� ����
*/

ALGraph::ALGraph(int nv)
{
	numV = nv;
	numE = 0;

	// ����Ʈ �迭 �����Ҵ�
	adjList = new List[nv];
	// int �迭 �����Ҵ�
	visitInfo = new int[nv];

	for (int i = 0; i < nv; i++)
		adjList[i].SetSortRule(WhoIsPrecede);
	
	memset(visitInfo, 0, sizeof(int) * numV);	// visitInfo �迭 �� 0���� �ʱ�ȭ
}

/*
void ALGraph::GraphDestroy(void)	----> C++�̱� ������ �Ҹ��ڿ��� ���ٰ���
{
	// �����Ҵ��� ����Ʈ ��ü �迭 �Ҹ�
	if(adjList != NULL)
		delete(adjList);
}
*/

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

void ALGraph::AddEdge(int fromV, int toV)
{
	// �������̱� ������ �ѹ� ������ �߰��Ҷ� �� ���� ������ ��� ��带 �߰������ ��
	adjList[fromV].LInsert(toV);
	adjList[toV].LInsert(fromV);

	numE++;		// ���� ���� + 1
}

int ALGraph::VisitVertex(int visitV)
{
	if (visitInfo[visitV] == 0)
	{
		visitInfo[visitV] = 1;
		cout << char(visitV + 65) << " ";
		return TRUE;
	}
	return FALSE;
}

void ALGraph::DFShowGraphVertex(int startV)
{
	Stack stack;			// ���� ����
	int visitV = startV;
	int nextV;

	VisitVertex(visitV);	// ���� ���� �湮

	while (adjList[visitV].LFirst(&nextV) == true)
	{
		int visitFlag = FALSE;		// �湮 ���� ����

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
}


ALGraph::~ALGraph(void)
{
	// �����Ҵ��� ����Ʈ ��ü �迭 �Ҹ�
	if (adjList != NULL)
		delete(adjList);

	// �����Ҵ��� int�� �迭 �Ҹ�
	if (visitInfo != NULL)
		delete[] visitInfo;
}