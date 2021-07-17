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
��ȯ�� = 0	n1�� �켱������ �� ����
��ȯ�� = 1	�켱������ ���ų� n2�� �� ����
*/

ALGraph::ALGraph(int nv)
{
	numV = nv;
	numE = 0;

	// ����Ʈ �迭 �����Ҵ�
	adjList = new List[nv];

	for (int i = 0; i < nv; i++)
		adjList[i].SetSortRule(WhoIsPrecede);
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

ALGraph::~ALGraph(void)
{
	// �����Ҵ��� ����Ʈ ��ü �迭 �Ҹ�
	if (adjList != NULL)
		delete(adjList);
}