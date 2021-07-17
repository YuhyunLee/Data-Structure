#include "ALGraphKruscal.h"
#include <iostream>

int main(void)
{
	ALGraph graph(6);

	graph.AddEdge(A, B, 9);
	graph.AddEdge(B, C, 2);
	graph.AddEdge(A, C, 12);
	graph.AddEdge(A, D, 8);
	graph.AddEdge(D, C, 6);
	graph.AddEdge(A, F, 11);
	graph.AddEdge(F, D, 4);
	graph.AddEdge(D, E, 3);
	graph.AddEdge(E, C, 7);
	graph.AddEdge(F, E, 13);

	graph.ConKruskalMST();		// MST·Î º¯È¯
	graph.ShowGraphEdgeInfo();
	graph.ShowGraphEdgeWeightInfo();

	return 0;
}