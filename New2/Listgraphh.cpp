#include "stdafx.h"
#include "ListGraph.h"
#include <vector>
#include <iostream>
using namespace std;

CListGraph::CListGraph(int _verticesCount)
	: graph(_verticesCount)
{
}

void CListGraph::AddEdge(int from, int to)
{
	graph[from].push_back(to);
}

int CListGraph::VerticesCount() const
{
	return graph.size();
}

void CListGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const
{
	vertices = graph[vertex];
}
void CListGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const
{
	for (int i = 0; i < graph.size(); i++) {
		for (int j: graph[i]) {
			if (j == vertex) {
				vertices.push_back(i);
			}
		}
	}
	//все входящие в эту вершину
	//vertices = graph[vertex];
}
