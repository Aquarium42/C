#pragma once

#include <vector>
#include "Graph.h"
class CListGraph : public IGraph {
public:
	CListGraph(int _verticesCount);
	void AddEdge(int from, int to) override;
	int VerticesCount() const override;
	void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
	void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
private:
	std::vector< std::vector<int> > graph;
};

