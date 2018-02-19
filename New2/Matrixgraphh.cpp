#include "stdafx.h"
#include "MatrixGraph.h"
#include <vector>
#include <iostream>
using namespace std;

CMatrixGraph::CMatrixGraph(int _verticesCount)
	: graph(_verticesCount, vector<bool>(_verticesCount, false))
{
}

void CMatrixGraph::AddEdge(int from, int to)
{
	graph[from][to ] = true;
}

int CMatrixGraph::VerticesCount() const
{
	return graph.size();
}

void CMatrixGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const
{
	for (int j = 0; j < graph[vertex].size(); j++) {
		if (graph[vertex][j] == true) {
			vertices.push_back(j);
		}
	}
}
void CMatrixGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const
{
	for (int j = 0; j < graph[vertex].size(); j++) {
		if (graph[j][vertex] == true) {
			vertices.push_back(j);
		}
	}
	
	//все входящие в эту вершину
	//vertices = graph[vertex];
}
