#include "stdafx.h"
#include "ArcGraph.h"
#include <vector>
#include<memory>
#include <iostream>
using namespace std;

CArcGraph::CArcGraph(int vertex_count)
	: graph()
{
	count = vertex_count;
}
CArcGraph::CArcGraph(const IGraph* obj)
	: CArcGraph(obj->VerticesCount())
{
	for (int i = 0; i < obj->VerticesCount(); i++) {
		vector <int> next;
		obj->GetNextVertices(i, next);
	}

}

void CArcGraph::AddEdge(int from, int to)
{
	std::vector< int > pair;
	pair.push_back(from);
	pair.push_back(to);
	graph.push_back(pair);
}

int CArcGraph::VerticesCount() const
{
	return count;
}

void CArcGraph::GetNextVertices(int vertex, std::vector<int>& vertices_) const
{
	for (int i = 0; i < graph.size(); i++) {
		if (graph[i][0] == vertex) {
			vertices_.push_back(graph[i][1]);
		}
	}
}
void CArcGraph::GetPrevVertices(int vertex, std::vector<int>& vertices_) const
{
	for (int i = 0; i < graph.size(); i++) {
		if (graph[i][1] == vertex) {
			vertices_.push_back(graph[i][0]);
		}
	}
	//все входящие в эту вершину
	//vertices = graph[vertex];
}
