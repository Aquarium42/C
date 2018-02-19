#pragma once

#include <vector>
#include <unordered_set>
#include "Graph.h"
class CHashGraph : public IGraph {
public:
	CHashGraph(int _verticesCount);

	void AddEdge(int from, int to) override;
	int VerticesCount() const override;
	void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
	void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
private:
	std::vector< std::unordered_set<int> > graph;
	//std::vector< std::vector<int> > graph;
};

#pragma once
