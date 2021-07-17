#include <iostream>
#include "ALGraphBFS.h"
using namespace std;

int main(void)
{
	ALGraph graph(7);

	graph.AddEdge(A, B);
	graph.AddEdge(A, D);
	graph.AddEdge(B, C);
	graph.AddEdge(D, C);
	graph.AddEdge(D, E);
	graph.AddEdge(E, F);
	graph.AddEdge(E, G);

	graph.ShowGraphEdgeInfo();
	cout << endl;

	graph.BFShowGraphVertex(A); cout << endl;
	graph.BFShowGraphVertex(C); cout << endl;
	graph.BFShowGraphVertex(E); cout << endl;
	graph.BFShowGraphVertex(G); cout << endl;

	return 0;
}