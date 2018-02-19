#include "stdafx.h"
#include "SetHashGraph.h"
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

CHashGraph::CHashGraph(int _verticesCount)
	: graph(_verticesCount)
{
}

void CHashGraph::AddEdge(int from, int to)
{
	graph[from].insert(to);
}

int CHashGraph::VerticesCount() const
{
	return graph.size();
}

void CHashGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const
{
	for (auto i = graph[vertex].begin(); i != graph[vertex].end(); i++) {
		vertices.push_back(*i);
	}
}
void CHashGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const
{

	for (int i = 0; i < graph.size(); i++) {
		auto itFind = graph[i].find(vertex);
		if (itFind != graph[i].end()) {
			vertices.push_back(i);
		}
		
	}
	//все входящие в эту вершину
	//vertices = graph[vertex];
}
